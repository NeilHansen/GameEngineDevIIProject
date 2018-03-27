#include "ThomasTankAssetHolder.h"


void ThomasTankAssetHolder::LoadAssets()
{
	// load player texture
	if (!playerTexture.loadFromFile(filePath + "/Images/player.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}
	//assert();

	// load enemy texture
	if (!enemyTexture.loadFromFile(filePath + "/Images/enemy.png"))
	{
		std::cout << "Failed to load enemy image" << std::endl;
	}
	//assert(!enemyTexture.loadFromFile(filePath + "/Images/enemy.png"));

	// load other texture
	if (!miscTexture.loadFromFile(filePath + "/Images/misc.png"))
	{
		std::cout << "Failed to load misc image" << std::endl;
	}
	//assert(!enemyTexture.loadFromFile(filePath + "/Images/enemy.png")); // change

	//if(!buffer->loadFromFile(filePath + "Audio/Vanilla.wav"))
	sf::Texture text;
	//sf::SoundBuffer buffer;
//	sf::Music music;
	//music.openFromFile("Audio/Vanilla.wav");

	std::cout << "Assets Loaded" << std::endl;
}
