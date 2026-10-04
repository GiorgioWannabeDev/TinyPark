#pragma once

#include "universal.h"

class CustomMenu
{
private:
	//variables
	sf::Sprite customMenu;
	sf::Texture customMenuTexture;
	sf::Sprite colorButton[5];
	sf::Texture colorButtonTexture[5];
	//functions

	void initVariables();
public:

	void update(sf::Vector2f mousePosView, int &number);

	void render(sf::RenderTarget *target);

	CustomMenu();
	~CustomMenu();
};

