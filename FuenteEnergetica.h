#ifndef FUENTEENERGETICA_H_
#define FUENTEENERGETICA_H_

#include "RegistroParaAlteracion.h"
#include "ListaDoble.h"
#include "Tablero.h"
#include "Arbitro.h"
#include "Jugador.h"
#include "FichasEnJuego.h"

/*
 * La 'FuenteEnergetica' se encarga de actualizar los niveles de energia
 * de las fichas que se encuentran en el tablero de juego.
 */

class FuenteEnergetica{

	private:
		ListaDoble<RegistroParaAlteracion*>* listaDeRegistros;
		FichasEnJuego* fichasExistentes;

	public:
	   /*
	    * POST: crea una fuente que se encarga de establecer los niveles de energia
	    *       de las fichas en juego. Estara asociada con las fichas que
	    *       se hayan jugado en la partida.
	  	*/
		FuenteEnergetica();

		 /*
		  * POST: Asigna a la fuente la facultad de modificar la lista de fichas que esten en juego.
		  */
		void asignarListaDeFichas(FichasEnJuego* fichasJugadas);

		 /* PRE: 'unaFicha' es una ficha valida.
		  * POST: agrega a la lista de registro uno nuevo que correspode a la ficha 'unaFicha'.
		  */
		 void agregarNuevoRegistro(Ficha* unaFicha);

		 /*
		  * POST: carga un 20% el nivel de energia que tienen las fichas que
		  * 	  todavia estan en el tablero.
		  */
		 void cargarFichasAlInicioDeTurno();

		/* PRE: 'registro' un registro valido dentro de la lista.
		 * POST: la ficha a la cual pertenece el registro se descargo y se modifica el registro
		 * 		 anterior y posterior si los hubiera.
		 */
		void fichaDescargada(RegistroParaAlteracion* registro);

		/* PRE: 'registro' un registro valido dentro de la lista cuya ficha sigue viva.
		 *      'unTablero' es el tablero del juego.
		 * POST: estable el nuevo nivel de energia con la cual la ficha termina un turno de juego
		 * 		 en base a la interaccion con otras.
		 */
		void modificarEnergiaDeFicha(RegistroParaAlteracion* registro, Tablero* unTablero);

		 /* PRE: 'unTablero' en tablero valido.
		  * POST: actualiza el nivel de energia con el cual las fichas
		  * 	  del tablero comenzaran el proximo turno.
		  * 	  Si no pudo hacerlo por completo entonces hubo una jugada ganadora.
		  */
		 void mapearEnergias(Tablero* unTablero, Arbitro* elArbitro);

		 /*
		  * POST: reduce en 1% el nivel de las alteraciones de las fichas que hay en juego.
		  */
		 void reducirAlteraciones();

		 /* PRE: registro pertenece a una ficha con energia 0.
		  * POST: modifica el tablero sacando la ficha descargada y luego se controla
		  * 	  si se sucede una jugada ganadora con el nuevo estado del tablero.
		  */
		 void hayUnafichaMuerta( RegistroParaAlteracion* registro, Tablero* unTablero,
				 	 	 	 	 Arbitro* elArbitro);

		 /*
		  * POST: Libera la memoria pedida.
		  */
		 ~FuenteEnergetica();

		/*
		 * POST: libera la memoria pedida para la lista de los registros de energia de las fichas.
		 */
		void reiniciarFuente();

	private:
		/*
		 * POST: libera la memoria pedida para los registros.
		 */
		void liberarRegistros();

		/*
		 * POST: devuelve la cantidad de alteracion que tendra que restarse
		 * 		 por fila por una ficha rival.
		 */
		unsigned int restarPorFichaAnterior(RegistroParaAlteracion* registro);

		/*
		 * POST: devuelve la cantidad de alteracion que tendra que restarse por
		 * 		 columna por una ficha rival.
		 */
		unsigned int restarPorFichaPosterior(RegistroParaAlteracion* registro);

		/* PRE: 'registro' un registro valido, 'tablero' un tablero de juego valido.
		 * POST: acumula en restarEnergia y sumarEnergia la cantidad de energia que se
		 * 		modificara a la ficha debido a la intereccion con fichas vecinas a su posicion.
		 */
		void agregarAlteracionPorFichasVecinas(RegistroParaAlteracion* registro,
				Tablero* unTablero, unsigned int &restarEnergia, unsigned int &sumarEnergia);

		/* PRE: 'unaFicha' es una ficha con vida 0.
		 * POST: quita de la lista de fichas en juego a 'unaFicha'.
		 */
		void sacarFichaDelJuego(Ficha* unaFicha);
};

#endif /* FUENTEENERGETICA_H_ */
