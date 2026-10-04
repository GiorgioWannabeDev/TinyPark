#include "Car.h"

void Car::initVariables()
{
	//init texture
	this->texture.loadFromFile("textures/BREAK.png");
	this->sprite.setTexture(this->texture);
	this->sprite.setPosition(400.f, 400.f);

	this->velocity = 0.f;
	this->position = sf::Vector2f(400.f, 400.f);
	this->acceleration = 0.f;
	this->carAngle = 0.f;
	this->steering = 0.f;
	this->maxAcceleration = 10.f;
	this->maxVelocity = 30.f;
	this->maxSteering = 45.f;
	this->brakeDeceleration = 30.f;
	this->freeDeceleration = 8.f;
	this->sprite.setOrigin(this->sprite.getGlobalBounds().width / 2, this->sprite.getGlobalBounds().height/2);
	this->sprite.setScale(6, 6);
	this->size.x = this->sprite.getGlobalBounds().width;
	this->size.y = this->sprite.getGlobalBounds().height;

}

void Car::cancelMovement(float dt)
{
	//Update angle
	this->carAngle -= angularVelocity * 180.f / 3.14f * dt;

	//Update position

	float radianAngle = radian(this->carAngle);

	sf::Vector2f direction(std::cos(radianAngle), std::sin(radianAngle));
	this->position -= direction * this->velocity * dt;

	this->sprite.setPosition(this->position);
	this->sprite.setRotation(this->carAngle);
}

const sf::Sprite Car::getSprite() const
{
	return this->sprite;
}


const float Car::radian(float n) const
{
	return n * 3.14 / 180.f;
}

Car::Car()
{
	this->initVariables();
}

Car::~Car()
{
}

void Car::changeColor(sf::Color newColor)
{
	this->sprite.setColor(newColor);
}

void Car::update(float dt)
{
	this->updateMotion(dt);

	//Update velocity

	this->velocity += this->acceleration * dt;
	this->velocity = std::max(-this->maxVelocity, std::min(this->maxVelocity, this->velocity));

	//Angular velocity
	angularVelocity = 0.f;
	if (this->steering != 0.f)
	{
		float turningRadius = this->size.x / std::sin(radian(this->steering));
		angularVelocity = this->velocity / turningRadius;
	}

	

	//Update position
	float radianAngle = radian(this->carAngle);
	sf::Vector2f direction(std::cos(radianAngle), std::sin(radianAngle));
	this->position += direction * this->velocity * dt;

	//Update angle
	this->carAngle += angularVelocity * 180.f / 3.14f * dt;

	this->sprite.setPosition(this->position);
	this->sprite.setRotation(this->carAngle);

	if (this->sprite.getGlobalBounds().getPosition().x < 0 ||
		this->sprite.getGlobalBounds().getPosition().y < 0 ||
		this->sprite.getGlobalBounds().getPosition().x + this->sprite.getGlobalBounds().getSize().x > 1764 ||
		this->sprite.getGlobalBounds().getPosition().y + this->sprite.getGlobalBounds().getSize().y > 990)
	{
		this->cancelMovement(dt);
	}
}

void Car::updateMotion(float dt)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) || sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		if (this->velocity < 0) this->acceleration = this->brakeDeceleration;
		else
			this->acceleration += 1.0 * dt;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) || sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		if (this->velocity > 0) this->acceleration = -this->brakeDeceleration;
		else
			this->acceleration -= 1.0 * dt;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		if (std::abs(this->velocity) > dt * this->brakeDeceleration)
		{
			this->acceleration = -std::copysign(this->brakeDeceleration, this->velocity);
		}
		else
		{
			this->acceleration = -this->velocity / dt;
		}
	}
	else //free deceleration if no acceleration changes happen
	{
		if (std::abs(this->velocity) > dt * this->freeDeceleration)
		{
			this->acceleration = -std::copysign(this->freeDeceleration, this->velocity);
		}
		else
		{
			this->acceleration = -this->velocity / dt;
		}
	}

	this->acceleration = std::max(-this->maxAcceleration, std::min(this->maxAcceleration, this->acceleration));

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		this->steering -= 30.f * dt;
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		this->steering += 30.f * dt;
	}
	else this->steering = 0.f;

	this->steering = std::max(-this->maxSteering, std::min(this->maxSteering, this->steering));

}

void Car::render(sf::RenderTarget *target)
{
	target->draw(this->sprite);
}

void Car::resetPos()
{
	this->velocity = 0.f;
	this->position = sf::Vector2f(400.f, 400.f);
	this->acceleration = 0.f;
	this->carAngle = 0.f;
	this->steering = 0.f;
}

void Car::showCoords()
{
	std::cout << this->sprite.getPosition().x << ' ' << this->sprite.getPosition().y << '\n';
}
