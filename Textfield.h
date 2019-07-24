#pragma once
#include"SpriteExtension.h"
#include"FontHandler.h"

class Textfield : public Sprite {
public:
	Textfield(wstring text, Font* font, SDL_Color color, Sprite* hook, int size = -1);

	void SetTextWrap(bool state);
	void SetPadding(float padding);
	void SetPadding(int padding);

	void SetHPadding(int padding);
	void SetVPadding(int padding);

	void Show(bool visibility);

	void SetText(wstring text);
	void SetColor(SDL_Color color);
	void SetSize(int size);

	wstring GetText() const;

	void onDraw();
	

private:

	wstring _text;
	Font* _font;
	SDL_Color _color;
	int _size;

	bool _wrap;

	int _Vpadding;
	int _Hpadding;

	bool _visible;

};