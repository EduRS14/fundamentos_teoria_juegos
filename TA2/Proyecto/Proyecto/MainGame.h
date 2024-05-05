#pragma once
#include <SDL/SDL.h>
#include <GL/eglew.h>
#include "Sprite.h"
#include "GLS_Program.h"
#include <iostream>

using namespace std;

enum class GameState { 
	PLAY, EXIT 
};

class MainGame
{
	private:

		// Imagenes:
		Sprite mario_p;
		Sprite mario_m;
		Sprite mario_d;
		Sprite goomba;
		Sprite bowser;
		Sprite bowser_jr;

		int width;
		int height;
		SDL_Window* window;
		void init();
		void processInput();
		GLS_Program program;
		void initShaders();

		// Variables agregadas
		int imagenActual; // Numero de imagen actual
		float tiempo = 0; // Contador para saber que imagen mostrar


	public:
		MainGame();
		~MainGame();
		GameState gameState;
		void run();
		void draw(int imagenActual);
		void update();

};

