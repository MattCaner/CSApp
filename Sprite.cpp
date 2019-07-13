#pragma once
#include"Sprite.h"

Sprite::Sprite(Panel* panel, const TextureArray* textures, float sizeX, float sizeY, float posX, float posY) : 
	_panel(panel), _textures(textures), _sizeX(sizeX*panel->getActualSize().x), _sizeY(sizeY*panel->getActualSize().y), _posX(posX*panel->getActualSize().x), _posY(posY* panel->getActualSize().y) {

}

Sprite::Sprite(Panel* panel, const TextureArray* textures, int sizeX, int sizeY, int posX, int posY) :
	_panel(panel), _textures(textures), _sizeX(sizeX), _sizeY(sizeY), _posX(posX), _posY(posY)
{

}

void Sprite::setTextureNumber(int indx) {
	_textureIndex = indx;
}

SDL_Rect Sprite::GetLimits() const {

	SDL_Rect tmp;
	tmp.x = _panel->getActualPosition().x + _posX;
	tmp.y = _panel->getActualPosition().y + _posY;
	tmp.w = _sizeX;
	tmp.h = _sizeY;

	return tmp;

}

v2di Sprite::GetIntPosition() const {
	return v2di(_posX, _posY);
}

void Sprite::SetPosition(v2d v) {

}

void Sprite::SetPosition(v2di v) {
	_posX = v.x;
	_posY = v.y;
}

void Sprite::Draw() {
	SDL_Rect tmp = GetLimits();
	SDL_RenderSetViewport(AppState::Get().GetRenderer(), &tmp);
	SDL_RenderCopy(AppState::Get().GetRenderer(), (*_textures)[_textureIndex], NULL, NULL);
}