#pragma once
#include"SpriteExtension.h"
#include"Utilities.h"
#include"CSApp_basic.h"

class Clickable : public SpriteExtension {
public:
	
	Clickable(Sprite* spritehook, std::function<void(SDL_Event*)> onClick, bool clickAndReturn);
	bool isClickAndReturn() const { return _isClickAndReturn; }
	bool returnState() const { return _state; }

	void debugInfo() { }

private:
	
	bool _isClickAndReturn;
	bool _state;

};