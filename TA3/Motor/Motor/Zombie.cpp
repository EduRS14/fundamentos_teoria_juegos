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
	// Configuracion iniciales del zombie
	this->speed = speed;
	color.set(0, 185, 0, 255); // Definimos el color del zombie (verde)
	this->position = position;
}

void Zombie::update(vector<string>& levelData, vector<Human*>& humans, vector<Zombie*>& zombies)
{
}