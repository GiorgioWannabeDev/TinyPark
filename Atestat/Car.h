#pragma once

#include "universal.h"
#include <cmath>

class Car
{
private:
	//Variables

	//Car properties
	sf::Sprite sprite;
	sf::Texture texture;
	sf::Vector2f position;
	sf::Vector2f size;
	float carAngle;
	float velocity;
	float acceleration;
	float steering;
	float angularVelocity;

	//Constants
	float maxVelocity;
	float maxAcceleration;
	float freeDeceleration;
	float brakeDeceleration;
	float maxSteering;

	//Functions
	void initVariables();
public:
	//Public functions
	void cancelMovement(float dt);

	const sf::Sprite getSprite() const;

	//radian converter
	float radian(float n) const;

	Car();
	~Car();

	void changeColor(sf::Color newColor);

	void update(float dt);

	void updateMotion(float dt);

	void render(sf::RenderTarget *target);

	void resetPos();

	//temp

	void showCoords();
};

