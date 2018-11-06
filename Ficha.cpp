#include "Ficha.h"

Ficha::Ficha(Jugador* duenio, unsigned int numeroDeColumna,  unsigned int alteracionRivales, unsigned int alteracionCompanieras){

	this->duenio = duenio;
	this->vidaMaxima = 100;
	this->vida = this->vidaMaxima;
	this->alteracionAcontrarias = alteracionRivales;
	this->alteracionAsimilares = alteracionCompanieras;
	this->color = new Color(duenio->obtenerColor());
	this->posicion = new Vector(numeroDeColumna, 0);
}


float Ficha::getVida(){
    return this->vida;
}

Vector* Ficha::obtenerPosicion(){
	return this->posicion;
}

unsigned int Ficha::obtenerAlteracionRivales(){
	return this->alteracionAcontrarias;
}

unsigned int Ficha::obtenerAlteracionCompanieras(){
	return this->alteracionAsimilares;
}

Color* Ficha::obtenerColor(){
	return this->color;
}

bool Ficha::energiaAlMaximo(){
    return(this->vida == 100);
}

void Ficha::reducirAlteracionPositiva(){
	if(this->alteracionAsimilares > 0){
		this->alteracionAsimilares--;
	}
}

void Ficha::reducirAlteracionNegativa(){
	if(this->alteracionAcontrarias > 0){
		this->alteracionAcontrarias--;
	}
}

void Ficha::disminuirVida(float porcentaje){
    float nuevaEnergia = (this->vida-porcentaje);
    if(nuevaEnergia <= 0){
    	this->vida = 0;
    }
    else{
    	this->vida -= porcentaje;
    }
	this->reasignarColores();
}

void Ficha::aumentarVida(float porcentaje){
    float nuevaEnergia = (this->vida + porcentaje);
    if(nuevaEnergia >= 100){
    	this->vida = 100;
    }
    else{
    	this->vida += porcentaje;
    }
	this->reasignarColores();
}

void Ficha::reasignarColores(){
	Color* coloresOriginales =  this->duenio->obtenerColor();
	this->color->asignarRojo(this->recalcular(coloresOriginales->obtenerRojo()));
	this->color->asignarVerde(this->recalcular(coloresOriginales->obtenerVerde()));
	this->color->asignarAzul(this->recalcular(coloresOriginales->obtenerAzul()));
}


ebmpBYTE Ficha::recalcular(ebmpBYTE color){
	ebmpBYTE maximoColor = 255;
	return (color - maximoColor) * (this->vida / this->vidaMaxima) + maximoColor;
}

void Ficha::modificarPosicionFila(){
	this->posicion->asignarNumeroDeFila(this->posicion->obtenerNumeroDeFila() - 1);
}

Jugador* Ficha::obtenerDuenio(){
	return this->duenio;
}


Ficha::~Ficha(){
	delete this->color;
	delete this->posicion;
}
