#pragma once

#include "F4IReader.h"
#include <thread>
#include <chrono>
#include <string>

/*
	TODO:
		- Consider taking input from the BMS command line (ie. -F4DXWrapper_PollRate=50) or via Falcon BMS.cfg (ie. set g_nPollingMemoryRate2D <n> and set g_nPollingMemoryRate3D <n>)

*/

class F4DX_manager
{
private:
	// Constants
	inline static const char *m_szVersion = "0.1.0-alpha.1";
	constexpr static auto PollMemoryRate2D = std::chrono::milliseconds(50);		// We poll this in 2D, trying to get moving as soon as possible.
	constexpr static auto PollMemoryRate3D = std::chrono::milliseconds(3000);	// We poll this in 3D, trying to sleep as long as possible.

	///////////////
	// Variables //
	///////////////

	// D3D9 variables
	bool bDraw = true;

	// Init variables
	bool bInit = false;

	// Object variables
	F4IReader memReader;

	// Constructor
	F4DX_manager() = default;

	// Private initialization functions
	void initEnvironment();

public:
	static F4DX_manager& getManager()
	{
		// Thread-safe as of C++11 and VS2015.
		// (see https://preshing.com/20130930/double-checked-locking-is-fixed-in-cpp11/)
		static F4DX_manager singleton;
		return singleton;
	}

	static const std::string& getVersion()
	{
		static const std::string version = m_szVersion;
		return version;
	}

	static BOOL WINAPI CtrlHandler(DWORD dwCtrlType) noexcept(true);

	// Deleting constructor copy and assign. Singleton pattern, baby.
	F4DX_manager(F4DX_manager const&) = delete;
	void operator=(F4DX_manager const&) = delete;

	// Functions to get function pointers to the real DirectX Create* functions.
	FARPROC loadFunction(const char * const szLib, const char * const szFunc);

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
		DXWrapper1.3.5(Draw:1;PollingRate:50ms)[CTRL+BRK]or[CTRL+C]enables/disables drawing.

	To set Msg, call setTextOutput().
*/
	void setTextOutput(std::string newMsg);
};