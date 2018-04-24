#include "ThomasTankInput.h"
#include <iostream>


void ThomasTankInput::Initialize()
{
	canMove = true;
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
				ThomasTankAudio::StopMusic();
				ThomasTankAudio::PlayMusic("The XX - Intro.wav");
				return;
			}
		}
		if (ThomasTankEngine::gameState == ThomasTankEngine::Playing)
		{
			if (canMove) {
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
						//std::cout << "Mouse Button Left" << "\n";
					}
				}
				//Keyboard Input - player1
				if (event.type == sf::Event::EventType::KeyPressed)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						MoveUp(true);
						WalkingAnim(true, true);

						//std::cout << "W" << "\n";
					}
					if (event.key.code == sf::Keyboard::S)
					{
						MoveDown(true);
						WalkingAnim(true, true);
						//std::cout << "S" << "\n";
					}

					//player 1 fire
					if (event.key.code == sf::Keyboard::LControl)
					{
						//Fire(true);
						ShootAnim(true);
						//std::cout << "S" << "\n";
					}

					//player2
					if (event.key.code == sf::Keyboard::Up)
					{
						MoveUp(false);
						WalkingAnim(true, false);
						//std::cout << "Up" << "\n";
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						MoveDown(false);
						WalkingAnim(true, false);
						//std::cout << "Down" << "\n";
					}

					//player 2 fire
					if (event.key.code == sf::Keyboard::RControl)
					{
						//Fire(true);
						ShootAnim(false);
						//std::cout << "S" << "\n";
					}
				}
				if (event.type == sf::Event::EventType::KeyReleased)
				{
					if (event.key.code == sf::Keyboard::W)
					{
						//std::cout << "No input" << std::endl;
						ThomasTankEngine::StopPlayer(true);
						WalkingAnim(false, true);
					}
					if (event.key.code == sf::Keyboard::S)
					{
						//std::cout << "No input" << std::endl;
						ThomasTankEngine::StopPlayer(true);
						WalkingAnim(false, true);
					}
					/*if (event.key.code == sf::Keyboard::LControl)
					{
						WalkingAnim(false, true);
					}*/

					//std::cout << "WTF M8" << std::endl;

					//player2
					if (event.key.code == sf::Keyboard::Up)
					{
						//std::cout << "No input" << std::endl;
						ThomasTankEngine::StopPlayer(false);
						WalkingAnim(false, false);
					}
					if (event.key.code == sf::Keyboard::Down)
					{
						//std::cout << "No input" << std::endl;
						ThomasTankEngine::StopPlayer(false);
						WalkingAnim(false, false);
					}

					/*if (event.key.code == sf::Keyboard::RControl)
					{
						WalkingAnim(false, false);
					}*/
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

void ThomasTankInput::WalkingAnim(bool isWalking, bool isFirstPlayer)
{
	ThomasTankEngine::WalkingAnim(isWalking, isFirstPlayer);
}

void ThomasTankInput::ShootAnim(bool isFirstPlayer)
{
	ThomasTankEngine::ShootAnim(isFirstPlayer);
}

void ThomasTankInput::DeathAnim(bool isFirstPlayer)
{
	ThomasTankEngine::DeathAnim(isFirstPlayer);
}