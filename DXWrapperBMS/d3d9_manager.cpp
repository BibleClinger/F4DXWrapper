#include "d3d9_manager.h"
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <sstream>
#include <thread>
#include <chrono>

BOOL WINAPI d3d9_manager::CtrlHandler(DWORD dwCtrlType) noexcept(true)
{
	switch(dwCtrlType)
	{
	case CTRL_BREAK_EVENT:
	case CTRL_C_EVENT:
		getManager().setDraw(!getManager().shouldDraw());
		return true; // For now we eat the CTRL + C event and don't pass it on (since it can close BMS).
	}
	return false;
}

void d3d9_manager::loadRealDLL()
{
	static bool bRealDLLLoaded = false;

	if (!bRealDLLLoaded)
	{
		hinstRealDLL = LoadLibrary(szRealDLLPath);
		if (hinstRealDLL)
		{
#pragma warning( disable : 4191)
			fnCreate9 = reinterpret_cast<fnDirect3DCreate9>(GetProcAddress(hinstRealDLL, "Direct3DCreate9"));
			fnCreate9Ex = reinterpret_cast<fnDirect3DCreate9Ex>(GetProcAddress(hinstRealDLL, "Direct3DCreate9Ex"));
#pragma warning( default : 4191)
			if (fnCreate9 && fnCreate9Ex)
			{
				bRealDLLLoaded = true;
			}
		}
	}
}

void d3d9_manager::setDLL(HINSTANCE hinstDLL)
{
	// Note: This call is expected from DLLMAIN.
	// DO *NOT* DO ANTYHING HERE THAT ISN'T SAFE.
	this->hinstThisDLL = hinstDLL;	
}

void d3d9_manager::initEnvironment()
{
	if(!bInit)
	{
		loadRealDLL();	// Load the real D3D9.dll. This is 100% necessary.
		establishIO();	// Establish cheap IO with the server admin.
		std::thread(&d3d9_manager::poll3DEnvironment, this).detach();  // Fire off the polling thread for Falcon memory analyzer. We don't join it on exit, so detach immediately.
		bInit = true;
	}
}

fnDirect3DCreate9 d3d9_manager::getRealCreate9fn()
{
	initEnvironment();
	return fnCreate9;
}

fnDirect3DCreate9Ex d3d9_manager::getRealCreate9Exfn()
{
	initEnvironment();
	return fnCreate9Ex;
}

void d3d9_manager::setDraw(bool bNewDraw)
{
	std::stringstream msg;
	bDraw = bNewDraw;

	msg << "Draw: " << bDraw << ";PollingRate: " << (!bDraw ? PollMemoryRate3D.count() : PollMemoryRate2D.count()) << "ms";
	setTextOutput(msg.str());
}

bool d3d9_manager::shouldDraw()
{
	return bDraw;
}

void d3d9_manager::setTextOutput(std::string newMsg)
{
	std::string sTitle = "F4DXWrapper." + getVersion() + "(" + newMsg + ")[CTRL+BRK]or[CTRL+C]enables/disables drawing.";
	SetConsoleTitle(sTitle.c_str());
}

void d3d9_manager::establishIO()
{
	bool bExistingConsole = false;
	bool bAttached = false;
	bool bAlloc = false;

	if(GetConsoleWindow())
	{
		bExistingConsole = true; // Console already attached
	}
	else
	{
		bAttached = AttachConsole(ATTACH_PARENT_PROCESS); // We have no console, and we're trying to attach to BMS' parent console, if any.
		if(!bAttached)
		{
			bAlloc = AllocConsole(); // We and BMS' parent process have no console. We try to allocate our own.
		}
	}
	// We should have a console by now.
	//if (!bExistingConsole && !bAttached && !bAlloc)
	//{
		/*
			This is a situation where:
				1. we couldn't find a console;
				2. we couldn't attach to a console; and
				3. we couldn't allocate a console.

			It may be theoretically possible that we have a console that isn't detected by GetConsoleWindow().

			For now we do nothing different.
		*/
	//}

	SetConsoleCtrlHandler(d3d9_manager::CtrlHandler, TRUE);
	setTextOutput("Waiting for 3D...");
}

void d3d9_manager::poll3DEnvironment()
{
	bool bIn3D = false;
	bool bIsExitGame = false;

	bool bOld3D = false;
	bool bFirst = true;
	bool bMonitor = true;

	while (std::this_thread::sleep_for(bIn3D ? PollMemoryRate3D : PollMemoryRate2D), bMonitor)
	{
		if (!memReader.peekVariables(bIn3D, bIsExitGame))
		{
			continue; // Error reading. Shared memory isn't set up. Skip this cycle.
		}
		if (bIsExitGame)
		{
			// We're bingo on time. BMS thinks it's exiting.
			setDraw(true); // We should probably be drawing.
			bMonitor = false; // We should stop monitoring.
		}

		if (bFirst)
		{
			// This is our first read, so set some initial variables and ignore this.
			bFirst = false;
			// Note: The drawing will start as true upon startup, and we should be in 2D anyway at this point.
		}
		else if (bIn3D != bOld3D)
		{
			// This is not the first run, *and* we have a new 3D state.
			//SetConsoleTitle("3D change in Falcon BMS detected..."); // Change to an IO function in the manager.
			setDraw(!bIn3D); // Don't draw in 3D; draw when NOT in 3D.
		}
		bOld3D = bIn3D; // Save the old value.
	}
}