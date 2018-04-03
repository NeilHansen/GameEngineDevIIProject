
#include "ThomasTankAudio.h"
#include <iostream>

//sf::SoundBuffer ThomasTankAudio::buffer;
sf::Music ThomasTankAudio::music;
ThomasTankAudio::ThomasTankAudio()
{
}

ThomasTankAudio::~ThomasTankAudio()
{
}

void ThomasTankAudio::Initialize()
{
	std::cout << "Audio Engine Initialized" << "\n";
}


void ThomasTankAudio::PlayMusic()
{
	//sf::Music music;
	if (!music.openFromFile("../../Assets/Audio/Vanilla.wav"))
	{
		printf("AUDIO ERROR\n");
		return; // error
	}
	music.play();
}