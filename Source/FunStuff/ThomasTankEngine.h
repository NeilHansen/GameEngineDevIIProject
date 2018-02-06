#pragma once

#include <SFML/window.hpp>
#include <SFML/Graphics.hpp>

class ThomasTankEngine
{
public:
	static void Initialize();
	static void Start();
private:

	static bool IsExciting();
	static void GameLoop();

	enum GameState {UnInitialized, ShowingSplash, Paused, ShowingMenu, Exiting};
	static GameState gameState;

	sf::RenderWindow window;
};



