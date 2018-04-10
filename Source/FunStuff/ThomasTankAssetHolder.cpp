#include "ThomasTankAssetHolder.h"


void ThomasTankAssetHolder::LoadAssets()
{
	// load player texture
	if (!playerTexture.loadFromFile(filePath + "/Images/CharacterWalk.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	if (!playerWalkTexture.loadFromFile(filePath + "/Images/CharacterWalk1.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	if (!playerShootTexture.loadFromFile(filePath + "/Images/CharacterShoot.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	if (!playerHitTexture.loadFromFile(filePath + "/Images/CharacterDeath.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	
	//assert();

	// load enemy texture
	if (!enemyTexture.loadFromFile(filePath + "/Images/Character2Walk.png"))
	{
		std::cout << "Failed to load enemy image" << std::endl;
	}

	if (!enemyWalkTexture.loadFromFile(filePath + "/Images/Character2Walk1.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	if (!enemyShootTexture.loadFromFile(filePath + "/Images/Character2Shoot.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	if (!enemyHitTexture.loadFromFile(filePath + "/Images/Character2Death.png"))
	{
		std::cout << "Failed to load player image" << std::endl;
	}

	
	//assert(!enemyTexture.loadFromFile(filePath + "/Images/enemy.png"));

	// load other texture
	if (!miscTexture.loadFromFile(filePath + "/Images/misc.png"))
	{
		std::cout << "Failed to load misc image" << std::endl;
	}
	//assert(!enemyTexture.loadFromFile(filePath + "/Images/enemy.png")); // change

	std::cout << "Assets Loaded" << std::endl;
}
