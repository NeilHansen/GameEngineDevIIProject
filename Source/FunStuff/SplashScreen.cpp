#include "SplashScreen.h"
#include <SFML/Window.hpp>

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
	sf::Image image;
	if (image.loadFromFile("Assets/Images/turmp.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);


	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;
	
	while (_gameState != EngineName::Initialized)
	{
		while (renderWindow.GetEvent(event)) 
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