#include "CuatroEnLinea.h"
#include <iostream>
using namespace std;

CuatroEnLinea::CuatroEnLinea(){

	this->tableroDeJuego = 0;
	this->dibujante = 0;
	this->arbitro = 0;

	this->pantallaDeJuego = new Pantalla();
	this->jugadores = new Jugadores();
	this->fichasVivas = new FichasEnJuego();
	this->fuente = new FuenteEnergetica();
	this->receptor = new Receptor();
	this->configuracion = new Configuracion();
}

void CuatroEnLinea::iniciarJuego(){

	this->pantallaDeJuego->ImprimirMensajeDeInicio();
}

void CuatroEnLinea::setearPartida(){

	unsigned int eleccionJugadores = elegirNumeroDeJugadores();
	this->configuracion->asignarCantidadDeJugadores(eleccionJugadores);

	unsigned int eleccionFila = elegirNumeroDeFilas();
	this->configuracion->asignarCantidadDeFilas(eleccionFila);

	unsigned int eleccionColumna = elegirNumeroDeColumna();
	this->configuracion->asignarCantidadDeColumnas(eleccionColumna);

	// crear tablero
	Tablero* elTablero = new Tablero(eleccionFila, eleccionColumna);
	this->tableroDeJuego = elTablero;

	// crear Dibujante
	Dibujante* elDibujante = new Dibujante(elTablero, 480, 640);
	this->dibujante = elDibujante;

	//asignacion de lista a la fuente
	this->fuente->asignarListaDeFichas(this->fichasVivas);


	unsigned int cantidadDeFichas = (eleccionFila*eleccionColumna);
	this->jugadores->agregar(eleccionJugadores, cantidadDeFichas);
	this->jugadores->establecerCantidadDeFichasJugables(eleccionJugadores, cantidadDeFichas);

	unsigned int eleccionDificultad = elegirDificultad();
	switch(eleccionDificultad){
		case 1: this->configuracion->obtenerDificultad()->cambiarAFacil();
				break;
		case 2: this->configuracion->obtenerDificultad()->cambiarAMedio();
				break;
		case 3: this->configuracion->obtenerDificultad()->cambiarADificil();
				break;
	}

	//crear aribitro
	Arbitro* elArbitro = new Arbitro(elTablero, 4, this->jugadores);
	this->arbitro = elArbitro;
}


void CuatroEnLinea::jugarPartida(){

	while(this->arbitro->seguirJugando()){
		this->fuente->cargarFichasAlInicioDeTurno();
		efectuarTurnosDeLosJugadores();
		if(this->arbitro->seguirJugando()){
			this->fuente->mapearEnergias(this->tableroDeJuego, this->arbitro);
			if(! this->arbitro->hayGanador()){
				this->fuente->reducirAlteraciones();
			}
		}
	}
}

void CuatroEnLinea::efectuarTurnosDeLosJugadores(){

	this->jugadores->obtenerListadoDeJugadores()->iniciarCursor();
	while(this->jugadores->obtenerListadoDeJugadores()->avanzarCursor() &&
		  this->arbitro->seguirJugando()){

		this->dibujante->dibujarTablero();
		Jugador* jugadorDuenioDelTurno;
		jugadorDuenioDelTurno = this->jugadores->obtenerListadoDeJugadores()->obtenerCursor();
		this->pantallaDeJuego->ImprimirInicioDeTurno(jugadorDuenioDelTurno->obtenerIdentificacion());
		unsigned int columnaElegida = elegirColumnaParaJugada();
		unsigned int alteracionRivales = this->configuracion->obtenerDificultad()->obtenerAlteracionEnergeticaARivalesVecinas();
		unsigned int alteracionCompanieras = this->configuracion->obtenerDificultad()->obtenerAlteracionEnergeticaACompanierasVecinas();
		Ficha* fichaJugada;
		fichaJugada = this->fichasVivas->crearFicha(jugadorDuenioDelTurno, columnaElegida, alteracionRivales, alteracionCompanieras);
		jugadorDuenioDelTurno->jugarUnaFicha();
		this->tableroDeJuego->agregar(fichaJugada);

		if(! this->arbitro->unaJugadaGanadora(fichaJugada)){

			this->fuente->agregarNuevoRegistro(fichaJugada);
		}
	}
}

