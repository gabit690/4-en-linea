#ifndef JUGADOR_H_
#define JUGADOR_H_

#include "Color.h"

/*
 * Un 'Jugador' es un miembro de un juego que propone las
 * jugadas a realizar durante la partida.
 * Cuenta con una identificacion propia, un color determinado y la cantidad
 * de fichas total que puede jugar durante una partida.
 */

class Jugador {

	private:
		unsigned int codigo;
		unsigned int fichas;
		Color* color;

	public:

		/* PRE: rojo, verde y azul son enteros entre 0 y 255. identificacion >0.
		 * POST: crea un jugador con su color asociado en la escala RGB.
		 */
		Jugador(unsigned int identificacion, unsigned int cantidadDeFichas,
				unsigned char rojo, unsigned char verde, unsigned char azul);


		/* PRE: el jugador tiene al menos una ficha para jugar.
		 * POST: reduce la cantidad de fichas que tiene el jugador en 1.
		 */
		void jugarUnaFicha();

		/*
		 * POST: devuelve el numero que identifica al jugador en el juego.
		 */
		unsigned int obtenerIdentificacion();

		/*
		 * POST: devuelve la cantidad de fichas para ser jugadas que tiene el jugador.
		 */
		unsigned int obtenerCantidadDeFichas();

		/* POST: devuelve los colores del jugador*/
		Color* obtenerColor();

		/*
		 * POST: elimina todos los recursos utilizados.
		 */
		~Jugador();
};

#endif /* JUGADOR_H_ */
