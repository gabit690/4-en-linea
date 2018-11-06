#ifndef CONFIGURACION_H_
#define CONFIGURACION_H_

#include "Dificultad.h"

class Configuracion {

	private:

		unsigned int cantidadDeColumnas;
		unsigned int cantidadDeFilas;
		unsigned int cantidadDeJugadores;
		Dificultad* dificultad;

	public:

		/*
		 * POST: genera una configuracion con sus campos nulos.
		 */
		Configuracion();

		/*
		 * POST: asigna el cantidadDeColumnas del tablero.
		 */
		void asignarCantidadDeColumnas(unsigned int cantidadDeColumnas);

		/*
		 * POST: asigna el cantidadDeFilas del tablero.
		 */
		void asignarCantidadDeFilas(unsigned int cantidadDeFilas);

		/*
		 * PRE: 'cantidadDeJugadores' es mayor a cero.
		 * POST: asigna la cantida de jugadores
		 */
		void asignarCantidadDeJugadores(unsigned int cantidadDeJugadores);

		/*
		 * POST: devuelve la dificultad elegida.
		 */
		Dificultad* obtenerDificultad();

		/*
		 * POST: devuelve el cantidadDeColumnas asignado al tablero.
		 */
		unsigned int obtenerCantidadDeColumnas();

		/*
		 * POST: devuelve el cantidadDeFilas asignado al tablero.
		 */
		unsigned int obtenerCantidadDeFilas();

		/*
		 * POST: devuelve la cantidad de jugadores asignada.
		 */
		unsigned int obtenerCantidadDeJugadores();

		/*
		 * POST: determina si la posicion fila y columna existen.
		 */
		bool existePosicion(unsigned int fila, unsigned int columna);

		/*
		 * POST: libera los recursos de memoria pedidos.
		 */
		~Configuracion();

};

#endif /* CONFIGURACION_H_ */
