#include <SFML/Graphics.hpp>

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
    sf::RenderWindow window(sf::VideoMode(1280, 720), "SFML game!", sf::Style::Titlebar | sf::Style::Close);
    window.setFramerateLimit(65);

    const int speed = 10;
    uint32_t windowWidth = window.getSize().x;
    uint32_t windowHeigth = window.getSize().y;

    Point windowCenterPoint = Point(windowWidth / 2 * -1, windowHeigth / 2 * -1);

    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Yellow);
    shape.setOrigin(windowCenterPoint.x + shape.getRadius(), windowCenterPoint.y + shape.getRadius());

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape.move(0.5f * speed / 1.5f, -0.5f * speed / 1.5f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            shape.move(-0.5f * speed / 1.5f, -0.5f * speed / 1.5f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shape.move(-0.5f * speed / 1.5f, 0.5f * speed / 1.5f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape.move(0.5f * speed / 1.5f, 0.5f * speed / 1.5f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
        {
            shape.move(0.f, -0.5f * speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
        {
            shape.move(0.f, 0.5f * speed);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            shape.move(-0.5f * speed, 0.f);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            shape.move(0.5f * speed, 0.f);
        }

        window.clear();
        window.draw(shape);
        window.display();   
    }

    return 0;
}
