#ifndef FICHASENJUEGO_H_
#define FICHASENJUEGO_H_

#include "Lista.h"
#include "Jugador.h"
#include "Ficha.h"

/*
 * 'FichasEnJuego' contiene a todas las fichas que se encuentran en el tablero
 * de juego durante la partida.
 */

class FichasEnJuego{

	private:
		Lista<Ficha*>* listaDeFichasVivas;

	public:

		/*
		 * POST: crea una lista que contendra las fichas que esten vivas en la partida.
		 */
		FichasEnJuego();

		/* PRE: 'unJugador' tiene que ser un jugador valido y posicionColumna mayor a 0.
		 * POST: crea una ficha correspodiente al jugador 'unJugador', la agrega a la lista
		 * de fichas vivas y devuelve un puntero hacia la ficha creada.
		 */
		Ficha* crearFicha(Jugador* unJugador, unsigned int posicionColumna,
						  unsigned int alteracionRivales,
						  unsigned int alteracionCompanieras);

		/* PRE: 'unaFicha' es una ficha valida dentro de la lista.
		 * POST: quita de la lista de fichas vivas a 'unaFicha'.
		 */
		void quitarFicha(Ficha* unaFicha);

		/*
		 * POST: libera la memoria pedida para la lista de fichas vivas.
		 */
		void reiniciarFichas();

		/* POST: libera los recursos utilizados.
		 */
		~FichasEnJuego();

	private:


		/*
		 * POST: libera la memoria pedida para las fichas de la partida.
		 */
		void liberarFichas();
};

#endif /* FICHASENJUEGO_H_ */
