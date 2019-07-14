#include "TextureArray.h"
#include "AppState.h"

TextureArray::TextureArray() {

}

TextureArray::TextureArray(SDL_Texture* firstOne) {
	_textures.push_back(firstOne);
}

void TextureArray::addTexture(SDL_Texture* toAdd) {
	_textures.push_back(toAdd);
}


SDL_Texture* TextureArray::operator[](int indx) const {
	return _textures[indx];
}


SDL_Texture* loadFromFile(std::string from){
	SDL_Texture* toReturn = nullptr;
	SDL_Surface* loadedSurface = IMG_Load(from.c_str());
	if (loadedSurface == NULL) {

	}
	else{

		toReturn = SDL_CreateTextureFromSurface(AppState::Get().GetRenderer(), loadedSurface);
		if (toReturn == NULL)
		{
			cout << "Error while loading image." << endl;
		}

		SDL_FreeSurface(loadedSurface);
	}

	cout << "Texture from path: " << from << " loaded sucessfully." << endl;

	return toReturn;
}