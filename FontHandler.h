#pragma once
#include"CSApp_basic.h"

class Font {
public:
	Font();
	Font(const char* sourcepath, int size = 20);

	TTF_Font* GetFont();
	
private:

	TTF_Font* _currentFont;
	int _size;

};