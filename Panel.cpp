#pragma once
#include"Panel.h"
#include"AppState.h"

Panel::Panel(Panel* parent, float sizeX, float sizeY, float posX, float posY) :
	_parent(parent), _appWindow(nullptr), _sizeX(0), _sizeY(0), _posX(0), _posY(0) {
	if (parent != nullptr) {
		_sizeX = (int)((float)(parent->getActualSize().x)*sizeX);
		_sizeY = (int)((float)(parent->getActualSize().y)*sizeY);
		_posX = (int)((float)(parent->getActualSize().x)*posX);
		_posY = (int)((float)(parent->getActualSize().y)*posY);
	}
}


Panel::Panel(Panel* parent, int sizeX, int sizeY, int posX, int posY) :
	_parent(parent), _appWindow(nullptr), _sizeX(sizeX), _sizeY(sizeY), _posX(posX), _posY(posY) {

}

v2d Panel::getActualSize() {
	return v2d(_sizeX, _sizeY);

}

v2d Panel::getActualPosition() {
	return v2d(_posX, _posY);

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
/*
void Panel::Draw() {

}*/
