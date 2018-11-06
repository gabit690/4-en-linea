#ifndef PANTALLA_H_
#define PANTALLA_H_

/*
 * La 'Pantalla' se encarga de mostrar mensajes determinados por consola.
 */

class Pantalla{

    public:

        /*
         * POST: muestra por pantalla el mensaje de inicio del juego.
         */
        void ImprimirMensajeDeInicio();

        /*
         * POST: muestra por pantalla un mensaje indicando que se seleccione la dificultad.
         * 		 1: Easy, 2: Normal, 3: Hard.
         */
        void ImprimirSeleccionDeDificultad();

         /*
          * POST: muestra por pantalla un mensaje indicando que se ingrese un numero de jugadores.
          */
        void ImprimirPedidoDeJugadores();

        /*
         * POST: indica que se ha ingresado un dato invalido.
         */
        void ImprimirErrorDeInput();

        /*
         * POST: muestra por pantalla un mensaje indicando que se
         * 		 ingrese el tamanio de filas para el tablero.
         */
        void ImprimirPedidoDeFilas();

        /*
         * POST: muestra por pantalla un mensaje indicando que se
         *       ingrese el tamanio de columnas para el tablero.
         */
        void ImprimirPedidoDeColumnas();

        /*
         * POST: indica por pantalla el comienzo de un turno.
         */
        void ImprimirInicioDeTurno(unsigned int jugadorDelTurno);

        /*
         * POST: pide por pantalla que se ingrese una jugada.
         */
        void ImprimirPedidoDeJugada();

        /*
         * POST: indica por pantalla que la fila seleccionada esta llena.
         */
        void ImprimirColumnaLlena();

        /*
         * PRE: recibe por parametro un objeto el numero del Jugador ganador.
         * POST: muestra por pantalla un mensaje indicando que hubo un ganador.
         */
        void ImprimirGanador(unsigned int jugadorDelTurno);

        /*
         * POST: muestra por pantalla un mensaje indicando que el juego termina en empate.
         */
        void ImprimirJuegoEmpatado();

        /*
         * POST: muestra por pantalla un mensaje indicando que el juego termina debido a que
         * 		 los jugadores se quedaron sin fichas.
         */
        void ImprimirJugadoresSinFichas();

        /*
         * POST: muestra por pantalla un mensaje indicando que el juego termina porque se
         * 	     lleno el tablero.
         */
        void ImprimirTableroLleno();

        /*
         * POST: muestra por pantalla que ha concluido el juego.
         */
        void ImprimirFinDelJuego();

        /*
         * POST: muestra por pantalla un mensaje que consulta si se quiere
         * 		 jugar otra vez.
         */
        void ImprimirSeguirJugando();

};

#endif /* PANTALLA_H_ */
