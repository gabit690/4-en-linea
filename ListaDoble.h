#ifndef LISTADOBLE_H_
#define LISTADOBLE_H_

#include "NodoDoble.h"
#include <string>

/*
 * Una 'ListaDoble' es una coleccion dinamica de elementos posicionados
 * de manera secuencial.
 * La listaDoble tiene acceso al elemento anterior y/o posterior de la lista.
 */

template <typename T> class ListaDoble{

	private:
		unsigned int tamanio;
		NodoDoble<T>* primero;
		NodoDoble<T>* ultimo;
		NodoDoble<T>* cursor;

	public:
		/*
		 * POST: crea una ListaDoble sin elementos lista para usar.
		 */
		ListaDoble(){
			this->tamanio = 0;
			this->primero = NULL;
			this->ultimo = NULL;
			this->cursor = NULL;
		}

		/*
		 * POST: indica si la lista se encuentra vacia.
		 */
		bool estaVacia(){
			return (this->primero == NULL);
		}

		/* POST: prepara el cursor de la lista para realiza un recorrido de sus elementos.
		 */
		void iniciarCursor(){
			this->cursor = NULL;
		}
	
		/*
 		 * PRE: se inicio el recorrido de la lista y no se modifico el contenido de la misma.
		 * POST: pone el cursor de la lista una posicion mas adelante e indica si
		 * 	 logro apuntar a un nuevo elemento.
		 */
		bool avanzarCursor(){
			if(this->cursor == NULL){
				this->cursor = this->primero;
			}
			else{
				this->cursor = cursor->obtenerSiguiente();
			}
			return (this->cursor != NULL);
		}

		/* PRE: el cursor tiene que estar en una posicion valida.
		 * POST: devuelve el elemento de la Lista donde se encuentra el cursor.
		 */
		T obtenerCursor(){
			return cursor->obtenerContenido();
		}

		/* PRE: 'posicion' debe permanecer al intervalo [1, obtenerTamanio() + 1].
		 * POST: agrega el 'elemento' a la Lista en la 'posicion' indicada.
		 */
		void insertar(T elemento, unsigned int posicion){
			if ((posicion <= 0) || (posicion > (tamanio + 1))){
				throw std::string("Error al agregar. Posicion incorrecta.");
			}
			NodoDoble<T>* nuevo = new NodoDoble<T>(elemento);
			if (posicion == 1){
				if (primero == NULL){
					ultimo = nuevo;
				} else {
					nuevo->asignarSiguiente(primero);
					primero->asignarAnterior(nuevo);
				}
				primero = nuevo;
			} else if (posicion == (tamanio + 1)){
				nuevo->asignarSiguiente(ultimo->obtenerSiguiente());
				nuevo->asignarAnterior(ultimo);
				ultimo->asignarSiguiente(nuevo);
				ultimo = nuevo;
			} else {
				NodoDoble<T>* anterior = obtenerNodo(posicion - 1);
				nuevo->asignarAnterior(anterior);
				nuevo->asignarSiguiente(anterior->obtenerSiguiente());
				anterior->obtenerSiguiente()->asignarAnterior(nuevo);
				anterior->asignarSiguiente(nuevo);
			}
			this->tamanio++;
			this->iniciarCursor();
		}

		/* 
		 * POST: agrega el 'elemento' al final de la Lista.
		 */
		void agregar(T elemento){
			this->insertar(elemento, this->tamanio + 1);
		}


		/* PRE: 'posicion' debe permanecer al intervalo [1, obtenerTamanio()].
		 * POST: devuelve el contenido de dicha 'posicion' de la Lista.
		 */
		T obtenerDato(unsigned int posicion){
			if ((posicion <= 0) || (posicion > tamanio)){
				throw std::string("Error al obtener elemento. La posicion es incorrecta.");
			}

			return (this->obtenerNodo(posicion)->obtenerContenido());
		}

		/* PRE: 'posicion' debe permanecer al intervalo [1, obtenerTamanio()].
		 * POST: elimina el elemento de la Lista y lo retorna.
		 */
		T sacar(unsigned int posicion){
			if ((posicion <= 0) || (posicion > tamanio)){
				throw std::string("Error al borrar elemento. La posicion es incorrecta.");
			}
			NodoDoble<T>* borrado;
			if (posicion == 1){
				borrado = primero;
				primero = borrado->obtenerSiguiente();
				if (primero == NULL){
					this->ultimo = NULL;
				}
			} else if (posicion == tamanio){
				borrado = ultimo;
				ultimo = ultimo->obtenerAnterior();
				ultimo->asignarSiguiente(NULL);
			} else {
				NodoDoble<T>* anterior = this->obtenerNodo(posicion - 1);
				borrado = anterior->obtenerSiguiente();
				anterior->asignarSiguiente(borrado->obtenerSiguiente());
				borrado->obtenerSiguiente()->asignarAnterior(anterior);
			}
			T elementoBorrado = borrado->obtenerContenido();
			delete borrado;
			return elementoBorrado;
		}

		/* POST: devuelve el tamanio de la Lista. 
		 */
		unsigned int obtenerTamanio(){
			return this->tamanio;
		}
	
		/* POST: devuelve la posicion donde se encuentra el 'dato'.
		 *	 Si no esta en la lista devuelve 0.
		 */
		unsigned int buscarPosicionDelElemento(T dato){
			unsigned int posicionEnLista = 0;
			unsigned int posicionCursor = 0;
			bool encontrado = false;
			this->iniciarCursor();
			while(this->avanzarCursor() && (! encontrado)){
				encontrado = (this->obtenerCursor() == dato);
				posicionCursor++;
			}
			if(encontrado){
				posicionEnLista = posicionCursor;
			}
			this->iniciarCursor();
			return posicionEnLista;
		}

		/* PRE: la lista no debe estar vacia.
		 * POST: devuelve el ultimo elemento de la lista.
		 */
		T obtenerUltimoElemento(){
			if(this->ultimo == NULL){
				throw std::string("La lista esta vacia");
			}
			return this->ultimo->obtenerContenido();
		}

		/* PRE: el cursor recorrio un elemento anterior a la posicion en la que se encuentra 			 *      ahora.
 		 * POST: devuelve el elemento anterior al apuntado por el cursor.
 		 */
		T obtenerElementoAnterior(){
			T elementoAnterior;
			NodoDoble<T>* nodoApuntado = this->cursor;
			NodoDoble<T>* nodoAnterior = nodoApuntado->obtenerAnterior();
			elementoAnterior = nodoAnterior->obtenerContenido();
			return elementoAnterior;
		}

		/* PRE: el cursor esta en medio de un recorrido y hay un elemento posterior a la 			 *      posicion en la que se encuentra ahora.
		 * POST: devuelve el elemento posterior al apuntado por el cursor.
		 */
		T obtenerElementoPosterior(){
			T elementoPosterior;
			NodoDoble<T>* nodoApuntado = this->cursor;
			NodoDoble<T>* nodoPosterior = nodoApuntado->obtenerSiguiente();
			elementoPosterior = nodoPosterior->obtenerContenido();
			return elementoPosterior;
		}

		/* POST: elimina todos los recursos utilizados.
		 */
		~ListaDoble(){
			while(!this->estaVacia()){
				this->sacar(this->obtenerTamanio());
			}
		}

		private:

		/*
		 * PRE: 'posicion' esta entre [1, obtenerTamanio()].
		 * POST: devuelve el nodo en la posicion indicada.
		 */
		NodoDoble<T>* obtenerNodo(unsigned int posicion){
			NodoDoble<T>* auxiliar = this->primero;
			for(int i = 1; i < posicion; i++){
				auxiliar = auxiliar->obtenerSiguiente();
			}
			return auxiliar;
		}

};

#endif /* LISTADOBLE_H_ */
