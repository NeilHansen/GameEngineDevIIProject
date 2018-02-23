#include "ThomasTankEngine.h"

using namespace std;

// Min Requirements
LPCTSTR ThomasTankEngine::g_gameTitle = "ThomasTankEngine";
DWORDLONG ThomasTankEngine::g_diskSpaceNeeded = 0;
DWORDLONG ThomasTankEngine::g_vramAvailable = 0;
DWORDLONG ThomasTankEngine::g_ramAvailable = 0;
DWORDLONG ThomasTankEngine::g_ramTotal = 0;
DWORDLONG ThomasTankEngine::g_vramTotal = 0;
DWORD ThomasTankEngine::g_cpuSpeed = 0;

// State
ThomasTankEngine::GameState ThomasTankEngine::gameState = ThomasTankEngine::UnInitialized;

// Scene Graph
SceneGraph ThomasTankEngine::sceneGraph;

// Stats
const sf::Time ThomasTankEngine::timePerFrame = sf::seconds(1.0f/60.0f);
sf::Time ThomasTankEngine::m_statsUpdateTime = sf::Time::Zero;
std::size_t ThomasTankEngine::m_statsNumberOfFrames = 0;


void ThomasTankEngine::Initialize()
{
	// Check for another instance
	if (ThomasTankEngine::IsOnlyInstance(ThomasTankEngine::g_gameTitle))
		cout << "\tThis is the only Instance of " << ThomasTankEngine::g_gameTitle << "\n\n";
	else
		cout << "\tAnother Instance of " << ThomasTankEngine::g_gameTitle << " has been created\n\n";

	// Check storage
	if (ThomasTankEngine::CheckStorage(ThomasTankEngine::g_diskSpaceNeeded))
		cout << "\tThere is available disk space\n\n";

	// Check Memory
	ThomasTankEngine::GetAvailableMemory(ThomasTankEngine::g_ramAvailable, ThomasTankEngine::g_vramAvailable, ThomasTankEngine::g_ramTotal, ThomasTankEngine::g_vramTotal);

	cout << "\tRAM available: " << ThomasTankEngine::g_ramAvailable / 1000000 << " MB" << "\n";
	cout << "\tRAM total: " << ThomasTankEngine::g_ramTotal / 1000000 << " MB" << "\n";
	cout << "\tVRAM available: " << ThomasTankEngine::g_vramAvailable / 1000000 << " MB" << "\n";
	cout << "\tVRAM total: " << ThomasTankEngine::g_vramTotal / 1000000 << " MB" << "\n\n";

	ThomasTankEngine::g_cpuSpeed = ThomasTankEngine::ReadCPUSpeed();
	cout << "\tCPU Speed: " << ThomasTankEngine::g_cpuSpeed << " MHz" << "\n\n";

	// cout architecture within function
	ThomasTankEngine::GetSystemArchitecture();

	// Initialize other components of the engine
	ThomasTankAudio::Initialize();
	ThomasTankPhysics::Initialize();
	ThomasTankDisplay::Initialize();

	// Initialize scene graph
	sceneGraph.Start();

	gameState = ThomasTankEngine::ShowingSplash;

	cout << "Engine Intialized" << "\n";
}

void ThomasTankEngine::Run()
{
	if (gameState == ThomasTankEngine::UnInitialized)
	{
		return;
	}

	// Splash
	if (gameState == ThomasTankEngine::ShowingSplash)
	{
		cout << "\nShow splash" << endl;
		ThomasTankSplash::Show(ThomasTankDisplay::mainWindow);
	}

	// Delta Time
	sf::Clock clock = sf::Clock();
	sf::Time timeSinceLastUpdate = sf::Time::Zero;

	// Main Loop
	while (ThomasTankDisplay::mainWindow.isOpen())
	{
		// Check if we should be exiting
		if (gameState == ThomasTankEngine::Exiting)
		{
			//Quit; not working
			return;
		}

		sf::Time dt = clock.restart();
		timeSinceLastUpdate += dt;

		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;

			// Handle input & update
			ProcessInput();
			Update(timePerFrame);
			//cout << "Update..." << endl;
		}

		// Update Stats & Render
		UpdateStatistics(dt);
		ThomasTankDisplay::Draw();
	}
}

void ThomasTankEngine::UpdateStatistics(sf::Time deltaTime)
{
	m_statsUpdateTime += deltaTime;
	m_statsNumberOfFrames++;

	if (m_statsUpdateTime >= sf::seconds(1.0f))
	{
		ThomasTankDisplay::UpdateStatsText("FPS: " + std::to_string(m_statsNumberOfFrames));

		m_statsUpdateTime -= sf::seconds(1.0f);
		m_statsNumberOfFrames = 0;
	}
}

void ThomasTankEngine::Update(sf::Time deltaTime)
{
	// Draw scene graph
	sceneGraph.Update(deltaTime);
}

void ThomasTankEngine::ProcessInput()
{
	sf::Event event;
	while (ThomasTankDisplay::mainWindow.pollEvent(event))
	{
		// Check for window close
		if (event.type == sf::Event::Closed)
		{
			//Quit; not working
			ThomasTankDisplay::mainWindow.close();
		}
	}
}

// Not actually being used right now
void ThomasTankEngine::Quit()
{
	// Close application
	ThomasTankDisplay::mainWindow.close();
}

bool ThomasTankEngine::IsOnlyInstance(LPCTSTR gameTitle)
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

bool ThomasTankEngine::CheckStorage(const DWORDLONG diskSpaceNeeded)
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

void ThomasTankEngine::GetAvailableMemory(DWORDLONG &ram, DWORDLONG &vram, DWORDLONG &ramTotal, DWORDLONG &vramTotal)
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

DWORD ThomasTankEngine::ReadCPUSpeed()
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

void ThomasTankEngine::GetSystemArchitecture()
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
