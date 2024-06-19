#include "Zombie.h"
#include <random>
#include <ctime>
#include <glm/gtx/rotate_vector.hpp>

Zombie::Zombie()
{
}

Zombie::~Zombie()
{
}

void Zombie::init(float speed, glm::vec2 position)
{
	// Configuracion de la velocidad y la posicion del zombie
	this->speed = speed;
	color.set(0, 185, 0, 255);
	this->position = position;
	this->fatiga = 0.5f;
	std::mt19937 randomEngine(time(nullptr));
	std::uniform_real_distribution<float> randDir(-1.0f, 1.0f);

	direction = glm::vec2(randDir(randomEngine), randDir(randomEngine));
	if (direction.length() == 0)
	{
		direction = glm::vec2(1.0f, 1.0f);
	}
}

void Zombie::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
    std::mt19937 randomEngine(time(nullptr));
    std::uniform_real_distribution<float> randRotate(-40.0f, 40.0f);

    // Ajustamos la velocidad del zombie en función de la fatiga
    float velocidadAjustada = speed * (1.0f - fatiga);
    
    position += direction * velocidadAjustada;

    if (collideWithLevel(levelData))
    {
        direction = glm::rotate(direction, randRotate(randomEngine));
    }
}

// Funcion que ajusta la fatiga del zombie (TA3 + TA4)
void Zombie::condicionFatiga(int valor)
{
	if (valor > 0)
	{
		this->fatiga = 0.8f;
	}
	else
	{
		this->fatiga = 0.0f;
	}
}
