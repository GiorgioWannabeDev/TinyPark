#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"

int main()
{
    //init game engine;
    srand(time(NULL));

    Game game;

    while (game.isRunning())
    {
        //Update

        game.update();


        //Render

        game.render();

    }
}