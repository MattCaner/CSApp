#pragma once
#include"Panel.h"

Panel::Panel(Panel* parent, float sizeX, float sizeY, float posX, float posY) :
	_parent(parent), _appWindow(nullptr), _sizeX(sizeX), _sizeY(sizeY), _posX(posX), _posY(posY) {
	if (parent != nullptr) {
		_sizeX *= parent->getActualSize().x;
		_sizeY *= parent->getActualSize().y;
		_posX *= parent->getActualSize().x;
		_posY *= parent->getActualSize().y;
	}
}


Panel::Panel(Panel* parent, int sizeX, int sizeY, int posX, int posY) :
	_parent(parent), _appWindow(nullptr), _sizeX(sizeX), _sizeY(sizeY), _posX(posX), _posY(posY) {

}

v2d Panel::getActualSize() {
	if (_parent == nullptr) {
		return v2d(_appWindow->getHeight(), _appWindow->getWidth());
	}
	else {
		return v2d(_parent->getActualSize().x * _sizeX, _parent->getActualSize().y * _sizeY);
	}
}

v2d Panel::getActualPosition() {
	if (_parent == nullptr) {
		return v2d(0.f, 0.f);
	}
	else {
		v2d p = _parent->getActualPosition();
		v2d s = _parent->getActualSize();
		return v2d(p.x + s.x * _sizeX, p.y + s.y * _sizeY);
	}

}

v2d Panel::transformWorldToPanel(v2d v) {
	if (_parent == nullptr) {
		return v;
	}
	else {
		return v2d(getActualPosition().x + getActualSize().x * v.x, getActualPosition().y + getActualSize().y * v.y);
	}
}

v2d Panel::transformPanelToWorld(v2d v) {
	return v2d(getActualPosition().x + getActualSize().x * v.x, getActualPosition().y + getActualSize().y * v.y);
}


SDL_Rect Panel::GetLimits() const{

	SDL_Rect tmp;

	if (_parent == nullptr) {
		tmp.x = _posX;
		tmp.y = _posY;
	}
	else {
		tmp.x = _parent->getActualPosition().x + _posX;
		tmp.y = _parent->getActualPosition().y + _posY;
	}


	tmp.w = _sizeX;
	tmp.h = _sizeY;

	return tmp;

}