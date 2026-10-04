#pragma once

#include "universal.h"
#include "MainMenu.h"
#include "Car.h"
#include "Level.h"
#include "CustomMenu.h"

class Game
{
	public:

	private:
		//variables
		MainMenu *menu;
		sf::Texture carTexture;
		float deltaTime;
		Car* car;
		Level* level;
		CustomMenu customMenu;
		int nr;
		
		//Game over
		bool gameOver;
		sf::Sprite gameOverWindow;
		sf::Texture gameOverTexture;
		float score;
		sf::Text scoreText;
		sf::Font scoreFont;

		//mouse pos
		sf::Vector2i mousePos;
		sf::Vector2f mousePosView;

		//window
		sf::RenderWindow* window;
		sf::VideoMode resolution;


		//events
		sf::Event ev;

		//private functions
		void initVariables();
		void initWindow();
		void initGameOverWindow();
		void initText();
		//Game Logic
		
		UI currentUI;


	public:
		//public variables
		

		//Constructors/Destructors
		Game();
		~Game();

		//accessors
		const bool isRunning() const;

		//Functions
		
		void updateMousePos();


		//Main menu


		void pollEvents();
		void update();
		void render();
};

