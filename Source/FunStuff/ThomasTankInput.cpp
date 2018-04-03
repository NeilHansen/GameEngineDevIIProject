#include "ThomasTankInput.h"
#include <iostream>


void ThomasTankInput::Initialize()
{
	std::cout << "Input System Initialized" << "\n";
}

void ThomasTankInput::ProcessInput()
{
	sf::Event event;
	while (ThomasTankDisplay::mainWindow.pollEvent(event))
	{
		// Check for window close
		if (event.type == sf::Event::Closed)
		{
			//Quit; not working
			ThomasTankDisplay::mainWindow.close();
		}
		//Splash Screen input
		if (ThomasTankEngine::gameState == ThomasTankEngine::ShowingSplash)
		{
			if (event.type == sf::Event::EventType::KeyPressed ||
				event.type == sf::Event::EventType::MouseButtonPressed ||
				event.type == sf::Event::EventType::Closed)
			{
				ThomasTankEngine::gameState = ThomasTankEngine::Playing;
				std::cout << "Input on splash" << "\n";
				return;
			}
		}
		if (ThomasTankEngine::gameState == ThomasTankEngine::Playing)
		{
			//mouse input
			if (event.type == sf::Event::EventType::MouseButtonPressed)
			{
				if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
				{
					
					std::cout << "Mouse Button Right" << "\n";
					ThomasTankAudio::PlaySfx("cha-ching.wav");
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					std::cout << "Mouse Button Left" << "\n";
				}
			}
			//Keyboard Input
			else if (event.type == sf::Event::EventType::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					MoveUp();
					std::cout << "W" << "\n";
				}
				if (event.key.code == sf::Keyboard::S)
				{
					MoveDown();
					std::cout << "S" << "\n";
				}
				if (event.key.code == sf::Keyboard::A)
				{
					MoveLeft();
					std::cout << "A" << "\n";
				}
				if (event.key.code == sf::Keyboard::D)
				{
					MoveRight();
					std::cout << "D" << "\n";
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					std::cout << "SPACE" << "\n";
				}
			}
		}
	}
}

void ThomasTankInput::MoveUp()
{
	ThomasTankEngine::MovePlayer(Vector2(0.0f, -1.0f));
}

void ThomasTankInput::MoveDown()
{
	ThomasTankEngine::MovePlayer(Vector2(0.0f, 1.0f));
}

void ThomasTankInput::MoveLeft()
{
	ThomasTankEngine::MovePlayer(Vector2(-1.0f, 0.0f));
}

void ThomasTankInput::MoveRight()
{
	ThomasTankEngine::MovePlayer(Vector2(1.0f, 0.0f));
}
