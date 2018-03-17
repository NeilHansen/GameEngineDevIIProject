#include "ThomasTankInputManager.h"
#include <iostream>

ThomasTankInputManager::ThomasTankInputManager()
{
}
ThomasTankInputManager::~ThomasTankInputManager()
{
}

void ThomasTankInputManager::Initialize()
{
	std::cout << "Input System Initialized" << "\n";
}



void ThomasTankInputManager::ProcessInput()
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
					std::cout << "W" << "\n";
					//(0,1)
				}
				if (event.key.code == sf::Keyboard::S)
				{
					std::cout << "S" << "\n";
					//(0,-1)
				}
				if (event.key.code == sf::Keyboard::A)
				{
					std::cout << "A" << "\n";
					//(1,0)
				}
				if (event.key.code == sf::Keyboard::D)
				{
					std::cout << "D" << "\n";
					//(-1,0)
				}
				if (event.key.code == sf::Keyboard::Space)
				{
					std::cout << "SPACE" << "\n";
				}


				

			}
			
		}
	}
}


