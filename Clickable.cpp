#include"Clickable.h"


Clickable::Clickable(std::function<void(SDL_Event*)> onClick, std::function<bool(SDL_Event*)> mouseInRectangle, bool clickAndReturn) {
	AppState::Get().AddPolledEvent(SDL_MOUSEBUTTONDOWN, [&mouseInRectangle,&onClick](SDL_Event* e) mutable {if (mouseInRectangle(e)) onClick(e); });
}