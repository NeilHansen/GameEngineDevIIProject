#pragma once

#include <SFML/Audio.hpp>


class ThomasTankAudio
{
public:
	ThomasTankAudio();
	~ThomasTankAudio();
	static void Initialize();
	static void PlayMusic();
	
private:
 	static sf::SoundBuffer buffer;
	static sf::Music music;

};
