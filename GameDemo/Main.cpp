#include <iostream>

#include "Game.h"

int main()
{
    Game game;

    //game loop
    while (game.IsRunning())
    {
        game.Update();
        game.Render();   
    }

    return 0;
}
