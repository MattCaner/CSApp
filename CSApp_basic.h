#pragma once

//basic includes:
//sdl:
#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>

//standard library:
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

//custom exception file:
#include"SDLException.h"

//Forward declarations:

class AppState;

class TextureArray;
struct v2di;
struct v2d;

class Panel;
class AppWindow;

class EventHandler;
class Sprite;
class SpriteExtension;
class Clickable;
class Highlightable;


//using directives:
using std::cout;
using std::endl;
using std::map;
using std::vector;
using std::wstring;