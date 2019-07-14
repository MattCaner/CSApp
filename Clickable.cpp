#include"Clickable.h"


Clickable::Clickable(Sprite* spritehook, std::function<void(SDL_Event*)> onClick, bool clickAndReturn):
	SpriteExtension(spritehook), _isClickAndReturn(clickAndReturn){
	AppState::Get().AddPolledEvent(SDL_MOUSEBUTTONDOWN, [onClick, spritehook](SDL_Event* e) {
		SDL_Rect tmp = spritehook->GetLimits();
		if (mouseInRectangle(getMouseVector(), tmp)) onClick(e);
	});
}