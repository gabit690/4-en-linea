#ifndef CUATROENLINEA_H_
#define CUATROENLINEA_H_

#include "Dibujante.h"
#include "Arbitro.h"
#include "Configuracion.h"
#include "FichasEnJuego.h"
#include "FuenteEnergetica.h"
#include "Jugadores.h"
#include "Pantalla.h"
#include "Receptor.h"
#include "Tablero.h"

/*
 * 'CuatroEnLinea' es un juego cuyo objetivo es que alguno de los jugadores de la partida
 * logre alinear 4 de sus fichas en un tablero.
 * Las fichas manejan una cantidad determinada de energia que cambia durante el juego segun
 * las interacciones que tenga con otras fichas.
 */

class CuatroEnLinea{
	private:
		Pantalla* pantallaDeJuego;
		Tablero* tableroDeJuego;
		Dibujante* dibujante;
		Jugadores* jugadores;
		FichasEnJuego* fichasVivas;
		Arbitro* arbitro;
		FuenteEnergetica* fuente;
		Receptor* receptor;
		Configuracion* configuracion;

	public:

		/*
		 * POST: crea todas las instancias necesarias para jugar '4 en linea B'.
		 * El juego se crea con la dificultad 'Normal' por defecto.
		 */
		CuatroEnLinea();

		/*
		 * POST: Se encarga de imprimir mensaje de Bienvenida y de comienzo a la partida.
		 */
		void iniciarJuego();

		/*
		 * POST: establece los parametros en los cuales se realizara una partida.
		 */
		void setearPartida();

		/*
		 * POST: se juega una partida de 4 en linea.
		 */
		void jugarPartida();

		/*
		 * POST: finaliza el juego 4 en linea.
		 */
		bool finalizarJuego();

		/*
		 * POST: libera todos los recursos de memoria pedidos.
		 */
		~CuatroEnLinea();

	private:

		/*
		 * POST: devuelve la cantidad de Jugadores elegida por el usuario.
		 */
		unsigned int elegirNumeroDeJugadores();

		/*
		 * POST: devuelve la cantidad de Filas del tablero elegida por el usuario.
		 */
		unsigned int elegirNumeroDeFilas();

		/*
		 * POST: devuelve la cantidad de Columnas del tablero elegida por el usuario.
		 */
		unsigned int elegirNumeroDeColumna();

		/*
		 * POST: devulve el valor de la dificultad elegida: 1(Easy), 2(Normal) o 3(Hard).
		 */
		unsigned int elegirDificultad();

		/*
		 * POST: devuelve el numero de Columna elegido por el participante
		 * 		 para colocar su Ficha.
		 */
		unsigned int elegirColumnaParaJugada();

		/*
		 * POST: efectua el turno de los jugadores que correspondan.
		 */
		void efectuarTurnosDeLosJugadores();

		/*
		 * POST: consulta al usuario si se quiere dejar de jugar o empezar una nueva partida.
		 * 		 En caso de que quiera Salir del juego devolvera True.
		 */
		bool dejarDeJugar();

		/*
		 * POST: reinicia el juego para poder setear una nueva partida.
		 */
		void reiniciarJuego();
};

#endif /* CUATROENLINEA_H_ */
