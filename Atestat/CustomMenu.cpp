#include "CustomMenu.h"

void CustomMenu::initVariables()
{
	if (!this->customMenuTexture.loadFromFile("textures/GAMEOVERBUTTON.png"))
	{
		std::cout << "CustomMenu::initVariables::textures: ERROR LOADING TEXTURE FILES!";
	}
	this->customMenu.setTexture(this->customMenuTexture);
	this->customMenu.setOrigin(this->customMenu.getGlobalBounds().getSize().x / 2, this->customMenu.getGlobalBounds().getSize().y / 2);
	this->customMenu.setScale(12.f, 12.f);
	this->customMenu.setPosition(882, 495);

	this->colorButtonTexture[0].loadFromFile("textures/WHITE.png");
	this->colorButtonTexture[1].loadFromFile("textures/GREEN.png");
	this->colorButtonTexture[2].loadFromFile("textures/BLUE.png");
	this->colorButtonTexture[3].loadFromFile("textures/RED.png");
	this->colorButtonTexture[4].loadFromFile("textures/BLACK.png");

	for (int i = 0; i <= 4; i++)
	{
		this->colorButton[i].setTexture(this->colorButtonTexture[i]);
		this->colorButton[i].setOrigin(this->colorButton[i].getGlobalBounds().getSize().x / 2, this->colorButton[i].getGlobalBounds().getSize().y / 2);
		this->colorButton[i].setScale(2.f, 2.f);
		if (i <= 2)
			this->colorButton[i].setPosition(882 + 220 * i, 495);
		else
			this->colorButton[i].setPosition(882 + (-(5-i))*220, 495);
	}
}

void CustomMenu::update(sf::Vector2f mousePosView, int &number)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->colorButton[0].getGlobalBounds().contains(mousePosView))
		{
			//std::cout << "WHITE";
			number = 0;
		}
		if (this->colorButton[1].getGlobalBounds().contains(mousePosView))
		{
			//std::cout << "GREEN";
			number = 1;
		}
		if (this->colorButton[2].getGlobalBounds().contains(mousePosView))
		{
			//std::cout << "BLUE";
			number = 2;
		}
		if (this->colorButton[3].getGlobalBounds().contains(mousePosView))
		{
			//std::cout << "RED";
			number = 3;
		}
		if (this->colorButton[4].getGlobalBounds().contains(mousePosView))
		{
			//std::cout << "BLACK";
			number = 4;
		}
	}

}

void CustomMenu::render(sf::RenderTarget* target)
{
	target->draw(this->customMenu);

	for (int i = 0; i <= 4; i++)
	{
		target->draw(this->colorButton[i]);
	}
}

CustomMenu::CustomMenu()
{
	this->initVariables();
}

CustomMenu::~CustomMenu()
{
}
