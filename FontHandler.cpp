#include"FontHandler.h"

Font::Font(): _currentFont(nullptr), _size(0) {

}

Font::Font(const char* sourcepath, int size): _size(size) {
	_currentFont = TTF_OpenFont(sourcepath, size);
	if (_currentFont == nullptr) throw sdl_loading_error("Font from path: " + std::string(sourcepath) + " was not loaded succesfully.");
}

TTF_Font* Font::GetFont() {


}