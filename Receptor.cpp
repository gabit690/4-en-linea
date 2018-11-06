#include "Receptor.h"

	bool Receptor::dificultadValida(unsigned int eleccion){
		return ((eleccion >= 1) && (eleccion <= 3));
	}

	bool Receptor::numeroDeJugadoresValidos(unsigned int eleccion){
		return (eleccion >= 2);
	}

	bool Receptor::dimensionParaFilasValido(unsigned int eleccion){
		return (eleccion >= 1);
	}

	bool Receptor::dimensionParaColumnasValida(unsigned int eleccion){
		return (eleccion >= 1);
	}

	bool Receptor::esUnaColumnaDelTablero(unsigned int eleccion, unsigned int tamanioDeColumnas){
		return ((0 < eleccion) && (eleccion <= tamanioDeColumnas));
	}

	bool Receptor::respuestaSeguirJugandoValida(unsigned int eleccion){
		return ((eleccion > 0) && (eleccion <= 2));
	}
