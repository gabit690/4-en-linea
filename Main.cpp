#include "CuatroEnLinea.h"
#include <ctime>
#include <cstdlib>

int main(){

	std::srand(std::time(NULL));

	CuatroEnLinea* juego = new CuatroEnLinea();
	bool terminarPrograma = false;

	while(! terminarPrograma){
		juego->iniciarJuego();
		juego->setearPartida();
		juego->jugarPartida();

		terminarPrograma = juego->finalizarJuego();
	}
	delete juego;
	std::cout << "Hasta luego...." << std::endl;
	return 0;
}
