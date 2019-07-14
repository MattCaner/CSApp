#pragma once

//basic includes:
//sdl:
#include <SDL.h>
#include <SDL_image.h>

//standard library:
#include <cmath>
#include <iostream>
#include <vector>
#include <map>
#include <functional>

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