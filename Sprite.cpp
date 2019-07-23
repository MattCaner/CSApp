#include"Sprite.h"
#include"Clickable.h"
#include"TextureArray.h"
#include"Textfield.h"



Drawable::Drawable(TextureArray* ta, int index) : _textures(ta), _index(index) {

}

void Drawable::SetTextureNumber(int index) {
	_index = index;
}

void Drawable::SetTextureArray(TextureArray* ta) {
	_textures = ta;
}

int Drawable::GetTextureIndex() const {
	return _index;
}

TextureArray* Drawable::getTextureArray() const {
	return _textures;
}

SDL_Texture* Drawable::getCurrentTexture() const {
	return _textures->operator[](_index);
}

Sprite::Sprite(Panel* panel, TextureArray* textures, float sizeX, float sizeY, float posX, float posY) : 
	Drawable(textures), _panel(panel), _sizeX((int)(sizeX*(float)(panel->getActualSize().x))), _sizeY((int)(sizeY*(float)(panel->getActualSize().y))), 
		_posX((int)(posX*(float)(panel->getActualSize().x))), _posY((int)(posY*(float)(panel->getActualSize().y))) {

}

Sprite::Sprite(Panel* panel, TextureArray* textures, int sizeX, int sizeY, int posX, int posY) :
	Drawable(textures), _panel(panel), _sizeX(sizeX), _sizeY(sizeY), _posX(posX), _posY(posY)
{

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
	SDL_RenderCopy(AppState::Get().GetRenderer(), getCurrentTexture(), NULL, NULL);
	for (auto& i : _extensions) {
		i->onDraw();
	}
}

void Sprite::makeButton(std::function<void(SDL_Event* e)> onClick) {
	SpriteExtension* _tmp = new Clickable(this, onClick, false);
	_extensions.push_back(_tmp);
}