#include "ThomasTankAssetHolder.h"


void ThomasTankAssetHolder::LoadAssets()
{
	// load player texture
	assert(!playerTexture.loadFromFile(filePath + "/Images/player.png"));

	// load enemy texture
	assert(!enemyTexture.loadFromFile(filePath + "/Images/enemy.png"));

	// load other texture
	assert(!enemyTexture.loadFromFile(filePath + "/Images/enemy.png")); // change
}
