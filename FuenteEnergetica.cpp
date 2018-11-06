#include "FuenteEnergetica.h"

FuenteEnergetica::FuenteEnergetica(){
	this->listaDeRegistros = new ListaDoble<RegistroParaAlteracion*>;
	fichasExistentes = NULL;
}

void FuenteEnergetica::asignarListaDeFichas(FichasEnJuego* fichasJugadas){
	this->fichasExistentes = fichasJugadas;
}

void FuenteEnergetica::sacarFichaDelJuego(Ficha* unaFicha){
	this->fichasExistentes->quitarFicha(unaFicha);
}

void FuenteEnergetica::agregarNuevoRegistro(Ficha* unaFicha){
	RegistroParaAlteracion* nuevoRegistro = new RegistroParaAlteracion(unaFicha);
	if(this->listaDeRegistros->obtenerTamanio() > 0){
		RegistroParaAlteracion* registroAnterior;
		registroAnterior = this->listaDeRegistros->obtenerUltimoElemento();
		registroAnterior->conectarFichaPosterior(unaFicha);
		nuevoRegistro->conectarFichaAnterior(registroAnterior->obtenerFichaActual());
	}
	this->listaDeRegistros->agregar(nuevoRegistro);
}

void FuenteEnergetica::cargarFichasAlInicioDeTurno(){
	this->listaDeRegistros->iniciarCursor();
	while(this->listaDeRegistros->avanzarCursor()){
		RegistroParaAlteracion* registroObtenido;
		registroObtenido = this->listaDeRegistros->obtenerCursor();
		if(registroObtenido->obtenerFichaActual()!=0){
			registroObtenido->obtenerFichaActual()->aumentarVida(20);
		}
	}
}

void FuenteEnergetica::fichaDescargada(RegistroParaAlteracion* registro){
	Ficha* fichaAnterior;
	Ficha* fichaDescargada;
	Ficha* fichaPosterior;

	fichaAnterior = registro->obtenerFichaAnterior();
	fichaDescargada = registro->obtenerFichaActual();
	fichaPosterior = registro->obtenerFichaPosterior();

	if(fichaAnterior != NULL){
		RegistroParaAlteracion* registroAnterior;
		registroAnterior = this->listaDeRegistros->obtenerElementoAnterior();
		registroAnterior->desconectarFichaPosterior();
	}
	if(fichaPosterior != NULL){
		RegistroParaAlteracion* registroPosterior;
		registroPosterior = this->listaDeRegistros->obtenerElementoPosterior();
		registroPosterior->desconectarFichaAnterior();
	}
	registro->desconectarFichaActual();
	this->sacarFichaDelJuego(fichaDescargada);
}

void FuenteEnergetica::modificarEnergiaDeFicha(RegistroParaAlteracion* registro, Tablero* unTablero){
	unsigned int sumarEnergia = 0;
	unsigned int restarEnergia = 0;
	restarEnergia += restarPorFichaAnterior(registro);
	restarEnergia += restarPorFichaPosterior(registro);
	agregarAlteracionPorFichasVecinas(registro, unTablero, restarEnergia, sumarEnergia);
	int energiaParaModificar = (int)(sumarEnergia - restarEnergia);

	if(energiaParaModificar < 0){
		unsigned int descargarAFicha = std::abs(energiaParaModificar);
		registro->obtenerFichaActual()->disminuirVida(descargarAFicha);
	}
	else{
		unsigned int cargarAFicha = energiaParaModificar;
		registro->obtenerFichaActual()->aumentarVida(cargarAFicha);
		}
}

void FuenteEnergetica::agregarAlteracionPorFichasVecinas(RegistroParaAlteracion* registro, Tablero* unTablero, unsigned int &restarEnergia, unsigned int &sumarEnergia){
	Lista<Ficha*>* vecinas = new Lista<Ficha*>;
	unTablero->obtenerVecinas(registro->obtenerFichaActual(), vecinas);
	vecinas->iniciarCursor();
	while(vecinas->avanzarCursor()){
		Ficha* fichaVecina;
		fichaVecina = vecinas->obtenerCursor();
		if(fichaVecina->obtenerDuenio() != registro->obtenerFichaActual()->obtenerDuenio()){
			restarEnergia += fichaVecina->obtenerAlteracionRivales();
		}
		else{
			sumarEnergia += fichaVecina->obtenerAlteracionCompanieras();
		}
	}
	delete vecinas;
}

