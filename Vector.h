#ifndef VECTOR_H_
#define VECTOR_H_

class Vector {

	private:
		int numeroDeColumna;
		int numeroDeFila;

	public:

		/* POST: crea un vector un de parametros ('numeroDeColumna', 'numeroDeFila')*/
		Vector(int numeroDeColumna, int numeroDeFila);

		/* POST: crea un vector copiando los parametros de 'otroVector'. */
		Vector(const Vector &otroVector);

		/* POST: devuelve una copia del vector con sus parametros multiplicados
		 * 		 por menos uno.
		 */
		Vector* obtenerInverso();

		/* POST: asigna el numero de columna al vector */
		void asignarNumeroDeColumna(int numeroDeColumna);

		/* POST: asigna el numero de fila al vector */
		void asignarNumeroDeFila(int numeroDeFila);

		/* POST: devuelve el numero de columna del vector */
		unsigned int obtenerNumeroDeColumna();

		/* POST: devuelve el numero de fila del vector */
		unsigned int obtenerNumeroDeFila();

		/* POST: devuelve la suma de dos vector */
		Vector operator + (Vector otroVector);

		/* POST: devuelve el producto del vector por un escalar */
		Vector operator * (int escalar);
};

#endif /* VECTOR_H_ */
