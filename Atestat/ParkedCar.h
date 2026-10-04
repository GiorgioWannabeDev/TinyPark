#pragma once

#include "universal.h"

class ParkedCar
{
private:
	//Variables
	char textureNames[3][40] = {"textures/SEDAN.png" , "textures/HATCHBACK.png", "textures/BREAK.png"};
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Vector2f size;

	//private functions
	void initVariables();
	void initTexture();

public:

	void setPosition(sf::Vector2f newPos);
	void setRotation(float rotation);

	void reinit();

	const sf::Sprite getSprite() const;

	void update();

	void render(sf::RenderTarget *target);

	ParkedCar();
	~ParkedCar();
};

