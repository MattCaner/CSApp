#pragma once
#include"AppState.h"
#include"AppWindow.h"

AppState::~AppState() {
	delete _window;
	delete _renderer;
}

AppState& AppState::Get() {
	static AppState instance;
	return instance;
}

bool AppState::Init(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags, Uint32 RendererFlag) {
	Get().InitInstance(height, width, startingState, SDLinitflags, RendererFlag);
	return true;
}

bool AppState::InitInstance(unsigned int height, unsigned int width, state startingState, Uint32 SDLinitflags, Uint32 RendererFlags) {



	if (SDLinitflags) {
		if (SDL_Init(SDLinitflags) < 0) throw sdl_init_error("SDL not initialised sucessfully! Error code: " + std::string(SDL_GetError()));
	}
	
	_window = new AppWindow(width, height);

	_state = startingState;

	_renderer = SDL_CreateRenderer(_window->_window,-1,RendererFlags);
	if (_renderer == nullptr) throw sdl_init_error("Renderer not initialised succesfully! Error code: " + std::string(SDL_GetError()));

	cout << "Application initialised" << endl;

	return true;
}

bool AppState::Quit() {

	cout << "Beginning termination of application" << endl;
	
	_window->Terminate();

	SDL_Quit();
	_state = TERMINATED;

	return true;
}

AppState::state AppState::getState() const { return _state; }

AppState::AppState(): _window(nullptr), _state(FALSESTATE), _renderer(nullptr) {
	cout << "Application created, waiting for initiation." << endl;
}

SDL_Renderer* AppState::GetRenderer() {
	return _renderer;
}

AppWindow& AppState::GetWindow() {
	return *_window;
}

void AppState::PollEvents() {

	SDL_Event e;
	while (SDL_PollEvent(&e) != 0) {
		_window->pollEvent(&e);
	}
}

Panel* AppState::MainPanel() {
	return &(_window->getMainPanel());
}

void AppState::AddPolledType(Uint32 type) {
	_window->AddPolledType(type);
}

void AppState::AddPolledEvent(Uint32 type, std::function<void(SDL_Event* e)> f) {
	_window->AddPolledEvent(type, f);
}

void AppState::ClearWindow() {
	SDL_RenderClear(_renderer);
}

void AppState::UpdateWindow() {
	SDL_RenderPresent(_renderer);
}