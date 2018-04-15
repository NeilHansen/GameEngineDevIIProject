#pragma once
#include"ThomasTankEngine.h"
//#include <SFML/Window/Event.hpp>


class ThomasTankInput {
public:
	ThomasTankInput() {}
	~ThomasTankInput() {}
	static void Initialize();
	static void ProcessInput();

	static void MoveUp(bool isFirstPlayer);
	static void MoveDown(bool isFirstPlayer);
	static void WalkingAnim(bool isWalking, bool isFirstPlayer);
	static void ShootAnim(bool isFirstplayer);
	static void DeathAnim(bool isFirstplayer);
private:

};

