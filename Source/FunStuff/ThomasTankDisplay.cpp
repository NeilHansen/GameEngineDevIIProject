#include "ThomasTankDisplay.h"
#include "ThomasTankEngine.h"

#include<stdio.h>
#include <iostream>

// Window
sf::RenderWindow ThomasTankDisplay::mainWindow;

// Stats text
sf::Font statsFont;
sf::Text statsText;

ThomasTankDisplay::ThomasTankDisplay()
{
}

ThomasTankDisplay::~ThomasTankDisplay()
{
}

void ThomasTankDisplay::Initialize()
{
	// Create window
	ThomasTankDisplay::mainWindow.create(sf::VideoMode(1000, 800, 32), "Engine");
	ThomasTankDisplay::mainWindow.setFramerateLimit(60);

	// Create stats text
	statsFont.loadFromFile("../../Assets/Fonts/LemonMilk.otf");
	statsText.setFont(statsFont);
	statsText.setPosition(1.0f, 1.0f);
	statsText.setCharacterSize(20);
	statsText.setFillColor(sf::Color::Green);

	std::cout << "Display Engine Initialized" << "\n";
}

void ThomasTankDisplay::Draw()
{
	ThomasTankDisplay::mainWindow.clear();

	sf::CircleShape circle = ThomasTankDisplay::MakeCircle(100, 50, sf::Color::Green, sf::Color::Cyan);
	circle.setPosition(150, 150);

	ThomasTankDisplay::mainWindow.draw(circle);
	ThomasTankDisplay::mainWindow.draw(statsText);

	ThomasTankDisplay::mainWindow.display();
}

void ThomasTankDisplay::UpdateStatsText(std::string str)
{
	statsText.setString(str);
}

sf::CircleShape ThomasTankDisplay::MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(color);

	circle.setOutlineThickness(outlineThickness);
	circle.setOutlineColor(outlineColor);

	return circle;
}
