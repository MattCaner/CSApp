#include"Textfield.h"

#include <comdef.h>

Textfield::Textfield(wstring text, TTF_Font* font, SDL_Color color, Sprite* hook, bool wrapText) : SpriteExtension(hook), _text(text), _font(font),
_color(color), _wrap(wrapText), _visible(true) { 

}

void Textfield::onDraw() {
	//cout << "onDraw for TextField" << endl;
	const wchar_t* tmpstr = _text.c_str();
	_bstr_t tmpstrlong(tmpstr);
	const char* tmpstrmultibyte = tmpstrlong;
	SDL_Surface* tmp = TTF_RenderText_Solid(_font, tmpstrmultibyte, _color);
	SDL_Texture* tmptexture = SDL_CreateTextureFromSurface(AppState::Get().GetRenderer(), tmp);

	SDL_Rect tmpRect = getHook()->GetLimits();
	SDL_RenderSetViewport(AppState::Get().GetRenderer(), &tmpRect);
	SDL_RenderCopy(AppState::Get().GetRenderer(), tmptexture, NULL, NULL);
}