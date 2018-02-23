#include "ThomasTankDisplay.h"
#include "ThomasTankEngine.h"
#include <iostream>

sf::RenderWindow ThomasTankDisplay::mainWindow;

ThomasTankDisplay::ThomasTankDisplay()
{
}

ThomasTankDisplay::~ThomasTankDisplay()
{
}

void ThomasTankDisplay::Initialize()
{
	ThomasTankDisplay::mainWindow.create(sf::VideoMode(1000, 800, 32), "Engine");
	std::cout << "Display Engine Initialized" << "\n";
}

void ThomasTankDisplay::Draw()
{
	ThomasTankDisplay::mainWindow.clear();

	sf::CircleShape circle = ThomasTankDisplay::MakeCircle(100, 50, sf::Color::Green, sf::Color::Cyan);
	circle.setPosition(150, 150);
	ThomasTankDisplay::mainWindow.draw(circle);
	ThomasTankDisplay::mainWindow.display();

}

sf::CircleShape ThomasTankDisplay::MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(color);

	circle.setOutlineThickness(outlineThickness);
	circle.setOutlineColor(outlineColor);

	return circle;
}
