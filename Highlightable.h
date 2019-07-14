#pragma once
#include"CSApp_basic.h"

class Highlightable {
public:

	Highlightable(std::function<void(SDL_Event*)> onClick, std::function<bool(SDL_Event*)> mouseInRectangle, bool clickAndReturn);

	bool isHighlighted() const { return _highlighted; }

private:

	bool _highlighted;

};