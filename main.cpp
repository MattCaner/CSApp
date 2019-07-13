#include"CSApp.h"


int main(int argc, char* args[])
{
	AppState::Init(480,640, AppState::RUNNING, SDL_INIT_VIDEO);

	TextureArray textures;
	textures.addTexture(loadFromFile("tmp.bmp"));

	Sprite* stickguy = new Sprite(APP.MainPanel(), &textures, 200, 200, 30, 30);
	stickguy->setTextureNumber(0);

	APP.AddPolledType(SDL_QUIT);
	APP.AddPolledEvent(SDL_QUIT, [](SDL_Event* e) {cout << "closing event" << endl;  APP.Quit(); });

	APP.AddPolledType(SDL_KEYDOWN);
	APP.AddPolledEvent(SDL_KEYDOWN, [&stickguy](SDL_Event* e) mutable {
		switch (e->key.keysym.sym){
		case SDLK_UP:
			stickguy->SetPosition(stickguy->GetIntPosition()+v2di(0,-10));
			break;
		case SDLK_DOWN:
			stickguy->SetPosition(stickguy->GetIntPosition() + v2di(0, 10));
			break;
		case SDLK_LEFT:
			stickguy->SetPosition(stickguy->GetIntPosition() + v2di(-10, 0));
			break;
		case SDLK_RIGHT:
			stickguy->SetPosition(stickguy->GetIntPosition() + v2di(10 , 0));
			break;
		}
	} );

	while (APP.getState() != AppState::TERMINATED) {

		APP.ClearWindow();

		APP.PollEvents();

		stickguy->Draw();


		APP.UpdateWindow();

	}

	return 0;
}