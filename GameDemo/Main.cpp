#include <iostream>

#include "Game.h"

struct Point
{
    int x;
    int y;

    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
};

int main()
{
    Game game;

    const int speed = 10;
    uint32_t windowWidth = game.GetWindowWidth();
    uint32_t windowHeigth = game.GetWindowHeigth();

    Point windowCenterPoint = Point(windowWidth / 2 * -1, windowHeigth / 2 * -1);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(windowCenterPoint.x + shape.getRadius(), windowCenterPoint.y + shape.getRadius());

    while (game.IsRunning())
    {
        game.Update();
        game.Render();   
    }

    return 0;
}
