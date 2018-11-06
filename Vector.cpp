#include "Vector.h"

Vector::Vector(int numeroDeColumna, int numeroDeFila) {

	this->numeroDeColumna = numeroDeColumna;
	this->numeroDeFila = numeroDeFila;
}

Vector::Vector(const Vector &otroVector){

	this->numeroDeColumna = otroVector.numeroDeColumna;
	this->numeroDeFila = otroVector.numeroDeFila;
}

Vector* Vector::obtenerInverso(){
	Vector vectorInverso(
			(-1) * this->obtenerNumeroDeColumna(),
			(-1) * this->obtenerNumeroDeFila());

	Vector* inverso = &vectorInverso;
	return inverso;
}

void Vector::asignarNumeroDeColumna(int numeroDeColumna){
	this->numeroDeColumna = numeroDeColumna;
}

void Vector::asignarNumeroDeFila(int numeroDeFila){
	this->numeroDeFila = numeroDeFila;
}

unsigned int Vector::obtenerNumeroDeColumna(){
	return this->numeroDeColumna;
}

unsigned int Vector::obtenerNumeroDeFila(){
	return this->numeroDeFila;
}

Vector Vector::operator +(Vector otroVector){
	Vector suma(0, 0);
	suma.asignarNumeroDeColumna(
		this->numeroDeColumna + otroVector.numeroDeColumna
	);
	suma.asignarNumeroDeFila(
		this->numeroDeFila + otroVector.numeroDeFila
	);
	return suma;
}

Vector Vector::operator *(int escalar){
	Vector producto(1, 1);
	producto.asignarNumeroDeColumna(this->numeroDeColumna * escalar);
	producto.asignarNumeroDeFila(this->numeroDeFila * escalar);
	return producto;
}
