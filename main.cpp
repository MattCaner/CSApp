#include"CSApp.h"

struct TEST {
	void onMenuClick(SDL_Event* e) {
		cout << "Click accepted" << endl;
	}
	int x;
};


#pragma optimize("",off)

int main(int argc, char* args[])
{
	APP_INIT(480, 640, AppState::RUNNING, SDL_INIT_VIDEO);

	TTF_Init();
		
	TextureArray* menuTextures = new TextureArray();
	menuTextures->addTexture(loadFromFile("b1.bmp"));
	menuTextures->addTexture(loadFromFile("white.bmp"));
	TTF_Font* Arial = TTF_OpenFont("arial.ttf", 28);

	if (!Arial) {
		cout << "Font not loaded. Error: " << TTF_GetError() << endl;
	}

	//Panel* menuButtonPanel = new Panel(APP.MainPanel(), 0.33f, 0.8f, 0.33f, 0.1f);
	//Sprite* buttonPlay = new Sprite(menuButtonPanel, menuTextures, 0.9f, 0.15f, 0.05f, 0.1f);

	Sprite* buttonPlay = new Sprite(APP.MainPanel(), menuTextures,0.2f,0.06f,0.4f,0.4f);

	Panel* menuPanel = new Panel(APP.MainPanel(), 0.33f, 0.8f, 0.33f, 0.1f);

	Sprite* whitePane = new Sprite(menuPanel, menuTextures,1.0f,1.0f,0.f,0.f);
	whitePane->SetTextureNumber(1);
	
	TEST test1;

	buttonPlay->makeButton([&test1](SDL_Event* e) mutable {test1.onMenuClick(e); });
	buttonPlay->addTextField(L"Actual Button", Arial, { 0,0,0 }, true);

	APP.AddPolledType(SDL_QUIT);
	APP.AddPolledEvent(SDL_QUIT, [](SDL_Event* e) {APP.Quit(); });

	APP.AddPolledEvent(SDL_MOUSEBUTTONDOWN, [](SDL_Event* e) {cout << getMouseVector().x << ";" << getMouseVector().y << endl; });

	while (APP.getState() != AppState::TERMINATED) {

		APP.ClearWindow();
//		cout << "MENUPANEL:" << menuPanel->GetLimits().x << " " << menuPanel->GetLimits().y << " " << menuPanel->GetLimits().w << " " << menuPanel->GetLimits().h << endl;
//		cout << "LIMITS:" << whitePane->GetLimits().x << " " << whitePane->GetLimits().y << " " << whitePane->GetLimits().w << " " << whitePane->GetLimits().h << endl;
		whitePane->Draw();
		buttonPlay->Draw();

		APP.PollEvents();
		APP.UpdateWindow();

	}

	return 0;
}