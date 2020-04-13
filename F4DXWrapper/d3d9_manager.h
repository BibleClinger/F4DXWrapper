#pragma once

#include "d3d9_main.h"
#include "F4IReader.h"
#include <thread>
#include <chrono>
#include <string>

/*
	TODO:
		- Consider taking input from the BMS command line: -DXWrapperBMS_PollRate=50
*/

class d3d9_manager
{
private:
	// Constants
	inline static const char *m_szVersion = "0.0.4-alpha.2";
	inline static const char *szRealDLLPath = "C:\\Windows\\system32\\d3d9.dll";
	constexpr static auto PollMemoryRate2D = std::chrono::milliseconds(50);		// We poll this in 2D, trying to get moving as soon as possible.
	constexpr static auto PollMemoryRate3D = std::chrono::milliseconds(3000);	// We poll this in 3D, trying to sleep as long as possible.

	///////////////
	// Variables //
	///////////////

	// DLL Variables
	HINSTANCE hinstThisDLL = nullptr;
	HINSTANCE hinstRealDLL = nullptr;
	fnDirect3DCreate9 fnCreate9 = nullptr;
	fnDirect3DCreate9Ex fnCreate9Ex = nullptr;

	// D3D9 variables
	bool bDraw = true;

	// Init variables
	bool bInit = false;

	// Object variables
	F4IReader memReader;
	std::thread* m_thread = nullptr;

	d3d9_manager() = default;

	// Private initialization functions
	void initEnvironment();
	void loadRealDLL();

public:
	static d3d9_manager& getManager()
	{
		// Thread-safe as of C++11 and VS2015.
		// (see https://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/)
		static d3d9_manager singleton;
		return singleton;
	}

	static const std::string& getVersion()
	{
		static const std::string version = m_szVersion;
		return version;
	}

	static BOOL WINAPI CtrlHandler(DWORD dwCtrlType) noexcept(true);

	// Deleting constructor copy and assign. Singleton pattern, baby.
	d3d9_manager(d3d9_manager const&) = delete;
	void operator=(d3d9_manager const&) = delete;

	// Initialization functions
	void setDLL(HINSTANCE hinstDLL);

	// Functions to get function pointers to the real DirectX Create* functions.
	fnDirect3DCreate9 getRealCreate9fn();
	fnDirect3DCreate9Ex getRealCreate9Exfn();

	// Sets drawing conditions. true = drawing is enabled; false = drawing is disabled.
	void setDraw(bool bDraw);
	// Gets the draw conditions. true = functions calls from BMS to DirectX should be passed through; false = functions calls from BMS to DirectX should be ignored.
	bool shouldDraw();

	// Establishes 
	void establishIO();
	void poll3DEnvironment();

/*
OUTPUT:
	Name + Version :	"F4DXWrapper." + getVersion()
	Msg :				[Msg:""]
	Instructions :		[CTRL+BRK]or[CTRL+ ]enables/disables drawing.

	Example:
		DXWrapper1.3.5(Draw:1;PollingRate:50ms)[CTRL+BRK]or[CTRL+ ]enables/disables drawing.

	To set Msg, call setTextOutput().
*/
	void setTextOutput(std::string newMsg);
};