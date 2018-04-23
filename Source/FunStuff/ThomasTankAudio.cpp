
#include "ThomasTankAudio.h"
#include <iostream>

sf::SoundBuffer ThomasTankAudio::buffer;
sf::Music ThomasTankAudio::music;
sf::Sound ThomasTankAudio::sound;

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


void ThomasTankAudio::PlayMusic(std::string filename)
{
	//sf::Music music;
	if (!music.openFromFile("../../Assets/Audio/" + filename))
	{
		printf("AUDIO ERROR\n");
		return; // error
	}
	music.play();
}

void ThomasTankAudio::StopMusic()
{
	music.stop();
}


// use this for filename "filename.extention"
void ThomasTankAudio::PlaySfx(std::string filename)
{
	//sf::SoundBuffer buffer;
	if (!buffer.loadFromFile("../../Assets/Audio/" +  filename))
	{
		printf("loading sfx failed\n");
		return;
	}

	sound.setBuffer(buffer);
	sound.play();

}