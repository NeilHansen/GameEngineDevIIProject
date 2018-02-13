#pragma once

#include <Windows.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

class ThomasTankDisplay
{
public:
	ThomasTankDisplay();
	~ThomasTankDisplay();
	static void Initialize();
	static void Update();
	static sf::RenderWindow mainWindow;

private:
	static sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor);
};
