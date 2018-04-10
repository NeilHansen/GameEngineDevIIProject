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

private:

};

