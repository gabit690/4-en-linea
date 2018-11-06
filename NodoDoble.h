#ifndef NODODOBLE_H_
#define NODODOBLE_H_

template <typename T> class NodoDoble{

	private:
		NodoDoble<T>* anterior;
		T dato;
		NodoDoble<T>* siguiente;

	public:
		NodoDoble(T contenido){
			this->anterior = NULL;
			this->dato = contenido;
			this->siguiente = NULL;
		}

		void cambiarContenido(T nuevoContenido){
			this->dato = nuevoContenido;
		}

		void asignarAnterior(NodoDoble<T>* otroNodo){
			this->anterior = otroNodo;
		}

		void asignarSiguiente(NodoDoble<T>* otroNodo){
			this->siguiente = otroNodo;
		}

		T obtenerContenido(){
			return this->dato;
		}

		NodoDoble<T>* obtenerAnterior(){
			return this->anterior;
		}

		NodoDoble<T>* obtenerSiguiente(){
			return this->siguiente;
		}

};

#endif /* NODODOBLE_H_ */
