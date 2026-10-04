#include "ParkedCar.h"

void ParkedCar::initVariables()
{
	this->initTexture();
	this->sprite.setTexture(this->texture);
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height / 2);
	this->sprite.setScale(6, 6);
	this->size.x = this->sprite.getGlobalBounds().width;
	this->size.y = this->sprite.getGlobalBounds().height;

	this->sprite.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

void ParkedCar::initTexture()
{
	if (!this->texture.loadFromFile(textureNames[rand() % 3]))
	{
		std::cout << "ParkedCar::initTexture::textures: ERROR LOADING TEXTURE FILES!";
	}
}

void ParkedCar::setPosition(sf::Vector2f newPos)
{
	this->sprite.setPosition(newPos);
}

void ParkedCar::setRotation(float rotation)
{
	this->sprite.setRotation(rotation);
}

void ParkedCar::reinit()
{
	if (!this->texture.loadFromFile(textureNames[rand() % 3]))
	{
		std::cout << "ParkedCar::initTexture::textures: ERROR LOADING TEXTURE FILES!";
	}
	this->sprite.setColor(sf::Color(rand() % 255, rand() % 255, rand() % 255));
}

const sf::Sprite ParkedCar::getSprite() const
{
	return this->sprite;
}

void ParkedCar::update()
{

}

void ParkedCar::render(sf::RenderTarget* target)
{
	target->draw(this->sprite);
}

ParkedCar::ParkedCar()
{
	this->initVariables();
}

ParkedCar::~ParkedCar()
{

}
