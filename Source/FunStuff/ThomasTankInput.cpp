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
					//std::cout << "Mouse Button Right" << "\n";
				}
				if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
				{
					//std::cout << "Mouse Button Left" << "\n";
				}
			}
			//Keyboard Input - player1
			if (event.type == sf::Event::EventType::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					MoveUp(true);
					//std::cout << "W" << "\n";
				}
				if (event.key.code == sf::Keyboard::S)
				{
					MoveDown(true);
					//std::cout << "S" << "\n";
				}
				
				//player2
				if (event.key.code == sf::Keyboard::Up)
				{
					MoveUp(false);
					//std::cout << "Up" << "\n";
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					MoveDown(false);
					//std::cout << "Down" << "\n";
				}
			}
			if(event.type == sf::Event::EventType::KeyReleased)
			{
				if (event.key.code == sf::Keyboard::W)
				{
					//std::cout << "No input" << std::endl;
					ThomasTankEngine::StopPlayer(true);
				}
				if (event.key.code == sf::Keyboard::S)
				{
					//std::cout << "No input" << std::endl;
					ThomasTankEngine::StopPlayer(true);
				}

				std::cout << "WTF M8" << std::endl;

				//player2
				if (event.key.code == sf::Keyboard::Up)
				{
					//std::cout << "No input" << std::endl;
					ThomasTankEngine::StopPlayer(false);
				}
				if (event.key.code == sf::Keyboard::Down)
				{
					//std::cout << "No input" << std::endl;
					ThomasTankEngine::StopPlayer(false);
				}
			}
		}
	}
}

void ThomasTankInput::MoveUp(bool isFirstPlayer)
{
	ThomasTankEngine::MovePlayer(Vector2(0.0f, -1.0f), isFirstPlayer);
}

void ThomasTankInput::MoveDown(bool isFirstPlayer)
{
	ThomasTankEngine::MovePlayer(Vector2(0.0f, 1.0f), isFirstPlayer);
}