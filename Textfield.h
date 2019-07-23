#pragma once
#include"SpriteExtension.h"

class Textfield : public SpriteExtension {
public:
	Textfield(wstring text, TTF_Font* font, SDL_Color color, Sprite* hook, bool wrapText = true);

	void Show(bool visibility);

	void SetText(wstring text);
	void SetColor(SDL_Color color);
	void SetSize(int size);

	wstring GetText() const;

	void onDraw();
	

private:

	wstring _text;
	TTF_Font* _font;
	SDL_Color _color;
	int size;

	bool _wrap;

	bool _visible;

};