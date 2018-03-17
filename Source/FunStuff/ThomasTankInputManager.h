#pragma once
#include"ThomasTankEngine.h"
#include "ThomasTankDisplay.h"
//#include <SFML/Window/Event.hpp>
#include <SFML/Window.hpp>

class ThomasTankInputManager{
public:
	ThomasTankInputManager();
	~ThomasTankInputManager();
	static void Initialize();
	static void Update();
	static void ProcessInput();
	void moveUp();
	void moveDown();
	void moveLeft();
	void moveRight();
	
	
private:
	
};

