#pragma once

#include <iostream>
#include <string>
#include <assert.h>

#include "SFML/Graphics.hpp"




class ThomasTankAssetHolder
{

public:
	sf::Texture playerTexture;
	sf::Texture playerWalkTexture;
	sf::Texture playerShootTexture;
	sf::Texture playerHitTexture;
    sf::Texture enemyTexture;
	sf::Texture enemyWalkTexture;
	sf::Texture enemyShootTexture;
	sf::Texture enemyHitTexture;
	sf::Texture miscTexture;
;
	
	

private:
	std::string filePath = "../../Assets";

public:
	ThomasTankAssetHolder() {}
	~ThomasTankAssetHolder() {}

	void LoadAssets();
private:

};