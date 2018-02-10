/***************************************************************************
// 
//
*****************************************************************************/
#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include <direct.h>
#include "ThomasTankEngine.h"

using namespace std;


int main(int argc, TCHAR* argv[])
{
	ThomasTankEngine tankEngine = ThomasTankEngine();
	tankEngine.Initialize();
	tankEngine.Start();
	tankEngine.GameLoop();
}

