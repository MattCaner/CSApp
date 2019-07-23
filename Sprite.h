#pragma once
#include"Panel.h"
#include"Utilities.h"
#include"AppState.h"
#include"CSApp_basic.h"

class Drawable {
public:
	Drawable(TextureArray* ta, int index = 0);
	virtual void Draw() = 0;
	virtual void SetTextureNumber(int index);
	virtual void SetTextureArray(TextureArray* ta);
	virtual int GetTextureIndex() const;
protected:
	TextureArray* getTextureArray() const;
	SDL_Texture* getCurrentTexture() const;
private:
	TextureArray* _textures;
	int _index = 0;
};

class SpriteExtension;

class Sprite : public Drawable {
public:

	Sprite(Panel* panel, TextureArray* textures, float sizeX, float sizeY, float posX, float posY);

	Sprite(Panel* panel, TextureArray* textures, int sizeX, int sizeY, int posX, int posY);

	virtual void Draw();

	v2d GetFloatPosition() const;
	v2di GetIntPosition() const;

	void SetPosition(v2d v);
	void SetPosition(v2di v);


	SDL_Rect GetLimits() const;

	void makeButton(std::function<void(SDL_Event* e)> onClick);
	void addTextField(wstring text, TTF_Font* font, SDL_Color color, bool wrapText = true);

private:

	Panel* _panel;

	int _sizeX;
	int _sizeY;
	int _posX;
	int _posY;

	vector<SpriteExtension*> _extensions;

};