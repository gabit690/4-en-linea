#ifndef REGISTROPARAALTERACION_H_
#define REGISTROPARAALTERACION_H_

/*
 * Un RegistroParaAlteracion es un registro que contiene la informacion
 * de una ficha jugada durante una partida de "4 en linea".
 * El registro tiene una referencia al registro de la ficha que fue
 * jugada anteriormente y otra al registro de la ficha que se jugo despues.
 */

#include "Ficha.h"

class RegistroParaAlteracion{
    private:

        Ficha* siguiente;
        Ficha* actual;
        Ficha* anterior;

    public:

        /*
         * PRE: 'unaFicha' tiene que ser una ficha valida.
         * POST: crea un registro con los datos que se necesitan para establecer el nuevo
         * 	     nivel de energia de la ficha al final de un turno de juego.
         */
        RegistroParaAlteracion(Ficha* unaFicha);

        /*
         * PRE: 'unaFicha' tiene que ser una ficha valida.
         * POST: establece la ficha jugada anteriomente a la actual con la cual se alterara
         * 		 por fila.
         */
        void conectarFichaAnterior(Ficha* unaFicha);

        /*
         * PRE: 'unaFicha' tiene que ser una ficha valida.
         * POST: establece la ficha jugada posteriormente a la actual con la cual se alterara
         * 		 por columna.
         */
        void conectarFichaPosterior(Ficha* unaFicha);

        /*
         * POST: la ficha que se jugo anteriormente a la actual se descargo entonces ya no
         * 		 modificara la energia de la ficha actual.
         */
        void desconectarFichaAnterior();

        /*
         * POST: la ficha a la cual pertenece el registro se quedo sin energia y se desconecta.
         */
        void desconectarFichaActual();

        /*
         * POST: la ficha que se jugo posteriormente a la actual se descargo entonces ya no
         * 	     modificara la energia de la ficha actual.
         */
        void desconectarFichaPosterior();

        /*
         * POST: devuelve un puntero a la ficha de distinto color que ingreso un turno
         * 		 antes que la actual. Si la ficha actual es la primera o su anterior
         * 		 se descargo entonces regresa un puntero a NULL.
         */
        Ficha* obtenerFichaAnterior();

        /*
         * POST: devuelve un puntero a la ficha actual dueña de la jugada.
         */
        Ficha* obtenerFichaActual();

        /*
         * POST: devuelve un puntero a la ficha de distinto color que ingreso un turno
         * 		 despues que la actual. Si la ficha actual es la ultima o su posterior
         * 		 se descargo entonces regresa un puntero a NULL.
         */
        Ficha* obtenerFichaPosterior();
};

#endif /* REGISTROPARAALTERACION_H_ */
