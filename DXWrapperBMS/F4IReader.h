#pragma once

#include <Windows.h>
#include "IVibeData.h"

class F4IReader
{
public:
	// Typedefs
	typedef void (*F4IREADER_CALLBACK_TYPE)(F4IReader* self, bool bSucceeded, bool bIs3D, bool bIsExit);
protected:
	// Const variables
	const char const* c_szSharedNameSpace = "FalconIntellivibeSharedMemoryArea";

	// Member Variables
	HANDLE m_hMapping = nullptr;
	HANDLE m_hView = nullptr;
	bool bMonitor = false;
	IntellivibeData *m_ivData = nullptr;

public:
	// Public functions
	F4IReader() = default;
	bool peekVariables(bool &bIn3D, bool & bIsExitGame);
protected:
	// protected functions
	void UnsafePeekVariables(bool& bIn3D, bool& bIsExitGame);
	bool ConnectSharedMemory();
	void DisconnectSharedMemory();
};

