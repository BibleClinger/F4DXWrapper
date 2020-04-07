#pragma once

#include <Windows.h>
#include <Memoryapi.h>
#include <thread>
#include "IVibeData.h"

class F4IReader
{
protected:
	// Typedefs
	typedef void (*F4IREADER_CALLBACK_TYPE)(F4IReader *self, bool bSucceeded, bool bIs3D, bool bIsExit);

	// Const variables
	const char const* c_szSharedNameSpace = "FalconIntellivibeSharedMemoryArea";
	DWORD c_dwSleepDelay = 5000; // 5 seconds

	// Member Variables
	std::thread *m_thread = NULL;
	HANDLE m_hMapping = NULL;
	HANDLE m_hView = NULL;
	bool bMonitor = false;
	IntellivibeData *m_ivData = NULL;
	DWORD m_dwSleepDelay;
public:
	// Public functions
	F4IReader()
	{
		m_dwSleepDelay = c_dwSleepDelay;
	}

	F4IReader(DWORD dwSleepDelay)
	{
		m_dwSleepDelay = dwSleepDelay;
	}

	// If sync, then return = next state of 3D
	// If async, then we need a callback provided for the next changed 3D state
	//void Monitor3DAsync(F4IREADER_CALLBACK_TYPE fn_usercallback);
	//bool Monitor3D(bool& bIn3D, bool& bIsExitGame);
	//void StopMonitor();
	bool peekVariables(bool &bIn3D, bool & bIsExitGame);
protected:
	// protected functions
	//void Monitor3DWrap(F4IREADER_CALLBACK_TYPE fn_usercallback);
	void UnsafePeekVariables(bool& bIn3D, bool& bIsExitGame);
	bool ConnectSharedMemory();
	void DisconnectSharedMemory();
};

