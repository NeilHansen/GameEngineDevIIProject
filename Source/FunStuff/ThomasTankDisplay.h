#pragma once

#include <list>
#include <Windows.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

#include <stdio.h>
#include <iostream>

#include "RenderComponent.h"

class ThomasTankDisplay
{
public:
	ThomasTankDisplay();
	~ThomasTankDisplay();

	static void Initialize();
	static void Draw(std::list<RenderComponent> rcs);
	static void UpdateStatsText(std::string str);

	static sf::RenderWindow mainWindow;

private:
	static sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor);
};
