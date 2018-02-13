#include "SplashScreen.h"
#include <SFML/Window.hpp>
#include "ThomasTankEngine.h"

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("Assets/Images/ThomasTank.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);


	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	
	while(ThomasTankEngine::gameState != ThomasTankEngine::ShowingSplash )
	{
		while (renderWindow.pollEvent(event)) 
		{
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed)
			{
				return;
			}

		}
	}
}