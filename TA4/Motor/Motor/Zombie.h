#pragma once
#include "Agent.h"
class Zombie :
    public Agent
{
private:
    // Vector de direccion del zombie
    glm::vec2 direction;
    // Variable de fatiga
    float fatiga;
public:
    Zombie();
    ~Zombie();
    void init(float speed, glm::vec2 position);
    void update(vector<string>& levelData,
        vector<Human*>& humans,
        vector<Zombie*>& zombies);
    void condicionFatiga(int valor);
};

