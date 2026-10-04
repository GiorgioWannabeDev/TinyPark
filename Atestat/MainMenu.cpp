#include "MainMenu.h"

void MainMenu::initVariables(sf::VideoMode videoMode)
{
	//load textures
	if (!(this->customButtonTexture.loadFromFile("textures/CUSTOMBUTTON.png") &&
		this->exitButtonTexture.loadFromFile("textures/CLOSEBUTTON.png") &&
		this->playButtonTexture.loadFromFile("textures/PLAYBUTTON.png") &&
		this->logoTexture.loadFromFile("textures/LOGO.png") &&
		this->backgroundTexture.loadFromFile("textures/BG.png")))
	{
		std::cout << "MainMenu::initVariables::textures: ERROR LOADING TEXTURE FILES!";
	}

	//set texture
	this->exitButton.setTexture(this->exitButtonTexture);
	this->playButton.setTexture(this->playButtonTexture);
	this->customButton.setTexture(this->customButtonTexture);
	this->logo.setTexture(this->logoTexture);
	this->background.setTexture(this->backgroundTexture);

	//set origin
	this->exitButton.setOrigin(this->exitButton.getGlobalBounds().getSize().x / 2, this->exitButton.getGlobalBounds().getSize().y / 2);
	this->playButton.setOrigin(this->playButton.getGlobalBounds().getSize().x / 2, this->playButton.getGlobalBounds().getSize().y / 2);
	this->customButton.setOrigin(this->customButton.getGlobalBounds().getSize().x / 2, this->customButton.getGlobalBounds().getSize().y / 2);
	this->logo.setOrigin(this->logo.getGlobalBounds().getSize().x / 2, this->logo.getGlobalBounds().getSize().y / 2);


	//set scale
	this->exitButton.setScale(2, 2);
	this->customButton.setScale(2, 2);
	this->playButton.setScale(2, 2);
	this->logo.setScale(7, 7);
	this->background.setScale(3, 3);

	//set position
	this->playButton.setPosition(videoMode.width / 2 , videoMode.height / 2+200);
	this->exitButton.setPosition(videoMode.width / 2 + this->exitButton.getGlobalBounds().width + 10, videoMode.height / 2+200);
	this->customButton.setPosition(videoMode.width / 2 - this->customButton.getGlobalBounds().width - 10, videoMode.height / 2+200);
	this->logo.setPosition(videoMode.width / 2, videoMode.height / 2 - 150);
	this->background.setPosition(0, 0);

	//reported UI
	this->reportedUI = UI::mainMenu;

}


void MainMenu::getReportedUI(UI &ui)
{
	ui = this->reportedUI;
}

void MainMenu::setReportedUI(UI ui)
{
	this->reportedUI = ui;
}

void MainMenu::update(sf::Vector2f mousePosView)
{
	this->updateButtons(mousePosView);
}

void MainMenu::updateButtons(sf::Vector2f mousePosView)
{
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (this->playButton.getGlobalBounds().contains(mousePosView))
		{
			reportedUI = UI::goToLevel;
		}
		else if (this->exitButton.getGlobalBounds().contains(mousePosView))
		{
			reportedUI = UI::closeApplication;
		}
		else if (this->customButton.getGlobalBounds().contains(mousePosView))
		{
			reportedUI = UI::customisationMenu;
		}
	}
}

void MainMenu::render(sf::RenderTarget* target)
{
	target->draw(this->background);
	target->draw(this->playButton);
	target->draw(this->customButton);
	target->draw(this->exitButton);
	target->draw(this->logo);

}

MainMenu::MainMenu(sf::VideoMode res)
{
	this->initVariables(res);

}

MainMenu::~MainMenu()
{

}
