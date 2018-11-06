#ifndef COLUMNA_H_
#define COLUMNA_H_

#include "Lista.h"
#include "Ficha.h"

class Columna {

	private:

		unsigned int alturaMaxima;
		Lista<Ficha*>* columna;

	public:

		/* POST: crea una columna capaz de guardar hasta 'alturaMaxima' de fichas.
		 */
		Columna(unsigned int alturaMaxima);

		/* PRE: la columna no esta llena.
		 * POST: agrega la ficha ingresada sobre las demas fichas */
		void agregar(Ficha* nuevaFicha);

		/* PRE: La columna no debe estar vacia y 'posicion' debe pertenecer al
		 * 		intervalo [1, contarFichas()].
		 * POST: elimina la Ficha de la 'posicion' indicada.
		 */
		void remover(unsigned int posicion);

		/* PRE: la columna no esta vacia.
		 * 		'posicion' pertenece al intervalo [1, contarFichas()].
		 * POST: devuelve la ficha de la posicion indicada.
		 */
		Ficha* obtenerFicha(unsigned int posicion);

		/* POST: indica si la columna se encuentra sin fichas */
		bool estaVacia();

		/* POST: indica si se alcanzo la maxima cantidad de fichas posible */
		bool estaLlena();

		/* POST: devuelve la cantidad de fichas que tiene la columna */
		unsigned int contarFichas();

		/* POST: devuelve una lista con las fichas de la columna*/
		Lista<Ficha*>* obtenerFichas();

		/* POST: libera los recursos utilizados */
		virtual ~Columna();
};

#endif /* COLUMNA_H_ */
