#include "Arbitro.h"

#include "Arbitro.h"

Arbitro::Arbitro(Tablero* tablero, unsigned int cantidadGanadora, Jugadores* listaDeJugadores) {

	this->tablero = tablero;
	this->jugadores = listaDeJugadores;
	this->cantidadGanadora = cantidadGanadora;
	this->ganador = NULL;
}


bool Arbitro::unaJugadaGanadora(Ficha* unaFicha){
	if(this->verificar(unaFicha)){
		this->ganador = unaFicha->obtenerDuenio();
	}
	return (this->ganador != NULL);
}

void Arbitro::analizarJugadaPorCaidaDeFicha(unsigned int posFila, unsigned int posColumna){
	Vector* posicionAnalizada = new Vector(posColumna, posFila);
	unsigned int cantidadDeFichasEnColumna = this->tablero->contarFichas(posColumna);
	while((posicionAnalizada->obtenerNumeroDeFila()<=cantidadDeFichasEnColumna)&&(!this->hayGanador())){
		Ficha* fichaAnalizada;
		fichaAnalizada = this->tablero->obtenerFicha(posicionAnalizada);
		if(!this->verificar(fichaAnalizada)){
			posicionAnalizada->asignarNumeroDeFila(posicionAnalizada->obtenerNumeroDeFila()+1);
		}
		else{
			this->ganador = fichaAnalizada->obtenerDuenio();
		}
	}
	delete posicionAnalizada;
}

bool Arbitro::hayGanador(){
	return (this->ganador != NULL);
}

bool Arbitro::seLlenoElTablero(){
	return (this->tablero->estaLleno());
}

bool Arbitro::jugadoresConFichas(){
	return this->jugadores->losJugadoresTienenFichas();
}

Jugador* Arbitro::ganadorDelJuego(){
	return this->ganador;
}


bool Arbitro::verificar(Ficha* ficha){

	return (
		this->verificarVertical(ficha) ||
		this->verificarHorizontal(ficha) ||
		this->verificarDiagonalPositiva(ficha) ||
		this->verificarDiagonalNegativa(ficha)
	);
}


bool Arbitro::seguirJugando(){
	bool empate = this->seLlenoElTablero();
	bool victoria = this->hayGanador();
	bool hayFichas = this->jugadoresConFichas();
	return ((! empate) && (! victoria) && (hayFichas));
}


bool Arbitro::verificarVertical(Ficha* ficha){

	Vector direccion(0, 1);
	return this->verificarEnDireccion(&direccion, ficha);
}

bool Arbitro::verificarHorizontal(Ficha* ficha){

	Vector direccion(1, 0);
	return this->verificarEnDireccion(&direccion, ficha);
}

bool Arbitro::verificarDiagonalPositiva(Ficha* ficha){

	Vector direccion(1, 1);
	return this->verificarEnDireccion(&direccion, ficha);
}

bool Arbitro::verificarDiagonalNegativa(Ficha* ficha){

	Vector direccion(1, -1);
	return this->verificarEnDireccion(&direccion, ficha);
}

bool Arbitro::verificarEnDireccion(Vector* direccion, Ficha* ficha){

	Vector* sentidoContrario = new Vector(
		(-1) * direccion->obtenerNumeroDeColumna(),
		(-1) * direccion->obtenerNumeroDeFila()
	);

	unsigned int cantidadCompanieras = (
			this->contarCompanierasAdyacentes(direccion, ficha) +
			this->contarCompanierasAdyacentes(sentidoContrario, ficha) +
			1
	);

	delete sentidoContrario;
	return cantidadCompanieras >= this->cantidadGanadora;
}

unsigned int Arbitro::contarCompanierasAdyacentes(Vector* sentido, Ficha* ficha){

	unsigned int cantidadDeCompanieras = 0;
	Vector* posicionVecina = new Vector(
		ficha->obtenerPosicion()->obtenerNumeroDeColumna() + sentido->obtenerNumeroDeColumna(),
		ficha->obtenerPosicion()->obtenerNumeroDeFila() + sentido->obtenerNumeroDeFila());


	for (
		unsigned int i = 2;

		i <= this->cantidadGanadora &&
		this->tablero->existeFichaEn(posicionVecina) &&
		(this->tablero->obtenerFicha(posicionVecina)->obtenerDuenio() ==
		ficha->obtenerDuenio());

		i++
	){
		posicionVecina->asignarNumeroDeColumna(
			ficha->obtenerPosicion()->obtenerNumeroDeColumna() +
			i * sentido->obtenerNumeroDeColumna()
		);
		posicionVecina->asignarNumeroDeFila(
			ficha->obtenerPosicion()->obtenerNumeroDeFila() +
			i * sentido->obtenerNumeroDeFila()
		);
		cantidadDeCompanieras++;
	}

	delete posicionVecina;
	return cantidadDeCompanieras;
}
