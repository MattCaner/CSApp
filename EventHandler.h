#pragma once
#include"CSApp_basic.h"


struct EventTypeHandler {
	EventTypeHandler() = default;
	EventTypeHandler(Uint32 et) : eventType(et) {}
	Uint32 eventType;
	vector<std::function<void(SDL_Event*)>> toExecute;
	void ExecuteAll(SDL_Event* e);

};


class EventHandler {
public:
	
	EventHandler() {}
	
	void AddPolledType(Uint32 type);
	void AddMethod(Uint32 eventType, std::function<void(SDL_Event*)> method);
	void Clear();

	void RunExecution(SDL_Event* e);

private:

	map<Uint32,EventTypeHandler> _register;

};

