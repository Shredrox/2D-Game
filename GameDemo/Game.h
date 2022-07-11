#pragma once

#include <iostream>

#include <SFML/Graphics.hpp>

class Game
{
private:
	//window
	sf::RenderWindow* m_Window;
	sf::VideoMode m_VideoMode;
	sf::Event m_Event;
	uint32_t m_WindowWidth;
	uint32_t m_WindowHeigth;

	//objects
	sf::CircleShape m_Player;
	sf::RectangleShape m_Enemy;

	//game var
	const int m_Speed = 10;
	
	void InitVariables();
	void InitWindow();
	void InitPlayer();
	void InitEnemies();

public:
	Game();
	~Game();

	void Start();
	void PollEvents();
	void Update();
	void Render();

	const bool IsRunning() const;
	const uint32_t GetWindowWidth();
	const uint32_t GetWindowHeigth();
};

