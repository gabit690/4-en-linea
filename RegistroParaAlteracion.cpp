#include "RegistroParaAlteracion.h"

RegistroParaAlteracion::RegistroParaAlteracion(Ficha* unaFicha){

        this->siguiente = NULL;
        this->actual = unaFicha;
        this->anterior = NULL;

}

void RegistroParaAlteracion::conectarFichaAnterior(Ficha* unaFicha){
	this->anterior = unaFicha;
}

void RegistroParaAlteracion::conectarFichaPosterior(Ficha* unaFicha){
	this->siguiente = unaFicha;
}

void RegistroParaAlteracion::desconectarFichaAnterior(){
	this->anterior = NULL;
}

void RegistroParaAlteracion::desconectarFichaActual(){
	this->actual = NULL;
}

void RegistroParaAlteracion::desconectarFichaPosterior(){
	this->siguiente = NULL;
}

Ficha* RegistroParaAlteracion::obtenerFichaAnterior(){
	return this->anterior;
}

Ficha* RegistroParaAlteracion::obtenerFichaActual(){
	return this->actual;
}

Ficha* RegistroParaAlteracion::obtenerFichaPosterior(){
	return this->siguiente;
}

