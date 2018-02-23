#include "ThomasTankSplash.h"


void ThomasTankSplash::Show(sf::RenderWindow & renderWindow)
{
	sf::Texture image;
	if (image.loadFromFile("../../Assets/Images/ThomasTank.png") != true)
	{
		return;
	}

	sf::Sprite sprite(image);

	// Center Splash Image
	sf::FloatRect imgRect = sprite.getLocalBounds();
	sprite.setOrigin(imgRect.width / 2, imgRect.height / 2);
	sprite.setPosition(sf::Vector2f(1000 / 2.0f, 800 / 2.0f));

	renderWindow.draw(sprite);
	renderWindow.display();

	sf::Event event;

	while (ThomasTankEngine::gameState == ThomasTankEngine::ShowingSplash)
	{
		while (renderWindow.pollEvent(event))
		{
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed)
			{
				ThomasTankEngine::gameState = ThomasTankEngine::Playing;
				return;
			}

		}
	}
}