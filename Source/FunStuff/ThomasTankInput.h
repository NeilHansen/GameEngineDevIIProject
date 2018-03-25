#pragma once
#include"ThomasTankEngine.h"
//#include <SFML/Window/Event.hpp>


class ThomasTankInput {
public:
	ThomasTankInput() {}
	~ThomasTankInput() {}
	static void Initialize();
	static void ProcessInput();

	static void MoveUp();
	static void MoveDown();
	static void MoveLeft();
	static void MoveRight();

private:

};

