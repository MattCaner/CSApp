#pragma once
#include"Sprite.h"

class SpriteExtension {
public:
	SpriteExtension(Sprite* hook): _hook(hook) {}
	virtual void onDraw() { cout << "probably error! Calling onDraw from spriteExtension" << endl; }
protected:
	Sprite* getHook() { return _hook; }
private:
	Sprite* _hook;
};