#pragma once
#include"CSApp_basic.h"
#include"Utilities.h"


//Application State Controller, handles all the thing application needs to function,
//including window, rendering and event polling management. It is a singleton - only
//one application state controller can exists per application.
class AppState {
public:

	~AppState();

	enum state {
		FALSESTATE = -1,
		TERMINATED = 0,
		RUNNING = 1,
		LOADING = 2
	};
	
	//Default getter of instance
	static AppState& Get();

	//Initiatior (fired by other classes)
	static bool Init(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags = 0, Uint32 RendererFlags = SDL_RENDERER_ACCELERATED);
	
	//Adds type of event to polling register. Adding the same type of event type twice will result in second time beeing ignored.
	void AddPolledType(Uint32 type);

	//Adds certain void(SDL_Event* e) function to be executed after event of declared type beeing polled.
	void AddPolledEvent(Uint32 type, std::function<void(SDL_Event* e)> f);

	//Clears window with its default renderer.
	void ClearWindow();

	//Updates window with its default renderer.
	void UpdateWindow();
	
	//Terminates application, destroys window, frees all used space. Set application state to TERMINATED (or 0).
	bool Quit();

	//Returns current state.
	state getState() const;

	//Returns pointer to default application renderer.
	SDL_Renderer* GetRenderer();

	//Returns reference to application AppWindow instance.
	AppWindow& GetWindow();

	//Sets AppWindow to poll all events in the queue until it is empty.
	void PollEvents();

	//Returns pointer to main panel of the AppWindow.
	Panel* MainPanel();

	//Inits current instance.	
	bool InitInstance(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags, Uint32 RendererFlags);

private:

	AppState();
	AppWindow* _window;
	state _state;
	SDL_Renderer* _renderer;
	SDL_Event _event;

};