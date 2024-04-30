#include "MainGame.h"
#include "Sprite.h"

// Las líneas agregadas se encuentran en las funciones MainGame(), draw y update

MainGame::MainGame()
{
    window = nullptr;
    width = 800;
    height = 600;
    gameState = GameState::PLAY;
    cuadradoActual = 1;
    tiempoCambio = 0;
    condicion1 = false;
}

void MainGame::init()
{
    SDL_Init(SDL_INIT_EVERYTHING);
    window = SDL_CreateWindow("Ventana TA1", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, SDL_WINDOW_OPENGL);
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
    program.linkShaders();
}

void MainGame::draw(int currentSquare)
{
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    program.use();

    GLuint timeLocation = program.getUniformLocation("time");
    glUniform1f(timeLocation, time);

    time += 0.0002;

  	// Condición para saber qué cuadrados dibujar
    switch (currentSquare)
    {
        case 1:
		    cuadrado1.draw();
		    break;
        case 2:
            cuadrado1.draw();
            cuadrado2.draw();
            break;
        case 3:
            cuadrado1.draw();
            cuadrado2.draw();
            cuadrado3.draw();
            break;
        case 4:
            cuadrado1.draw();
            cuadrado2.draw();
            cuadrado3.draw();
            cuadrado4.draw();
			break;
        case 5:
            cuadrado1.draw();
            cuadrado3.draw();
            cuadrado4.draw();
            break;
        case 6:
            cuadrado2.draw();
            cuadrado4.draw();
            cuadrado1.draw();
            break;
        case 7:
            cuadrado3.draw();
            cuadrado1.draw();
            cuadrado2.draw();
            break;
        case 8:
            cuadrado4.draw();
            cuadrado2.draw();
            cuadrado3.draw();
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

    cuadrado1.init(-1, 0, 1, 1);
    cuadrado2.init(0, 0, 1, 1);
    cuadrado3.init(0, -1, 1, 1);
    cuadrado4.init(-1, -1, 1, 1);

    update();
}

void MainGame::update()
{
	while (gameState != GameState::EXIT)
	{
        // Variable que sirva de contador para saber qué cuadrados dibujar
        tiempoCambio += 0.0002;

		processInput();

        // Condición del contador para saber qué cuadrados dibujar
		if (tiempoCambio > 5)
		{
            if (cuadradoActual <= 4) {
                cuadradoActual += 1;
            }
            else {
                // La condición se activa cuando se completó el primer ciclo
                condicion1 = true;
                // Si ya se completó el primer ciclo, se mostrarán solo 3 cuadrados, y su orden irá variando
                if (cuadradoActual < 8) {
                    cuadradoActual += 1;
                }
                else {
                    // Vuelve a la secuencia inicial del segundo ciclo
					cuadradoActual = 5;
                }
            }
            tiempoCambio = 0;
		}

		draw(cuadradoActual);
		
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

