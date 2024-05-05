#pragma once

#include <string>
#include <map>
#include "GLTexture.h"

using namespace std;

class TextureCache
{
private:
	map<string, GLTexture> textureMap;
public:
	TextureCache();
	~TextureCache();

	GLTexture getTexture(string texturePath);
};