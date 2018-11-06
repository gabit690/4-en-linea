#ifndef DIFICULTAD_H_
#define DIFICULTAD_H_

class Dificultad {

	private:

		unsigned int alteracionEnergeticaCompanieras;
		unsigned int alteracionEnergeticaRivales;
		
	public:

		/* POST: crea una dificultad de nivel Normal por default.
		 */
		Dificultad();

		/* POST: cambia el nivel de dificultad a facil */
		void cambiarAFacil();

		/* POST: cambia el nivel de dificultad a medio
		 *
		 */
		void cambiarAMedio();

		/* POST: cambia el nuvel de dificultad a dificil
		 *
		 */
		void cambiarADificil();

		/* POST: devuelve la cantidad inicial de alteracion energetica
		 * 		 que genera una ficha sobre sus companieras vecinas.
		 */
		unsigned int obtenerAlteracionEnergeticaACompanierasVecinas();

		/* POST: devuelve la cantidad inicial de alteracion energetica que
		 * 		 genera una ficha sobre sus rivales vecinas.
		 */
		unsigned int obtenerAlteracionEnergeticaARivalesVecinas();

};

#endif /* DIFICULTAD_H_ */
