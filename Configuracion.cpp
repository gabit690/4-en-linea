#include "Configuracion.h"

Configuracion::Configuracion(){

	cantidadDeColumnas = 0;
	cantidadDeFilas = 0;
	cantidadDeJugadores = 0;
	dificultad = new Dificultad;

}


void Configuracion::asignarCantidadDeColumnas(unsigned int cantidadDeColumnas){

	this->cantidadDeColumnas = cantidadDeColumnas;
}

void Configuracion::asignarCantidadDeFilas(unsigned int cantidadDeFilas){

	this->cantidadDeFilas = cantidadDeFilas;
}

void Configuracion::asignarCantidadDeJugadores(unsigned int cantidadDeJugadores){

	this->cantidadDeJugadores = cantidadDeJugadores;
}

Dificultad* Configuracion::obtenerDificultad(){

	return this->dificultad;
}


unsigned int Configuracion::obtenerCantidadDeColumnas(){

	return this->cantidadDeColumnas;
}

unsigned int Configuracion::obtenerCantidadDeFilas(){

	return this->cantidadDeFilas;
}


unsigned int Configuracion::obtenerCantidadDeJugadores(){

	return this->cantidadDeJugadores;
}

bool Configuracion::existePosicion(unsigned int fila, unsigned int columna){
	bool filaValida = ((0 < fila) && (fila <= this->cantidadDeFilas));
	bool columnaValida = ((0 < columna) && (columna <= this->cantidadDeColumnas));
	return (filaValida && columnaValida);
}

Configuracion:: ~Configuracion(){
	delete this->dificultad;
}
