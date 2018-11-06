#ifndef ARBITRO_H_
#define ARBITRO_H_

#include "Tablero.h"
#include "Ficha.h"
#include "Jugador.h"
#include "Jugadores.h"

/*
 * 'Arbitro' es el encargado de verificar que las condiciones
 * para jugar una partida se cumplan y determinar el resultado
 * de la partida jugada.
 */

class Arbitro {

	private:

		unsigned int cantidadGanadora;
		Tablero* tablero;
		Jugadores* jugadores;
		Jugador* ganador;

	public:

		/* POST: crea un arbitro que verifica que se encuentren 'cantidadGanadora'
		 * 		 en linea en las fichas del tablero.
		 */
		Arbitro(Tablero* tablero, unsigned int cantidadGanadora, Jugadores* listaDeJugadores);


		/* PRE: 'unaFicha' es una ficha jugada valida.
		 * POST: verifica si la ficha realiza cuatro en linea.
		 */
		bool unaJugadaGanadora(Ficha* unaFicha);

		/* PRE: posFila y posColumna es una posicion dentro del tablero.
		 * POST: Analiza desde la posicion de la ficha que se quedo sin energia,
		 * 		 si alguna de las que cayeron provoca 4 en linea.
		 */
		void analizarJugadaPorCaidaDeFicha(unsigned int posFila, unsigned int posColumna);

		/*
		 * POST: devuelve true si el arbitro registro una jugada ganadora.
		 */
		bool hayGanador();

		/*
		 * POST: devuelve true si el arbitro registro que se lleno el tablero.
		 */
		bool seLlenoElTablero();

		/*
		 * POST: devuelve true si el arbitro registro que los jugadores no tienen fichas para jugar.
		 */
		bool jugadoresConFichas();

		/*
		 * POST: devuelve el ganador del juego. Si no lo hubo devuelve NULL.
		 */
		Jugador* ganadorDelJuego();


		/*
		 * POST: indica si se encontro 'cantidadGanadora' alrededor de la ficha
		 * 		 indicada.
		 */
		bool verificar(Ficha* ficha);

		/*
		 * POST: devuelve verdader si se puede seguir jugando. Es decir, que no hubo ninguno de los
		 * 		 casos que provoca el final del Juego.
		 */
		bool seguirJugando();


	private:


		/* POST: indica si se encontro 'cantidadGanadora' verticalmente.
		 */
		bool verificarVertical(Ficha* ficha);

		/* POST: indica si se encontro 'cantidadGanadora' horizontalmente. */
		bool verificarHorizontal(Ficha* ficha);

		/* POST: indica si se encontro 'cantidadGanadora' sobre la diagonal
		 * 		 de pendiente positiva.
		 */
		bool verificarDiagonalPositiva(Ficha* ficha);

		/* POST: indica si se encontro 'cantidadGanadora' sobre la diagonal
		 * 		 de pendiente negativa.
		 */
		bool verificarDiagonalNegativa(Ficha* ficha);

		/* POSR: indica si se encontro 'cantidadGanadora' sobre la direccion dada
		 * 		 por el vector tanto en su sentido positivo como negativo.
		 */
		bool verificarEnDireccion(Vector* direccion, Ficha* ficha);

		/* POST: devuelve la cantidad de companieras adyacentes a la ficha en
		 * 		 el sentido dado dentro de 'cantidadGanadora' fichas y sin
		 * 		 salirse del tablero.
		 */
		unsigned int contarCompanierasAdyacentes(Vector* sentido, Ficha* ficha);

	};

#endif /* ARBITRO_H_ */
