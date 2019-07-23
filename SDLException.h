#pragma once
#include<exception>
#include<stdexcept>
#include<string>

class sdl_exception : std::exception {
public:
	sdl_exception(std::string description);
	virtual const char* what() const;
private:
	std::string _what;
};

class sdl_init_error : sdl_exception {
public:
	sdl_init_error(std::string description);
};

class sdl_loading_error : sdl_exception {
public:
	sdl_loading_error(std::string description);
};