#pragma once
#include"Sprite.h"

class SpriteExtension {
public:
	SpriteExtension(Sprite* hook): _hook(hook) {}
	virtual void debugInfo() {}
protected:
	Sprite* getHook() { return _hook; }
private:
	Sprite* _hook;
};