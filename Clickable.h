#include"CSApp_basic.h"

class Clickable{
public:
	
	Clickable(std::function<void(SDL_Event*)> onClick, std::function<bool(SDL_Event*)> mouseInRectangle, bool clickAndReturn);
	
	bool isClickAndReturn() const { return _isClickAndReturn; }
	bool returnState() const { return _state; }

private:
	
	bool _isClickAndReturn;
	bool _state;

};