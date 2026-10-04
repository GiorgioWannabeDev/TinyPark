#pragma once

#include "universal.h"

class MainMenu
{
private:
	//private variables
	sf::Sprite playButton,exitButton,customButton,logo,background;
	sf::Texture playButtonTexture, exitButtonTexture, customButtonTexture, logoTexture,backgroundTexture;
	UI reportedUI;

	//private functions
	void initVariables(sf::VideoMode res);


public:

	void getReportedUI(UI& ui);

	void setReportedUI(UI ui);

	void update(sf::Vector2f mousePosView);

	void updateButtons(sf::Vector2f mousePosView);

	void render(sf::RenderTarget *target);

	MainMenu(sf::VideoMode res);
	~MainMenu();

};

