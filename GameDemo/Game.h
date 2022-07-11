#pragma once

#include <SFML/Graphics.hpp>

class Game
{
private:
	sf::RenderWindow* m_Window;
	sf::VideoMode m_VideoMode;
	sf::Event m_Event;

	void InitVariables();
	void InitWindow();

public:
	Game();
	~Game();

	void PollEvents();
	void Update();
	void Render();

	const bool IsRunning() const;
	const uint32_t GetWindowWidth();
	const uint32_t GetWindowHeigth();
};

