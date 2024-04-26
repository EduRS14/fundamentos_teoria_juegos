#include <iostream>
#include <SDL/SDL.h>
#include "MainGame.h"

// Entrega de la TA1

// El funcionamiento pedido para esta tarea se encuentra en el archivo MainGame.cpp

using namespace std;

int main(int argc, char** argv) {

	MainGame mainGame;
	mainGame.run();
	system("pause");
	return 0;

}