void FuenteEnergetica::mapearEnergias(Tablero* unTablero, Arbitro* elArbitro){
	this->listaDeRegistros->iniciarCursor();
	while(this->listaDeRegistros->avanzarCursor() && (! elArbitro->hayGanador())){
		RegistroParaAlteracion* registroObtenido;
		registroObtenido = this->listaDeRegistros->obtenerCursor();
		if(registroObtenido->obtenerFichaActual() != 0){
			modificarEnergiaDeFicha(registroObtenido, unTablero);
			if(registroObtenido->obtenerFichaActual()->getVida() == 0){
				hayUnafichaMuerta(registroObtenido, unTablero, elArbitro);
				fichaDescargada(registroObtenido);
			}
		}
	}
}

void FuenteEnergetica::reducirAlteraciones(){
	this->listaDeRegistros->iniciarCursor();
	while(this->listaDeRegistros->avanzarCursor()){
		RegistroParaAlteracion* registroObtenido;
		registroObtenido = this->listaDeRegistros->obtenerCursor();
		if(registroObtenido->obtenerFichaActual() != 0){
			registroObtenido->obtenerFichaActual()->reducirAlteracionNegativa();
			registroObtenido->obtenerFichaActual()->reducirAlteracionPositiva();
		}
	}
}

void FuenteEnergetica::hayUnafichaMuerta(RegistroParaAlteracion* registro, Tablero* unTablero,
										 Arbitro* elArbitro){

	unTablero->remover(registro->obtenerFichaActual());
	unsigned int fila = registro->obtenerFichaActual()->obtenerPosicion()->obtenerNumeroDeFila();
	unsigned int columna = registro->obtenerFichaActual()->obtenerPosicion()->obtenerNumeroDeColumna();
	elArbitro->analizarJugadaPorCaidaDeFicha(fila, columna);
}

FuenteEnergetica::~FuenteEnergetica(){
	this->liberarRegistros();
	delete this->listaDeRegistros;
}

void FuenteEnergetica::reiniciarFuente(){
	this->liberarRegistros();
}

void FuenteEnergetica::liberarRegistros(){
	while(!this->listaDeRegistros->estaVacia()){
			RegistroParaAlteracion* RegistroAremover;
			RegistroAremover = this->listaDeRegistros->obtenerDato(1);
			this->listaDeRegistros->sacar(1);
			delete RegistroAremover;
		}
}

unsigned int FuenteEnergetica::restarPorFichaAnterior(RegistroParaAlteracion* registro){
	unsigned int  restarPorFila = 0;
	if(registro->obtenerFichaAnterior() != NULL){
		int posicionFilaFichaActual = registro->obtenerFichaActual()->obtenerPosicion()->obtenerNumeroDeFila();
		int posicionFilaFichaAnterior = registro->obtenerFichaAnterior()->obtenerPosicion()->obtenerNumeroDeFila();

		restarPorFila = std::abs(posicionFilaFichaAnterior -
								 posicionFilaFichaActual);
	}
	return restarPorFila;
}


unsigned int FuenteEnergetica::restarPorFichaPosterior(RegistroParaAlteracion* registro){
	unsigned int  restarPorColumna = 0;
	if(registro->obtenerFichaPosterior() != NULL){
		int posicionColumnaFichaActual = registro->obtenerFichaActual()->obtenerPosicion()->obtenerNumeroDeColumna();
		int posicionColumnaFichaPosterior = registro->obtenerFichaPosterior()->obtenerPosicion()->obtenerNumeroDeColumna();

		restarPorColumna = std::abs(posicionColumnaFichaActual -
									posicionColumnaFichaPosterior);
	}
	return restarPorColumna;
}
