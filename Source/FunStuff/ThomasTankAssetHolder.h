#pragma once

#include <iostream>
#include <string>
#include <assert.h>

#include "SFML/Graphics.hpp"




class ThomasTankAssetHolder
{

public:
	sf::Texture playerTexture;
	sf::Texture enemyTexture;
	sf::Texture miscTexture;
	

private:
	std::string filePath = "../../Assets";

public:
	ThomasTankAssetHolder() {}
	~ThomasTankAssetHolder() {}

	void LoadAssets();
private:

};