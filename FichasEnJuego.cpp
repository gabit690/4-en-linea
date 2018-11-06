#include "FichasEnJuego.h"

FichasEnJuego::FichasEnJuego(){
		this->listaDeFichasVivas = new Lista<Ficha*>;
}

Ficha* FichasEnJuego::crearFicha(Jugador* unJugador,unsigned int posicionColumna,
		                         unsigned int alteracionRivales,
								 unsigned int alteracionCompanieras){

	Ficha* nuevaFicha = new Ficha(unJugador, posicionColumna,
			                      alteracionRivales, alteracionCompanieras);
	this->listaDeFichasVivas->agregar(nuevaFicha);
	return nuevaFicha;
}

void FichasEnJuego::quitarFicha(Ficha* unaFicha){
	unsigned int posicionEnLista = this->listaDeFichasVivas->buscarPosicionDelElemento(unaFicha);
	Ficha* removerFicha;
	removerFicha = this->listaDeFichasVivas->obtener(posicionEnLista);
	this->listaDeFichasVivas->remover(posicionEnLista);
	delete removerFicha;
}

FichasEnJuego::~FichasEnJuego(){
	this->liberarFichas();
	delete this->listaDeFichasVivas;
}

void FichasEnJuego::reiniciarFichas(){
	this->liberarFichas();
}

void FichasEnJuego::liberarFichas(){
	while(! this->listaDeFichasVivas->estaVacia()){
		Ficha* removerFicha;
		removerFicha = this->listaDeFichasVivas->obtener(1);
		this->listaDeFichasVivas->remover(1);
		delete removerFicha;
	}
}
