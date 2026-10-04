#include "Game.h"


//private functions
void Game::initVariables()
{
	this->nr = 0;
	this->deltaTime = 0.5f ;
	this->menu = nullptr;
	this->window = nullptr;
	this->currentUI = UI::mainMenu;
	this->resolution = sf::VideoMode(1764, 990);
	this->carTexture.loadFromFile("textures/BREAK.png");
	
	this->car = new Car();
	this->level = new Level();
	this->score = 0.f;
}
void Game::initWindow()
{
	this->window = new sf::RenderWindow(resolution, "ATESTAT DEMO", sf::Style::Close | sf::Style::Titlebar);
	this->window->setFramerateLimit(30);
}
void Game::initGameOverWindow()
{
	if (!this->gameOverTexture.loadFromFile("textures/GAMEOVERBUTTON.png"))
	{
		std::cout << "Game::initGameOverWindow::textures: ERROR LOADING TEXTURE FILES!";
	}
	this->gameOverWindow.setTexture(this->gameOverTexture);
	this->gameOverWindow.setOrigin(this->gameOverWindow.getGlobalBounds().getSize().x / 2, this->gameOverWindow.getGlobalBounds().getSize().y / 2);
	this->gameOverWindow.setPosition(882, 495);
	this->gameOverWindow.setScale(10.f, 10.f);
}
void Game::initText()
{
	this->scoreFont.loadFromFile("fonts/Minecraftia-Regular.ttf");
	this->scoreText.setFont(this->scoreFont);
	
	this->scoreText.setOutlineColor(sf::Color::Black);
	this->scoreText.setOutlineThickness(2.f);
	this->scoreText.setFillColor(sf::Color::White);
	this->scoreText.setString("NONE");
	this->scoreText.setOrigin(this->scoreText.getGlobalBounds().getSize().x , this->scoreText.getGlobalBounds().getSize().y / 2);
	this->scoreText.setPosition(882-160, 495-50);
	this->scoreText.setCharacterSize(60.f);
}
//Constructors destructors
Game::Game()
{
	this->initVariables();
	this->menu = new MainMenu(this->resolution);
	this->initWindow();
	this->initGameOverWindow();
	this->initText();
}

Game::~Game()
{
	delete this->window;
	delete this->menu;
	delete this->car;
}
const bool Game::isRunning() const
{
	return this->window->isOpen();
}

void Game::updateMousePos()
{
	this->mousePos = sf::Mouse::getPosition(*this->window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePos);
}



void Game::pollEvents()
{
	//Event polling
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			this->window->close();
			break;
		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
			{
				if (this->currentUI == UI::mainMenu)
					this->window->close();
				else
				{
					this->currentUI = UI::mainMenu;
					this->menu->setReportedUI(UI::mainMenu);
					this->level->resetLevel();
					this->car->resetPos();
				}
			}
			break;

		default:
			break;
		}
	}

}
//Public functions
void Game::update()
{
	this->pollEvents();

	//mouse pos
	this->updateMousePos();


	switch (this->currentUI)
	{
	case UI::mainMenu:
		this->gameOver = 0;
		this->menu->update(this->mousePosView);
		this->menu->getReportedUI(this->currentUI);
		if (this->currentUI == UI::goToLevel) this->level->resetClock();
		break;
	case UI::goToLevel:
		if(!gameOver)
		this->car->update(this->deltaTime);
		// Car and Parked Cars collision
		for (int i = 0; i <= 13; i++)
		{
			if (this->car->getSprite().getGlobalBounds().intersects(this->level->getSpecificSprite(i).getGlobalBounds()))
			{
				this->car->cancelMovement(deltaTime);
				this->score -= 20.f;
			}
		}
		if (gameOver == 1 || this->level->getEmptySpot().getGlobalBounds().contains(this->car->getSprite().getPosition()))
		{
			
			if (gameOver == 0)
			{
				//calculate score
				this->score += 1000 - this->level->getFloatTime() * 10;
				if (this->score < 0) this->score = 0;
				std::stringstream ss;
				ss << "Score: " << this->score<<"\n Press Escape";
				this->scoreText.setString(ss.str());
			}

			gameOver = 1;
			
		}
		else
			this->level->update();
		break;
	case UI::customisationMenu:
		this->customMenu.update(mousePosView, nr);
		//std::cout << nr;
		switch (nr)
		{
		case 0:
			this->car->changeColor(sf::Color::White);
		break;
		case 1:
			this->car->changeColor(sf::Color::Green);
		break;
		case 2:
			this->car->changeColor(sf::Color::Blue);
		break;
		case 3:
			this->car->changeColor(sf::Color::Red);
		break;
		case 4:
			this->car->changeColor(sf::Color::Black);
		break;
		}
		break;
	}

	//update current UI
	this->menu->getReportedUI(this->currentUI);



	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
		this->car->showCoords();
	}
}

void Game::render()
{
	this->window->clear();

	//draw
	switch (this->currentUI)
	{
	case UI::mainMenu:
		this->menu->render(this->window);
		break;
	case UI::goToLevel:
		this->level->render(this->window);

		this->car->render(this->window);

		if (gameOver)
		{
			this->window->draw(this->gameOverWindow);
			this->window->draw(this->scoreText);
		}
		break;
	case UI::customisationMenu:
		this->customMenu.render(this->window);
		break;
	case UI::closeApplication:
		this->window->close();
		break;
	}
	

	this->window->display();
}
