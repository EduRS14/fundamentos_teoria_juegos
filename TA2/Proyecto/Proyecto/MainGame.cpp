#include "MainGame.h"
#include "Sprite.h"

// Las líneas agregadas se encuentran en las funciones MainGame(), run, draw y update

MainGame::MainGame()
{
	window = nullptr;
	width = 800;
	height = 600;
	gameState = GameState::PLAY;
	tiempo = 0; // Inicialización del contador
	imagenActual = 1; // Imagen inicial
}

void MainGame::init()
{
	SDL_Init(SDL_INIT_EVERYTHING);
	window = SDL_CreateWindow("TA02", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
	SDL_GLContext glContext = SDL_GL_CreateContext(window);
	GLenum error = glewInit();
	if (error != GLEW_OK)
	{
		// Falta validar el estado del glew
	}
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	initShaders();
}

void MainGame::initShaders()
{
	program.compileShaders("Shaders/colorShaderVert.txt", "Shaders/colorShaderFrag.txt");
	program.addAttribute("vertexPosition");
	program.addAttribute("vertexColor");
	program.addAttribute("vertexUV");
	program.linkShaders();
}

void MainGame::draw(int imagenActual)
{
	glClearDepth(1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	program.use();

	// Condición para saber que imagenes mostrar
	switch (imagenActual)
	{
	case 1:
		mario_p.draw();
		break;
	case 2:
		mario_p.draw();
		bowser_jr.draw();
		break;
	case 3:
		goomba.draw();
		break;
	case 4:
		goomba.draw();
		mario_m.draw();
		break;
	case 5:
		mario_d.draw();
		break;
	case 6:
		mario_d.draw();
		bowser.draw();
		break;
	default:
		break;
	}


	program.unuse();
	SDL_GL_SwapWindow(window);

}


void MainGame::run()
{
	init();

	// Imagenes

	mario_p.init(-0.5, -0.5, 0.5, 0.5, "images/mario_p.png");
	mario_d.init(-1, 0.5, 0.5, 0.5, "images/mario_d.png");
	mario_m.init(0.5, -0.5, 0.5, 0.5, "images/mario_m.png");
	goomba.init(0.5, -1, 0.5, 0.5, "images/goomba.png");
	bowser.init(-0.5, 0.5, 0.5, 0.5, "images/bowser.png");
	bowser_jr.init(0, 0, 0.5, 0.5, "images/bowser_jr.png");

	update();
}

void MainGame::update()
{
	while (gameState != GameState::EXIT)
	{
		// Variable que sirva de contador para saber qué imagen mostrar
		tiempo += 0.0002;

		processInput();
		// Condición del contador para saber qué cuadrados dibujar
		if (tiempo > 2)
		{
			if (imagenActual < 6) {
				imagenActual += 1;
			}
			else {
				imagenActual = 1;
			}

			tiempo = 0;
		}

		draw(imagenActual);
	}
}

void MainGame::processInput()
{
	SDL_Event event;
	while (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			gameState = GameState::EXIT;
			break;
		default:
			break;
		}
	}
}

MainGame::~MainGame()
{
}

