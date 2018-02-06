/***************************************************************************
// 
//
*****************************************************************************/
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <direct.h>
#include <SFML/Graphics.hpp>

using namespace std;

bool IsOnlyInstance(LPCTSTR gameTitle);
bool CheckStorage(const DWORDLONG diskSpaceNeeded);
void GetAvailableMemory(DWORDLONG &ram, DWORDLONG &vram, DWORDLONG &ramTotal, DWORDLONG &vramTotal);
void GetSystemArchitecture();
DWORD ReadCPUSpeed();

LPCTSTR g_gameTitle = "FunStuff";
DWORDLONG g_diskSpaceNeeded = 300;
DWORDLONG g_vramAvailable = 0;
DWORDLONG g_ramAvailable = 0;
DWORDLONG g_ramTotal = 0;
DWORDLONG g_vramTotal = 0;
DWORD g_cpuSpeed = 0;

sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor);

int main()
{
	/*
	cout << "Lab #2\n\n";	

	if (IsOnlyInstance(g_gameTitle))
		cout << "\tThis is the only Instance of " << g_gameTitle << "\n\n";
	else
		cout << "\tAnother Instance of " << g_gameTitle << " has been created\n\n";

	if (CheckStorage(g_diskSpaceNeeded))
		cout << "\tThere is available disk space\n\n";

	GetAvailableMemory(g_ramAvailable, g_vramAvailable, g_ramTotal, g_vramTotal);

	cout << "\tRAM available: " << g_ramAvailable / 1000000 << " MB" << "\n";
	cout << "\tRAM total: " << g_ramTotal / 1000000 << " MB" << "\n";
	cout << "\tVRAM available: " << g_vramAvailable / 1000000 << " MB" << "\n";
	cout << "\tVRAM total: " << g_vramTotal / 1000000 << " MB" << "\n\n";

	g_cpuSpeed = ReadCPUSpeed();
	cout << "\tCPU Speed: " << g_cpuSpeed << " MHz" << "\n\n";

	// cout architecture within function
	GetSystemArchitecture();
	*/
	sf::RenderWindow window({ 1200, 800 }, "Haiii");
	window.setFramerateLimit(30);

	while(window.isOpen())
	{
		sf::Event event;

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				
				window.close();
			}
		}

		window.clear();
		
		sf::CircleShape circle = MakeCircle(100, 50, sf::Color::Green, sf::Color::Cyan);
		circle.setPosition(150, 150);
		window.draw(circle);
		window.display();
	}

	cin.get();
}

sf::CircleShape MakeCircle(float radius, float outlineThickness, sf::Color color, sf::Color outlineColor)
{
	sf::CircleShape circle(radius);
	circle.setFillColor(color);

	circle.setOutlineThickness(outlineThickness);
	circle.setOutlineColor(outlineColor);

	return circle;
}

bool IsOnlyInstance(LPCTSTR gameTitle)
{
	HANDLE handle = CreateMutex(NULL, TRUE, gameTitle);
	if (GetLastError() != ERROR_SUCCESS) 
	{
		
		//HWND hWnd = FindWindow(gameTitle, NULL);
		//if (hWnd) 
		//{
			// An instance of your game is already running.
			//ShowWindow(hWnd, SW_SHOWNORMAL);
			//SetFocus(hWnd);
			//SetForegroundWindow(hWnd);
			//SetActiveWindow(hWnd);
			return false;
		//}
	}
	return true;
}

bool CheckStorage(const DWORDLONG diskSpaceNeeded) 
{
	// Check for enough free disk space on the current disk.
	int const drive = _getdrive();
	struct _diskfree_t diskfree;
	_getdiskfree(drive, &diskfree);
	unsigned __int64 const neededClusters = diskSpaceNeeded / (diskfree.sectors_per_cluster * diskfree.bytes_per_sector);

	if (diskfree.avail_clusters < neededClusters) 
	{
		// if you get here you don’t have enough disk space!
		cout << "CheckStorage Failure : Not enough physical storage." << endl;
		return false;
	}

	return true;
}

void GetAvailableMemory(DWORDLONG &ram, DWORDLONG &vram, DWORDLONG &ramTotal, DWORDLONG &vramTotal)
{
	MEMORYSTATUSEX status;
	status.dwLength = sizeof(status);
	GlobalMemoryStatusEx(&status);

	ram = (DWORDLONG)status.ullAvailPhys;
	vram = (DWORDLONG)status.ullAvailVirtual; // vram isn't returning correct values
	ramTotal = (DWORDLONG)status.ullTotalPhys;
	vramTotal = (DWORDLONG)status.ullTotalVirtual; // vram isn't returning correct values

	/*
	if (status.ullTotalPhys < physicalRAMNeeded)
	{
		//you don’t have enough physical memory. Tell the
		//player to go get a real computer and give this one to
		//his mother.
		cout << "CheckMemory Failure : Not enough physical memory." << endl; 
		
		return false;
	}

	// Check for enough free memory.
	if (status.ullAvailVirtual < virtualRAMNeeded)
	{
		// you don’t have enough virtual memory available.
		// Tell the player to shut down the copy of Visual Studio running in the background.
		cout << "CheckMemory Failure : Not enough virtual memory." << endl;
		return false;
	}
	

	char *buff = new char[virtualRAMNeeded];

	if (buff)
		delete[] buff;
	else 
	{
		// even though there is enough memory, it isn’t	available in one block, which can be critical for games	that manage their own memory
			cout << "CheckMemory Failure : Not enough contiguous memory." << endl;
		return false;
	}
	*/
}

DWORD ReadCPUSpeed() 
{
	DWORD BufSize = sizeof(DWORD);
	DWORD dwMHz = 0;
	DWORD type = REG_DWORD;
	HKEY hKey;

	// open the key where the proc speed is hidden:
	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		// query the key:
		RegQueryValueEx(hKey, "~MHz", NULL, &type, (LPBYTE)&dwMHz, &BufSize);
	}

	return dwMHz;
}

void GetSystemArchitecture()
{
	DWORD buffSize = sizeof(DWORD);
	DWORD type = REG_SZ;
	HKEY hKey;
	
	char charArr[256] = "";

	long lError = RegOpenKeyEx(HKEY_LOCAL_MACHINE, "HARDWARE\\DESCRIPTION\\System\\CentralProcessor\\0", 0, KEY_READ, &hKey);

	if (lError == ERROR_SUCCESS)
	{
		lError = RegQueryValueEx(hKey, "ProcessorNameString", NULL, &type, (LPBYTE)&charArr, &buffSize);

		while (lError == ERROR_MORE_DATA)
		{
			buffSize++;
			lError = RegQueryValueEx(hKey, "ProcessorNameString", NULL, &type, (LPBYTE)&charArr, &buffSize);
		}
	}

	cout << "\tSystem Architecture: " << charArr << "\n\n";

	return;
	/*
	if (sizeof(void*) == 8)
		return 64;
	if (sizeof(void*) == 4)
		return 32;
	*/
}