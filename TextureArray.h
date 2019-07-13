#pragma once
#include"CSApp_basic.h"

SDL_Texture* loadFromFile(std::string from);


class TextureArray{
public:
	TextureArray();
	TextureArray(SDL_Texture* firstOne);
	void addTexture(SDL_Texture* toAdd);

	SDL_Texture* operator[](int indx) const;

private:
	vector<SDL_Texture*> _textures;
};

