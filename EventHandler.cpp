#include "EventHandler.h"

void EventHandler::AddPolledType(Uint32 type) {
	_register.insert(std::make_pair(type, EventTypeHandler(type)));
}

void EventHandler::AddMethod(Uint32 eventType, std::function<void(SDL_Event*)> method) {
	_register[eventType].toExecute.push_back(method);
}

void EventHandler::Clear() {
	_register.clear();
}

void EventHandler::RunExecution(SDL_Event* e) {

	Uint32 index = e->type;
	_register[index].ExecuteAll(e);

}

void EventTypeHandler::ExecuteAll(SDL_Event* e){
	for (auto& i : toExecute) {
		i(e);
	}
}