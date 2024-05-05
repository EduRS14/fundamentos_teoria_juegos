#include <iostream>
#include <SDL/SDL.h>
#include "MainGame.h"

// Entrega de la TA2

// El funcionamiento pedido para esta tarea se encuentra en los archivos MainGame.cpp y MainGame.h

using namespace std;

int main(int argc, char** argv) {

	MainGame mainGame;
	mainGame.run();
	system("pause");
	return 0;

}