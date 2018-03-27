#pragma once

#include <iostream>
#include <string>
#include <assert.h>
#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"




class ThomasTankAssetHolder
{

public:
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	sf::Texture miscTexture;
	//sf::SoundBuffer buffer;
	//sf::Sound bgMusic;
	//sf::Sound sfx;
	
	

private:
	std::string filePath = "../../Assets";

public:
	ThomasTankAssetHolder() {}
	~ThomasTankAssetHolder() {}

	void LoadAssets();
private:

};