unsigned int CuatroEnLinea::elegirColumnaParaJugada(){
	bool eleccionValida = false;
	bool columnaAceptaJugada = false;
	unsigned int eleccion;
	while((! eleccionValida) || (! columnaAceptaJugada)){
		this->pantallaDeJuego->ImprimirPedidoDeJugada();
		std::cin >> eleccion;
		eleccionValida = this->receptor->esUnaColumnaDelTablero(eleccion, this->configuracion->obtenerCantidadDeColumnas());
		if(!eleccionValida){
			this->pantallaDeJuego->ImprimirErrorDeInput();
		}
		else{
			columnaAceptaJugada = (this->tableroDeJuego->contarFichas(eleccion)<this->configuracion->obtenerCantidadDeFilas());
			if(!columnaAceptaJugada){
				this->pantallaDeJuego->ImprimirColumnaLlena();
			}
		}
	}
	return eleccion;
}

bool CuatroEnLinea::finalizarJuego(){
	bool terminar = true;
	this->dibujante->dibujarTablero();
	if(this->arbitro->hayGanador()){
		this->pantallaDeJuego->ImprimirGanador(this->arbitro->ganadorDelJuego()->obtenerIdentificacion());
	}
	else{
		if(this->arbitro->seLlenoElTablero()){
			this->pantallaDeJuego->ImprimirJuegoEmpatado();
		}
		else{
			this->pantallaDeJuego->ImprimirJugadoresSinFichas();
		}
	}
	terminar = dejarDeJugar();
	return terminar;
}

bool CuatroEnLinea::dejarDeJugar(){
	bool eleccionValida = false;
	unsigned int eleccion;
	bool finalizar = true;
	while(! eleccionValida){
		this->pantallaDeJuego->ImprimirSeguirJugando();
		std::cin >> eleccion;
		eleccionValida = this->receptor->respuestaSeguirJugandoValida(eleccion);
		if(! eleccionValida){
			this->pantallaDeJuego->ImprimirErrorDeInput();
		}
	}
	if(eleccion == 1){
		this->reiniciarJuego();
		finalizar = false;
	}
	return finalizar;
}

void CuatroEnLinea::reiniciarJuego(){

	delete this->tableroDeJuego;
	this->tableroDeJuego = 0;
	delete this->dibujante;
	this->dibujante = 0;
	delete this->arbitro;
	this->arbitro = 0;

	/* this->colores->reiniciarColores();*/
	this->fichasVivas->reiniciarFichas();
	this->fuente->reiniciarFuente();
	this->jugadores->reiniciarJugadores();
}

unsigned int CuatroEnLinea::elegirNumeroDeJugadores(){
	bool eleccionValida = false;
	unsigned int eleccion;
	while(!eleccionValida){
		this->pantallaDeJuego->ImprimirPedidoDeJugadores();
		std::cin >> eleccion;

		eleccionValida = this->receptor->numeroDeJugadoresValidos(eleccion);
		if(!eleccionValida){
			this->pantallaDeJuego->ImprimirErrorDeInput();
		}
	}
	return eleccion;
}

unsigned int CuatroEnLinea::elegirNumeroDeFilas(){
	bool eleccionValida = false;
	unsigned int eleccion;
	while(!eleccionValida){
		this->pantallaDeJuego->ImprimirPedidoDeFilas();
		std::cin >> eleccion;
		eleccionValida = this->receptor->dimensionParaFilasValido(eleccion);
		if(!eleccionValida){
			this->pantallaDeJuego->ImprimirErrorDeInput();
		}
	}
	return eleccion;
}

unsigned int CuatroEnLinea::elegirNumeroDeColumna(){
	bool eleccionValida = false;
	unsigned int eleccion;
	while(! eleccionValida){
		this->pantallaDeJuego->ImprimirPedidoDeColumnas();
		std::cin >> eleccion;
		eleccionValida = this->receptor->dimensionParaColumnasValida(eleccion);
		if(! eleccionValida){
			this->pantallaDeJuego->ImprimirErrorDeInput();
		}
	}
	return eleccion;
}

unsigned int CuatroEnLinea::elegirDificultad(){
	bool eleccionValida = false;
	unsigned int eleccion;
	while(!eleccionValida){
		this->pantallaDeJuego->ImprimirSeleccionDeDificultad();
		std::cin >> eleccion;
		eleccionValida = this->receptor->dificultadValida(eleccion);
		if(!eleccionValida){
			this->pantallaDeJuego->ImprimirErrorDeInput();
		}
	}
	return eleccion;
}

CuatroEnLinea::~CuatroEnLinea(){
	delete this->pantallaDeJuego ;
	delete this->tableroDeJuego ;
	delete this->dibujante;
	delete this->jugadores;
	delete this->fichasVivas;
	delete this->arbitro;
	delete this->fuente;
	delete this->receptor;
	delete this->configuracion;
}
