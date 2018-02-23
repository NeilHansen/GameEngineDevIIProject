#pragma once

#include "SFML/System/Clock.hpp"

class BaseComponent
{
public:
	virtual void Start() {}
	virtual void Update() {}
};