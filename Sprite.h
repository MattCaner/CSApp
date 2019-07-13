#pragma once
#include"CSApp_basic.h"

class Sprite {
public:

	Sprite(Panel* panel, const TextureArray* textures, float sizeX, float sizeY, float posX, float posY);

	Sprite(Panel* panel, const TextureArray* textures, int sizeX, int sizeY, int posX, int posY);

	virtual void Draw();

	void setTextureNumber(int indx);

	v2d GetFloatPosition() const;
	v2di GetIntPosition() const;

	void SetPosition(v2d v);
	void SetPosition(v2di v);

	SDL_Rect GetLimits() const;

private:

	Panel* _panel;

	const TextureArray* _textures;
	unsigned int _textureIndex;

	int _sizeX;
	int _sizeY;
	int _posX;
	int _posY;

};