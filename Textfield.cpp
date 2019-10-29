#include"Textfield.h"

Textfield::Textfield(wstring text, Font* font, SDL_Color color, Sprite* hook, Panel* panel, float sizeX, float sizeY, float posX, float posY, int size):
	Sprite(panel,nullptr,sizeX,sizeY,posX,posY), _text(text), _font(font), _color(color), _wrap(false), _size(-1), _Vpadding(0), _Hpadding(0), _visible(true) 	{

}

