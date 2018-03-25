#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include <stdio.h>
#include <iostream>
#include <direct.h>
#include <Windows.h>

#include "ThomasTankAudio.h"
#include "ThomasTankPhysics.h"
#include "ThomasTankDisplay.h"
#include "ThomasTankSplash.h"
#include "SceneGraph.h"
#include "ThomasTankInput.h"
#include "ThomasTankAssetHolder.h"

#include "ThomasTankDemo.h"


class ThomasTankEngine
{
public:
	// Methods
	static void Initialize();
	static void Run();
	
	// Game State
	enum GameState { UnInitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting };
	static GameState gameState;

private:
	// Methods
	static void Quit();
	static void UpdateStatistics(sf::Time deltaTime);
	static void Update(sf::Time deltaTime);

	// Min Requirements
	static LPCTSTR g_gameTitle;
	static DWORDLONG g_diskSpaceNeeded;
	static DWORDLONG g_vramAvailable;
	static DWORDLONG g_ramAvailable;
	static DWORDLONG g_ramTotal;
	static DWORDLONG g_vramTotal;
	static DWORD g_cpuSpeed;

	static bool IsOnlyInstance(LPCTSTR gameTitle);
	static bool CheckStorage(const DWORDLONG diskSpaceNeeded);
	static void GetAvailableMemory(DWORDLONG &ram, DWORDLONG &vram, DWORDLONG &ramTotal, DWORDLONG &vramTotal);
	static DWORD ReadCPUSpeed();
	static void GetSystemArchitecture();

	// Engine
	static SceneGraph sceneGraph;
	static ThomasTankAssetHolder assetHolder;
	static ThomasTankDemo demo;

	// Stats
	static const sf::Time timePerFrame;
	static sf::Time m_statsUpdateTime;
	static std::size_t m_statsNumberOfFrames;
};



