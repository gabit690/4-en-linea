#include "Jugador.h"

Jugador::Jugador(unsigned int identificacion, unsigned int cantidadDeFichas,
		         unsigned char rojo, unsigned char verde, unsigned char azul){

	this->codigo = identificacion;
	this->fichas = cantidadDeFichas;
	this->color = new Color(rojo, verde, azul);
}


void Jugador::jugarUnaFicha(){
	if(this->fichas == 0){
		throw std::string("No quedan fichas para realizar una jugada.");
	}
	this->fichas--;
}

unsigned int Jugador::obtenerIdentificacion(){
	return this->codigo;
}

unsigned int Jugador::obtenerCantidadDeFichas(){
	return this->fichas;
}

Color* Jugador::obtenerColor(){
	return this->color;
}

Jugador::~Jugador(){
	delete this->color;
}
