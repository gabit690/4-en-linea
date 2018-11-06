#ifndef RECEPTOR_H_
#define RECEPTOR_H_

/*
 * Un 'Receptor' es el encargado de validar la informacion ingresada
 * por el usuario.
 */

class Receptor{

	public:
		/*
		 * POST: devuelve true si eleccion esta en el intervalo [1,3].
		 */
		bool dificultadValida(unsigned int eleccion);

		/*
		 * POST: devuelve true si eleccion es mayor o igual que 2.
		 */
		bool numeroDeJugadoresValidos(unsigned int eleccion);

		/*
		 * POST: devuelve true si eleccion es mayor o igual que 1.
		 */
		bool dimensionParaFilasValido(unsigned int eleccion);

		/*
		 * POST: devuelve true si eleccion es mayor o igual que 1.
		 */
		bool dimensionParaColumnasValida(unsigned int eleccion);

		/*
		 * POST: devuelve true si eleccion es mayor o igual que 1.
		 */
		bool esUnaColumnaDelTablero(unsigned int eleccion, unsigned int tamanioDeColumnas);

		/*
		 * POST: devuelve true si eleccion es pertece al intervalo [1,2].
		 */
		bool respuestaSeguirJugandoValida(unsigned int eleccion);

};

#endif /* RECEPTOR_H_ */
