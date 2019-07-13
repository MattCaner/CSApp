#pragma once
#include"AppWindow.h"
#include"Utilities.h"


class Panel {
public:
	Panel(Panel* parent, float sizeX, float sizeY, float posX, float posY);

	Panel(Panel* parent, int sizeX, int sizeY, int posX, int posY);

	v2d getActualSize();
	v2d getActualPosition();
	v2d transformWorldToPanel(v2d v);
	v2d transformPanelToWorld(v2d v);

	SDL_Rect GetLimits() const;

	void setPosition(v2d position);
	void setPosition(v2di position);

private:

	SDL_Rect* _limits;

	Panel* _parent;
	AppWindow* _appWindow;

	int _sizeX;
	int _sizeY;
	int _posX;
	int _posY;

};
