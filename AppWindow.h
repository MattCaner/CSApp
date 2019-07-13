#pragma once
#include"AppState.h"
#include"Panel.h"
#include"EventHandler.h"

class Panel;

class AppWindow {
public:

	AppWindow(int width, int height);
	~AppWindow();

	void Terminate();
	void pollEvent(SDL_Event* e);
	int getWidth() const;
	int getHeight() const;

	void AddPolledType(Uint32 type);
	void AddPolledEvent(Uint32 type, std::function<void(SDL_Event* e)> f);

	Panel& getMainPanel();

	friend bool AppState::InitInstance(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags, Uint32 RendererFlags);


private:
	SDL_Window* _window;
	Panel* _mainPanel;
	EventHandler* _evhandler;
};

