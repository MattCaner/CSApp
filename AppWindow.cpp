#pragma once
#include"AppWindow.h"

#include"Panel.h"


AppWindow::AppWindow(int width, int height) : _window(SDL_CreateWindow("test", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN)),
_mainPanel(new Panel(nullptr,width,height,0,0)),_evhandler(new EventHandler()) {
	cout << "Creating window" << endl;
}


AppWindow::~AppWindow() {

}


void AppWindow::Terminate() {
	cout << "terminating window" << endl;
	SDL_DestroyWindow(_window);
	cout << "window terminated" << endl;
}

void AppWindow::pollEvent(SDL_Event* e) {
	_evhandler->RunExecution(e);
}

int AppWindow::getWidth() const {
	int w;
	SDL_GetWindowSize(_window, &w, nullptr);
	return w;
}

int AppWindow::getHeight() const {
	int h;
	SDL_GetWindowSize(_window, nullptr, &h);
	return h;
}

Panel& AppWindow::getMainPanel() {
	return *_mainPanel;
}

void AppWindow::AddPolledType(Uint32 type) {
	_evhandler->AddPolledType(type);
}

void AppWindow::AddPolledEvent(Uint32 type, std::function<void(SDL_Event* e)> f) {
	_evhandler->AddMethod(type, f);
}