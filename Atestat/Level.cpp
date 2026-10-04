#include "Level.h"

void Level::initVariables()
{
	int j = 0;
	//load texture
	if (!this->mapTexture1.loadFromFile("textures/MAP1.png"))
	{
		std::cout << "Level::initVariables::textures: ERROR LOADING TEXTURE FILES!";
	}
	if (!this->parkingSpotTexture.loadFromFile("textures/FINISH.png"))
	{
		std::cout << "Level::initVariables::textures: ERROR LOADING TEXTURE FILES!";
	}
	this->map.setTexture(this->mapTexture1);
	this->map.setScale(9, 9);
	this->emptySpace = rand() % 15;
	
	sf::Vector2f parkedCarPositions[15] = {sf::Vector2f(206.f,857.f),
										   sf::Vector2f(206.f,713.f),
										   sf::Vector2f(781.f,857.f),
										   sf::Vector2f(781.f,713.f),
										   sf::Vector2f(152.f,178.f),
										   sf::Vector2f(300.f,178.f),
										   sf::Vector2f(441.f,178.f),
										   sf::Vector2f(582.f,178.f),
										   sf::Vector2f(729.f,178.f),
										   sf::Vector2f(875.f,178.f),
										   sf::Vector2f(1019.f,178.f),
										   sf::Vector2f(1158.f,178.f),
										   sf::Vector2f(1310.f,178.f),
										   sf::Vector2f(1450.f,178.f),
										   sf::Vector2f(1590.f,178.f)};

	this->parkingSpotSprite.setTexture(this->parkingSpotTexture);
	this->parkingSpotSprite.setOrigin(this->parkingSpotSprite.getGlobalBounds().width / 2, this->parkingSpotSprite.getGlobalBounds().height / 2);
	this->parkingSpotSprite.setScale(3.f, 3.f);

	for (int i = 0; i <= 14; i++)
	{

		if (i == emptySpace)
		{
			if (i <= 3)this->parkingSpotSprite.setRotation(90.f);
			this->parkingSpotSprite.setPosition(parkedCarPositions[emptySpace]);
			continue;
		}

		parkedCars[j].setPosition(parkedCarPositions[i]);
		j++;
		if (i > 3)
		{
			parkedCars[j].setRotation(90.f);
		}

		
	}
	
	
	this->initText();

}

void Level::initText()
{
	if (!this->font.loadFromFile("fonts/Minecraftia-Regular.ttf"))
	{
		std::cout << "Level::initText::fonts: ERROR LOADING FONT FILES!";
	}

	this->timerText.setFont(this->font);
	this->timerText.setCharacterSize(50);
	this->timerText.setFillColor(sf::Color::White);
	this->timerText.setString("NONE");
	this->timerText.setPosition(20, 30);
	this->timerText.setOutlineColor(sf::Color::Black);
	this->timerText.setOutlineThickness(2.f);
}

void Level::updateText()
{
	std::stringstream ss;
	
	ss << "Time elapsed: " <<std::fixed<<std::setprecision(2)<< clock.getElapsedTime().asSeconds();

	this->timerText.setString(ss.str());
}

void Level::update()
{
	this->updateText();
}

void Level::resetLevel()
{
	for (int i = 0; i <= 13; i++)
	{
		this->parkedCars[i].reinit();
	}

	int j = 0;
	//load texture
	if (!this->mapTexture1.loadFromFile("textures/MAP1.png"))
	{
		std::cout << "Level::initVariables::textures: ERROR LOADING TEXTURE FILES!";
	}
	if (!this->parkingSpotTexture.loadFromFile("textures/FINISH.png"))
	{
		std::cout << "Level::initVariables::textures: ERROR LOADING TEXTURE FILES!";
	}
	this->map.setTexture(this->mapTexture1);
	this->map.setScale(9, 9);
	this->emptySpace = rand() % 15;

	sf::Vector2f parkedCarPositions[15] = { sf::Vector2f(206.f,857.f),
										   sf::Vector2f(206.f,713.f),
										   sf::Vector2f(781.f,857.f),
										   sf::Vector2f(781.f,713.f),
										   sf::Vector2f(152.f,178.f),
										   sf::Vector2f(300.f,178.f),
										   sf::Vector2f(441.f,178.f),
										   sf::Vector2f(582.f,178.f),
										   sf::Vector2f(729.f,178.f),
										   sf::Vector2f(875.f,178.f),
										   sf::Vector2f(1019.f,178.f),
										   sf::Vector2f(1158.f,178.f),
										   sf::Vector2f(1310.f,178.f),
										   sf::Vector2f(1450.f,178.f),
										   sf::Vector2f(1590.f,178.f) };

	

	for (int i = 0; i <= 14; i++)
	{

		if (i == emptySpace)
		{
			if (i <= 3)this->parkingSpotSprite.setRotation(90.f);
			this->parkingSpotSprite.setPosition(parkedCarPositions[emptySpace]);
			continue;
		}

		parkedCars[j].setPosition(parkedCarPositions[i]);
		j++;
		if (i >= 3)
		{
			parkedCars[j].setRotation(90.f);
		}


	}

	
	this->initText();


}

void Level::resetClock()
{
	this->clock.restart();
}

float Level::getFloatTime()
{
	return this->clock.getElapsedTime().asSeconds();
}

const sf::Sprite Level::getEmptySpot()
{
	return this->parkingSpotSprite;
}

const sf::Sprite Level::getSpecificSprite(int spriteNumber)
{
	return this->parkedCars[spriteNumber].getSprite();
}

void Level::render(sf::RenderTarget* target)
{
	target->draw(this->map);
	for (int i = 0; i <= 13; i++)
	{
		this->parkedCars[i].render(target);
	}
	target->draw(this->timerText);
	//target->draw(this->parkingSpotSprite);
}

Level::Level()
{
	this->initVariables();
}

Level::~Level()
{

}
