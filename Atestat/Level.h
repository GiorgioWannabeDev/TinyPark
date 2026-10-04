#pragma once

#include "universal.h"
#include "ParkedCar.h"

class Level
{
private:
	//Variables
	sf::Clock clock;

	sf::Text timerText;
	sf::Font font;

	sf::Sprite map;
	sf::Texture mapTexture1;
	sf::Vector2f parkedCarPositions[15];
	ParkedCar parkedCars[14];

	//the empty space
	sf::Sprite parkingSpotSprite;
	sf::Texture parkingSpotTexture;
	int emptySpace;


	//Functions
	void initVariables();

	void initText();

	void updateText();


public:

	void update();

	void resetLevel();

	void resetClock();

	const float getFloatTime();

	const sf::Sprite getEmptySpot();

	const sf::Sprite getSpecificSprite(int spriteNumber);

	void render(sf::RenderTarget *target);

	Level();
	~Level();
};

