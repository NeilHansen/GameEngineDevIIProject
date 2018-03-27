#pragma once
#include "SFML/Audio.hpp"
#include <string>


class ThomasTankAudio
{
public:
	static void Initialize();
	static void playMusic();
	ThomasTankAudio();
private:
	static std::string filePath;
	//sf::SoundBuffer buffer;
	//sf::Sound music;

public:
	
};
