#include "Columna.h"

Columna::Columna(unsigned int alturaMaxima) {

	this->alturaMaxima = alturaMaxima;
	this->columna = new Lista<Ficha*>;
}

void Columna::agregar(Ficha* nuevaFicha){

	this->columna->agregar(nuevaFicha);
	nuevaFicha->obtenerPosicion()->asignarNumeroDeFila(this->columna->contarElementos());
}

void Columna::remover(unsigned int posicion){

	this->columna->remover(posicion);
}

Ficha* Columna::obtenerFicha(unsigned int posicion){

	return this->columna->obtener(posicion);
}

bool Columna::estaVacia(){

	return this->columna->estaVacia();
}

bool Columna::estaLlena(){

	return (this->columna->contarElementos() == this->alturaMaxima);
}

unsigned int Columna::contarFichas(){

	return this->columna->contarElementos();
}

Lista<Ficha*>* Columna::obtenerFichas(){

	return this->columna;
}

Columna::~Columna() {

	delete this->columna;
}

