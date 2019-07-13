#include"CSApp.h"


int main(int argc, char* args[])
{
	AppState::Init(480,640, AppState::RUNNING, SDL_INIT_VIDEO);

	TextureArray textures;
	textures.addTexture(loadFromFile("tmp.bmp"));

	Sprite* stickguy = new Sprite(APP.MainPanel(), &textures, 200, 200, 30, 30);
	stickguy->setTextureNumber(0);

	while (APP.getState() != AppState::TERMINATED) {

		APP.ClearWindow();
		APP.PollEvents();
		APP.UpdateWindow();

	}

	return 0;
}