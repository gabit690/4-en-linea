#include "Pantalla.h"
#include <iostream>

using namespace std;

void Pantalla::ImprimirMensajeDeInicio(){
	cout << endl;
    cout << "!!!Bienvenidos! Se ha iniciado un nuevo Juego de 4 En Linea!!!" << endl;
    cout << endl;
}

void Pantalla::ImprimirSeleccionDeDificultad(){
	cout << endl;
    cout << " Seleccione el numero que corresponda a la dificultad:" << endl;
    cout << "1. Easy:" << endl;
    cout << "2. Normal:" << endl;
    cout << "3. Hard:" << endl;
    cout << "Su respuesta: ";
}

void Pantalla::ImprimirPedidoDeJugadores(){
	cout << endl;
    cout << "Ingresa la cantidad de jugadores que participaran: ";
}

void Pantalla::ImprimirErrorDeInput(){
	cout << endl;
    cout << "Los datos ingresados son invalidos." << endl;
}


void Pantalla::ImprimirPedidoDeFilas(){
	cout << endl;
	cout << "Ingresa la cantidad de Filas del tablero: ";

}

void Pantalla::ImprimirPedidoDeColumnas(){
	cout << endl;
	cout << "Ingresa la cantidad de Columnas del tablero: ";
}

void Pantalla::ImprimirInicioDeTurno(unsigned int jugadorDelTurno){
	cout << endl;
    cout << "Es el turno del jugador "<< jugadorDelTurno;
}

void Pantalla::ImprimirPedidoDeJugada(){
	cout << endl;
    cout << "Elige una columna donde ingresaras tu ficha: ";
}

void Pantalla::ImprimirColumnaLlena(){
	cout << endl;
    cout << "!!!La columna esta llena...!!!" << endl;
}

void Pantalla::ImprimirGanador(unsigned int ganador){
	cout << endl;
    cout << "EL GANADOR ES EL JUGADOR NUMERO " << ganador << endl;
    cout << endl;
}

void Pantalla::ImprimirJuegoEmpatado(){
	cout << endl;
	cout << "!!! El juego termina en empate !!!" << endl;
    cout << endl;
}

void Pantalla::ImprimirJugadoresSinFichas(){
	cout << endl;
	cout << "!!! Los jugadores no tienen mas fichas !!!" << endl;
    cout << endl;
}

void Pantalla::ImprimirTableroLleno(){
	cout << endl;
	cout << "!!! Se lleno el tablero !!!" << endl;
    cout << endl;
}

void Pantalla::ImprimirFinDelJuego(){
	cout << endl;
	cout << "Ha terminado el juego..." << endl;
    cout << endl;
}

void Pantalla::ImprimirSeguirJugando(){
	cout << endl;
	cout << ">>> Quiere seguir jugando 4 en linea B????" << endl;
    cout << "1. Si." << endl;
    cout << "2. No." << endl;
    cout << "Su respuesta: ";
}
