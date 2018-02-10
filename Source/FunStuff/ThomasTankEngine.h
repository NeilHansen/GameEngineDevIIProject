#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <stdio.h>
#include <iostream>
#include <direct.h>
#include <Windows.h>

class ThomasTankEngine
{
public:
	ThomasTankEngine();
	~ThomasTankEngine();
	static void Initialize();
	static void Start();
	static void GameLoop();

private:
	static bool IsExiting();

	enum GameState {UnInitialized, ShowingSplash, Paused, ShowingMenu, Playing, Exiting};
	static GameState gameState;

	static sf::RenderWindow mainWindow;

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


	static sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor);
};



