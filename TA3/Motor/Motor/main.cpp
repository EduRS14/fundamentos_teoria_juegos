#include <SDL/SDL.h>
#include "MainGame.h"

// Entrega TA3

// Los cambios realizados en el motor para dibujar a los zombies 
// se realizaron en las clases MainGame y Zombie.

int main(int argc, char** argv) {
	MainGame mainGame;
	mainGame.run();
	system("pause");
	return 0;
}
