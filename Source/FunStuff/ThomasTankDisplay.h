#pragma once

#include <list>
#include <Windows.h>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Text.hpp>

#include <stdio.h>
#include <iostream>

//#include "RenderComponent.h"
#include "SceneGraph.h"

class ThomasTankDisplay
{
public:
	ThomasTankDisplay();
	~ThomasTankDisplay();

	static void Initialize(SceneGraph sg);
	static void Draw(SceneGraph sg);
	static void UpdateStatsText(std::string str);

	static sf::RenderWindow mainWindow;
	//static SceneGraph m_sceneGraph;

private:
	static sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor);
};
