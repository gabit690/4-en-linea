#include "Jugadores.h"

Jugadores::Jugadores(){
	this->jugadores = new Lista<Jugador*>;
	this->totalFichasJugables = 0;
}

void Jugadores::agregar(Jugador* nuevoJugador){

	this->jugadores->agregar(nuevoJugador);
}

void Jugadores::establecerCantidadDeFichasJugables(unsigned int cantidadDeJugadores, unsigned int cantidadDeFichas){
	this->totalFichasJugables = (cantidadDeJugadores*cantidadDeFichas);
}

void Jugadores::seJugoUnaFicha(){
	if(this->totalFichasJugables > 0){
		this->totalFichasJugables--;
	}
}

bool Jugadores::losJugadoresTienenFichas(){
	return (this->totalFichasJugables > 0);
}

Lista<Jugador*>* Jugadores::obtenerListadoDeJugadores(){
	return this->jugadores;
}

Jugadores::~Jugadores() {
	this->liberarJugadores();
	delete this->jugadores;
}

void Jugadores::reiniciarJugadores(){
	this->liberarJugadores();
}


void Jugadores::agregar(unsigned int cantidadDeJugadores,
						unsigned int cantidadDeFichas){

	for (unsigned int i = 1; i <= cantidadDeJugadores; i++){

		Color* nuevoColor = new Color(0, 0, 0);
		this->asignarColorUnico(nuevoColor);
		Jugador* nuevoJugador = new Jugador(i, cantidadDeFichas,
								nuevoColor->obtenerRojo(),
								nuevoColor->obtenerVerde(),
								nuevoColor->obtenerAzul());
		this->jugadores->agregar(nuevoJugador);
		delete nuevoColor;
	}
}


void Jugadores::asignarColorUnico(Color* color){

	color->asignarColorAleatorio();
	while (! this->esColorUnico(color)){
		color->asignarColorAleatorio();
	}
}

bool Jugadores::esColorUnico(Color* nuevoColor){

	bool esUnico = true;
	Color* unColor;

	if (!this->jugadores->estaVacia()){

		this->jugadores->iniciarCursor();
		while( this->jugadores->avanzarCursor() && esUnico){

			unColor = this->jugadores->obtenerCursor()->obtenerColor();

			if (unColor->obtenerRojo() == nuevoColor->obtenerRojo() &&
				unColor->obtenerVerde() == nuevoColor->obtenerVerde() &&
				unColor->obtenerAzul() == nuevoColor->obtenerAzul()){

				esUnico = false;
			}
		}
	}

	return esUnico;
}


void Jugadores::liberarJugadores(){

	unsigned int primero = 1;
	while(! this->jugadores->estaVacia()){
			Jugador* jugadorAremover;
			jugadorAremover = this->jugadores->obtener(primero);
			this->jugadores->remover(primero);
			delete jugadorAremover;
		}
}
