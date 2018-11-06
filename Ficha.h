#ifndef FICHA_H_
#define FICHA_H_

#include "Jugador.h"
#include "Color.h"
#include "Vector.h"

class Ficha {

	private:

		float vida;
		float vidaMaxima;
		Color* color;
		Vector* posicion;
		Jugador* duenio;
		unsigned int alteracionAcontrarias;
		unsigned int alteracionAsimilares;

	public:

		/* PRE: 'numeroDeColumna' es un numero valido de numero de columnas del
		 * 		tablero.
		 * POST: crea una ficha asociada al 'duenio' y ubicada en la columna
		 * 		'numeroDeColumna' del tablero.
		 */
		Ficha(Jugador* duenio, unsigned int numeroDeColumna, unsigned int alteracionRivales, unsigned int alteracionCompanieras);

		/*
		 * POST: devuelve la energia actual de la ficha.
		 */
		float getVida();

		/* POST: devuelve un vector indicando la posicion de la ficha */
		Vector* obtenerPosicion();

		/*
		 * POST: devuelve la cantidad de energia que modifica a las fichas rivales.
		 */
		unsigned int obtenerAlteracionRivales();

		/*
		 * POST: devuelve la cantidad de energia que modifica a las fichas companieras.
		 */
		unsigned int obtenerAlteracionCompanieras();

		/* POST: devuelve los colores de la ficha */
		Color* obtenerColor();

		/*
		 * POST: devuelve un valor de verdad respecto a la ficha si esta se encuentra al 100%
		 */
		bool energiaAlMaximo();

		/*
		 * POST: reduce la capacidad de alteracion energetica a las fichas vecinas
		 * 	     que pertenecen al mismo jugador en un -1%.
		 */
		void reducirAlteracionPositiva();

		/*
		 * POST: reduce la capacidad de alteracion energetica a las fichas vecinas
		 * 		 que pertenecen a un jugador rival en un -1%.
		 */
		void reducirAlteracionNegativa();


		/* PRE: 'porcentaje' es un real entre 0 y 100, y esta en relacion a la vida
		 * 		maxima.
		 * 		El porcentaje ingresado no puede disminuir la vida de la ficha a
		 * 		menos de 0%.
		 * POST: disminuye la vida en el porcentaje ingresado.
		 */
		void disminuirVida(float porcentaje);

		/* PRE: 'porcentaje' es un real entre 0 y 99, y esta en relacion a la vida
		 * 		maxima.
		 * 		el porcentaje de aumento de vida no puede superar el 100% de vida.
		 * POST: aumenta la vida en el porcentaje ingresado.
		 */
		void aumentarVida(float porcentaje);

		/* PRE: la posicion de la ficha tiene que ser >= 1.
		 * POST: asigna una nueva posicion de fila dentro del tablero a la
		 * 		 ficha luego de caer una posicion.
		 */
		void modificarPosicionFila();

		/* POST: devuelve el duenio de la ficha */
		Jugador* obtenerDuenio();

		/*
		 * POST: libera todos los recursos utilizados.
		 */
		~Ficha();


	private:

		/* POST: recalcula los colores de la ficha en funcion de su vida.
		 * 		 Entre menos vida tenga la ficha mas claro es su color.
		 */
		void reasignarColores();

		/* PRE: 'color' es uno de los colores del duenio.
		 * POST: devuelve la cantidad correspondiente de color segun la vida
		 * 		 de la ficha.
		 */
		ebmpBYTE recalcular(ebmpBYTE color);
};

#endif /* FICHA_H_ */
