#include"Textfield.h"

#include <comdef.h>

Textfield::Textfield(wstring text, Font* font, SDL_Color color, Sprite* hook, int size) : SpriteExtension(hook), _text(text), _font(font),
_color(color), _size(size), _wrap(false), _Vpadding(0), _Hpadding(0), _visible(true) { 

}

void Textfield::SetPadding(int padding) {
	_Vpadding = padding;
	_Hpadding = padding;
}

void Textfield::SetPadding(float padding) {
	_Vpadding = getHook()->GetLimits().h * padding;
	_Hpadding = getHook()->GetLimits().w * padding;
}

void Textfield::SetHPadding(int padding) {
	_Hpadding = padding;
}

void Textfield::SetVPadding(int padding) {
	_Vpadding = padding;
}

void Textfield::onDraw() {
	//cout << "onDraw for TextField" << endl;
	const wchar_t* tmpstr = _text.c_str();
	_bstr_t tmpstrlong(tmpstr);
	const char* tmpstrmultibyte = tmpstrlong;
	SDL_Surface* tmp = TTF_RenderUTF8_Blended(_font->GetFont(), tmpstrmultibyte, _color);
	SDL_Texture* tmptexture = SDL_CreateTextureFromSurface(AppState::Get().GetRenderer(), tmp);

	SDL_Rect tmpRect = getHook()->GetLimits();
	tmpRect.x += _Hpadding;
	tmpRect.y += _Vpadding;
	tmpRect.w -= 2*_Hpadding;
	tmpRect.h -= 2*_Vpadding;
	SDL_RenderSetViewport(AppState::Get().GetRenderer(), &tmpRect);
	SDL_RenderCopy(AppState::Get().GetRenderer(), tmptexture, NULL, NULL);

	SDL_FreeSurface(tmp);
	SDL_DestroyTexture(tmptexture);
}