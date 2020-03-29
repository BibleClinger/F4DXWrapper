#include "d3d9_manager.h"
#include <io.h>
#include <fcntl.h>
#include <iostream>

const char const* g_szVersion = "0.0.3-alpha.1";

void d3d9_manager::F4MemoryCallback(bool bSucceeded, bool bIs3D, bool IsExitGame)
{
	if (bSucceeded)
	{
		if(bIs3D)
		{
			//SleepEx(dwSleepBeforeStopDrawing, FALSE);
			//We should be calling a d3d9 clear() to paint the screen.
			getManager().setDraw(false);
		}
		else
		{
			getManager().setDraw(true);
		}
	}
}

BOOL d3d9_manager::CtrlHandler(DWORD dwCtrlType)
{
	switch(dwCtrlType)
	{
	case CTRL_BREAK_EVENT:
		getManager().setDraw(!getManager().shouldDraw());
		return true;
	case CTRL_C_EVENT:
		getManager().setDraw(!getManager().shouldDraw());
		return false;
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
		memReader->Monitor3DAsync(d3d9_manager::F4MemoryCallback);
		bInit = true;
	}
}

/*
void d3d9_manager::setD3D9(D9Wrapper::IDirect3D9* pd3d9)
{
	this->pd3d9 = pd3d9;
}
*/
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

	std::string sTitle = "{DXWrapperBMS" + std::string(g_szVersion) + "} [CTRL + BREAK] or [CTRL + C] to enable/disable drawing.";

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
		// We have a weird situation. Abort! Abort! Or just keep going.
	}

	SetConsoleCtrlHandler(d3d9_manager::CtrlHandler, TRUE);
	SetConsoleTitle(sTitle.c_str());
}