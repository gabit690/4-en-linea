#include "Dificultad.h"

Dificultad::Dificultad(){

	alteracionEnergeticaCompanieras = 10;
	alteracionEnergeticaRivales = 12;

}


void Dificultad::cambiarAMedio(){

	alteracionEnergeticaCompanieras = 10;
	alteracionEnergeticaRivales = 12;

}

void Dificultad::cambiarAFacil(){

	alteracionEnergeticaCompanieras = 20;
	alteracionEnergeticaRivales = 6;

}

void Dificultad::cambiarADificil(){

	alteracionEnergeticaCompanieras = 5;
	alteracionEnergeticaRivales = 24;

}

unsigned int Dificultad::obtenerAlteracionEnergeticaACompanierasVecinas(){

	return this->alteracionEnergeticaCompanieras;

}

unsigned int Dificultad::obtenerAlteracionEnergeticaARivalesVecinas(){

	return this->alteracionEnergeticaRivales;

}
