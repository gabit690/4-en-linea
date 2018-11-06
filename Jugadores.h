#ifndef JUGADORES_H_
#define JUGADORES_H_

#include "Lista.h"
#include "Jugador.h"
#include "Color.h"

/*
 * 'Jugadores' contien la lista de los jugadores que participan en una partida de juego
 * y controla la cantidad de fichas que se pueden jugar en toda la partida.
 */

class Jugadores {
	private:

		Lista<Jugador*>* jugadores;
		unsigned int totalFichasJugables;

	public:

		/* POST: crea una lista de jugadores vacia con 0 fichas jugables */
		Jugadores();

		/* POST: agrega un jugador a la lista */
		void agregar(Jugador* nuevoJugador);

		/* PRE: 'cantidadDeFicha' es mayor a cero.
		 * POST: asigna la cantidad de fichas disponibles para jugar una partida completa.
		 */
		void establecerCantidadDeFichasJugables(unsigned int cantidadDeJugadores, unsigned int cantidadDeFichas);

		/* PRE: los Jugadores deben tener fichas.
		 * POST: disminuye en 1 la cantidad de fichas que podran jugarse en la partida.
		 */
		void seJugoUnaFicha();

		/*
		 * POST: devuelve true si los jugadores de la lista tienen fichas para jugar.
		 */
		bool losJugadoresTienenFichas();

		/*
		 * POST: devuelve la lista de jugadores de la partida actual.
		 */
		Lista<Jugador*>* obtenerListadoDeJugadores();


		/*
		 * POST: libera la memoria pedida para la lista de jugadores.
		 */
		void reiniciarJugadores();

		/* POST: libera los recursos utilizados*/
		~Jugadores();

		/* POST: crea 'cantidadDeJugadores' de jugadores, cada uno con un color
		 * 		 unico e inicialmente con 'cantidadDeFichas' de fichas.
		 */
		void agregar(unsigned int cantidadDeJugadores, unsigned int cantidadDeFichas);


	private:

		/*
		 * POST: libera la memoria pedida para los jugadores de la partida.
		 */
		void liberarJugadores();

		/* POST: asigna a 'color' un color unico dentro de los jugadores existentes.
		 */
		void asignarColorUnico(Color* color);

		/* POST: indica si el color ingresado no lo tiene ninguno de los jugadores.
		 */
		bool esColorUnico(Color* color);
};

#endif /* JUGADORES_H_ */
