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

		// Cuadrados agregados
		Sprite cuadrado1;
		Sprite cuadrado2;
		Sprite cuadrado3;
		Sprite cuadrado4;

		int width;
		int height;
		SDL_Window* window;
		void init();
		void processInput();
		GLS_Program program;
		void initShaders();
		float time = 0;

		// Variables agregadas
		int cuadradoActual; // Numero de cuadrado actual
		bool condicion1; // Condicion para saber si ya se completo el primer ciclo
		double tiempoCambio; // Contador para saber qué cuadrados dibujar

	public:
		MainGame();
		~MainGame();
		GameState gameState;
		void run();
		void draw(int currentSquare);
		void update();

};

