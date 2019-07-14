#include"CSApp.h"

struct TEST {
	void onMenuClick(SDL_Event* e) {
		cout << "Click accepted" << endl;
	}
	int x;
};



int main(int argc, char* args[])
{
	APP_INIT(480, 640, AppState::RUNNING, SDL_INIT_VIDEO);
		
	TextureArray* menuTextures = new TextureArray();
	menuTextures->addTexture(loadFromFile("b1.bmp"));

	//Panel* menuButtonPanel = new Panel(APP.MainPanel(), 0.33f, 0.8f, 0.33f, 0.1f);
	//Sprite* buttonPlay = new Sprite(menuButtonPanel, menuTextures, 0.9f, 0.15f, 0.05f, 0.1f);

	Sprite* buttonPlay = new Sprite(APP.MainPanel(), menuTextures, 0.9f, 0.15f, 0.05f, 0.1f);
	
	TEST test1;

	buttonPlay->makeButton([&test1](SDL_Event* e) mutable {test1.onMenuClick(e); });

	APP.AddPolledType(SDL_QUIT);
	APP.AddPolledEvent(SDL_QUIT, [](SDL_Event* e) {APP.Quit(); });

	APP.AddPolledEvent(SDL_MOUSEBUTTONDOWN, [](SDL_Event* e) {cout << getMouseVector().x << ";" << getMouseVector().y << endl; });

	while (APP.getState() != AppState::TERMINATED) {

		APP.ClearWindow();

		buttonPlay->Draw();

		APP.PollEvents();
		APP.UpdateWindow();

	}

	return 0;
}