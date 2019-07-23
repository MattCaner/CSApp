#include"SDLException.h"

sdl_exception::sdl_exception(std::string description): _what(description) {

}

const char* sdl_exception::what() const {
	return _what.c_str();
}

sdl_init_error::sdl_init_error(std::string description): sdl_exception(description) {

}

sdl_loading_error::sdl_loading_error(std::string description): sdl_exception(description) {

}