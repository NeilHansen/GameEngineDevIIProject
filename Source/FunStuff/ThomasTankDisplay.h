#pragma once

#include <Windows.h>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

class ThomasTankDisplay
{
public:
	ThomasTankDisplay();
	~ThomasTankDisplay();
	static void Initialize();
	static void Draw();
	static void UpdateStatsText(std::string str);

	static sf::RenderWindow mainWindow;
	static sf::RectangleShape player;
private:
	static sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor);
};
