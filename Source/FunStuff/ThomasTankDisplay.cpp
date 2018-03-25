#include "ThomasTankDisplay.h"
#include "ThomasTankEngine.h"


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

void ThomasTankDisplay::Draw(std::list<RenderComponent> rcs)
{
	ThomasTankDisplay::mainWindow.clear();
	/*
	sf::CircleShape circle = ThomasTankDisplay::MakeCircle(100, 50, sf::Color::Green, sf::Color::Cyan);
	// Centers The Circle
	sf::FloatRect circlePar = circle.getLocalBounds();
	circle.setOrigin(circlePar.width / 2, circlePar.height / 2);
	circle.setPosition(1000 / 2, 800 / 2);

	//stuff it tried to test player move - this is just drawing a static object - we'll have to make a visual component er something
	//sf::RectangleShape player(sf::Vector2f(100,100));
	//player.setFillColor(sf::Color::Red);
	//ThomasTankDisplay::mainWindow.draw(player);

	ThomasTankDisplay::mainWindow.draw(circle);
	*/

	for (std::list<RenderComponent>::iterator it =rcs.begin(); it != rcs.end(); it++)
	{
		ThomasTankDisplay::mainWindow.draw(it->m_sprite);
	}

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
