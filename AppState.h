#pragma once
#include"CSApp_basic.h"

class Panel;
class AppWindow;


//Application State Controller, handles all the thing application needs to function,
//including window, rendering and event polling management. It is a singleton - only
//one application state controller can exists per application.
class AppState {
public:
	enum state {
		FALSESTATE = -1,
		TERMINATED = 0,
		RUNNING = 1,
		LOADING = 2
	};
	
	//default getter of instance
	static AppState& Get();

	//initiatior (fired by other classes)
	static bool Init(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags = 0, Uint32 RendererFlags = SDL_RENDERER_ACCELERATED);
	
	void AddPolledType(Uint32 type);
	void AddPolledEvent(Uint32 type, std::function<void(SDL_Event* e)> f);

	void ClearWindow();

	void UpdateWindow();
	
	bool Quit();
	state getState() const;
	SDL_Renderer* GetRenderer();
	AppWindow& GetWindow();

	void PollEvents();

	Panel* MainPanel();
	
	bool InitInstance(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags, Uint32 RendererFlags);

private:

	AppState();
	AppWindow* _window;
	state _state;
	SDL_Renderer* _renderer;
	SDL_Event _event;

};