#pragma once

#include <Windows.h>
#include "IVibeData.h"

class F4IReader
{
protected:
	// Const variables
	const char * const c_szSharedNameSpace = "FalconIntellivibeSharedMemoryArea";

	// Member Variables
	HANDLE m_hMapping = nullptr;
	HANDLE m_hView = nullptr;
	IntellivibeData *m_ivData = nullptr;

public:
	// Public functions
	F4IReader() = default;
	F4IReader& operator=(const F4IReader &) = delete;
	F4IReader(const F4IReader&) = delete;
	bool peekVariables(bool &bIn3D, bool & bIsExitGame);
protected:
	// protected functions
	void UnsafePeekVariables(bool& bIn3D, bool& bIsExitGame);
	bool ConnectSharedMemory();
	void DisconnectSharedMemory();
};

