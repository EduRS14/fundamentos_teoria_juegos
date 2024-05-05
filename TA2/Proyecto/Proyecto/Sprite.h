#pragma once
#include <GL/glew.h>
#include <string>
#include "GLTexture.h"
using namespace std;

class Sprite
{
private:
	float x, y;
	float width, height;
	GLuint vboID;
	float vertexData;
	GLTexture texture;

public:
	Sprite();
	~Sprite();
	void init(float x, float y, float width, float height, string texturePath);
	void draw();

};