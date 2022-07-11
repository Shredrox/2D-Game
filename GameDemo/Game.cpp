#include "Game.h"

void Game::InitVariables()
{
	this->m_Window = nullptr;
}

void Game::InitWindow()
{
	this->m_VideoMode.height = 720;
	this->m_VideoMode.width = 1280;
	this->m_Window = new sf::RenderWindow(this->m_VideoMode, "2D SFML Game", sf::Style::Titlebar | sf::Style::Close);
	this->m_Window->setFramerateLimit(65);
}

Game::Game()
{
	this->InitVariables();
	this->InitWindow();
}

Game::~Game()
{
	delete this->m_Window;
}

void Game::PollEvents()
{
    sf::Event event;
    while (this->m_Window->pollEvent(this->m_Event))
    {
        if (this->m_Event.type == sf::Event::Closed)
            this->m_Window->close();
    }

    //if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //{
    //    shape.move(0.5f * speed / 1.5f, -0.5f * speed / 1.5f);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //{
    //    shape.move(-0.5f * speed / 1.5f, -0.5f * speed / 1.5f);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A) && sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //{
    //    shape.move(-0.5f * speed / 1.5f, 0.5f * speed / 1.5f);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S) && sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //{
    //    shape.move(0.5f * speed / 1.5f, 0.5f * speed / 1.5f);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    //{
    //    shape.move(0.f, -0.5f * speed);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    //{
    //    shape.move(0.f, 0.5f * speed);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
    //{
    //    shape.move(-0.5f * speed, 0.f);
    //}
    //else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
    //{
    //    shape.move(0.5f * speed, 0.f);
    //}
}

void Game::Update()
{
    this->PollEvents();
    
}

void Game::Render()
{
    this->m_Window->clear(sf::Color(0,0,100,255));
    //this->m_Window->draw();
    this->m_Window->display();
}

const bool Game::IsRunning() const
{
	return this->m_Window->isOpen();
}

const uint32_t Game::GetWindowWidth()
{
	return this->m_Window->getSize().x;
}

const uint32_t Game::GetWindowHeigth()
{
	return this->m_Window->getSize().y;
}
