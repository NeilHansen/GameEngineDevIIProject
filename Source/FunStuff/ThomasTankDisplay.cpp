#include "ThomasTankDisplay.h"
#include "ThomasTankEngine.h"


// Window
sf::RenderWindow ThomasTankDisplay::mainWindow;

// scene graph
//SceneGraph ThomasTankDisplay::m_sceneGraph;

// Stats text
sf::Font statsFont;
sf::Text statsText;

ThomasTankDisplay::ThomasTankDisplay()
{
}

ThomasTankDisplay::~ThomasTankDisplay()
{
}

void ThomasTankDisplay::Initialize(SceneGraph sg)
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

void ThomasTankDisplay::Draw(SceneGraph sg)
{
	ThomasTankDisplay::mainWindow.clear();

	int drawCount = 0;

	std::list<RenderComponent*> rcs = sg.renderComponents;
	//std::cout << "rcs to draw: " << sg.renderComponents.size() << std::endl;

	for (std::list<RenderComponent*>::iterator it = rcs.begin(); it != rcs.end(); it++)
	{
		//std::cout << "draw: " << drawCount++ << std::endl;
		ThomasTankDisplay::mainWindow.draw((*it)->m_sprite);
	}

	//std::cout << "draw: " << drawCount++ << std::endl;
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
