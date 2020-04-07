#include "d3d9_manager.h"
#include <io.h>
#include <fcntl.h>
#include <iostream>
#include <thread>
#include <chrono>

BOOL WINAPI d3d9_manager::CtrlHandler(DWORD dwCtrlType)
{
	switch(dwCtrlType)
	{
	case CTRL_BREAK_EVENT:
		getManager().setDraw(!getManager().shouldDraw());
		return true;
	case CTRL_C_EVENT:
		getManager().setDraw(!getManager().shouldDraw());
		return true;
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
			fnCreate9 = reinterpret_cast<fnDirect3DCreate9>(GetProcAddress(hinstRealDLL, "Direct3DCreate9"));
			fnCreate9Ex = reinterpret_cast<fnDirect3DCreate9Ex>(GetProcAddress(hinstRealDLL, "Direct3DCreate9Ex"));
			if (fnCreate9 && fnCreate9Ex)
			{
				bRealDLLLoaded = true;
			}
		}
	}
}

void d3d9_manager::setDLL(HINSTANCE hinstDLL, DWORD dwReason, LPVOID lpvReserved)
{
	// Note: This call is expected from DLLMAIN.
	// DO *NOT* DO ANTYHING HERE THAT ISN'T SAFE.
	// This may not even be needed.
	this->hinstThisDLL = hinstDLL;
	this->bDynamicallyLoaded = (lpvReserved == NULL);
}

void d3d9_manager::initEnvironment()
{
	if(!bInit)
	{
		// Load the real D3D9.dll. This is important.
		loadRealDLL();
		// Establish cheap IO with the server admin.
		establishIO();
		// Thread for Falcon memory analyzer.
		memReader = new F4IReader();
		//memReader->Monitor3DAsync(d3d9_manager::F4MemoryCallback);
		m_thread = new std::thread(&d3d9_manager::poll3DEnvironment, this);
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

void d3d9_manager::setDraw(bool bDraw)
{
	this->bDraw = bDraw;
}

bool d3d9_manager::shouldDraw()
{
	return bDraw;
}

void d3d9_manager::establishIO()
{
	bool bExistingConsole = false;
	bool bAttached = false;
	bool bAlloc = false;

	std::string sTitle = "{DXWrapperBMS" + getVersion() + "} [CTRL + BREAK] or [CTRL + C] to enable/disable drawing.";

	if(GetConsoleWindow())
	{
		// Console already attached
		bExistingConsole = true;
	}
	else
	{
		bAttached = AttachConsole(ATTACH_PARENT_PROCESS);
		if(!bAttached)
		{
			bAlloc = AllocConsole();
		}
	}
	// We should have a console by now.
	if (!bExistingConsole && !bAttached && !bAlloc)
	{
		// We have a weird situation. Abort! Abort! Or just keep going...
	}

	SetConsoleCtrlHandler(d3d9_manager::CtrlHandler, TRUE);
	SetConsoleTitle(sTitle.c_str());
}

void d3d9_manager::poll3DEnvironment()
{
	bool bIn3D = false;
	bool bIsExitGame = false;

	bool bOld3D = false;
	bool bFirst = true;
	bool bMonitor = true;

	while (std::this_thread::sleep_for(PollMemoryRate), bMonitor)
	{
		if (!memReader->peekVariables(bIn3D, bIsExitGame))
		{
			// Error reading. Shared memory isn't set up.

			// Danger, Will Robinson!
			continue;
		}
		if (bIsExitGame)
		{
			// We're bingo on time. BMS thinks it's exiting.

			// Danger, Will Robinson!
			setDraw(true); // We should probably be drawing.
			bMonitor = false; // We should stop monitoring.
		}

		if (bFirst)
		{
			// This is our first read, so set some initial variables and ignore this. The drawing will start as true upon startup, and we should be in 2D anyway at that point.
			bFirst = false;
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