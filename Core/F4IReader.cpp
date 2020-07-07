#include "F4IReader.h"

bool F4IReader::peekVariables(bool& bIn3D, bool& bIsExitGame)
{
	if(!m_ivData)
	{
		if(!ConnectSharedMemory())
		{
			return false;
		}
	}
	UnsafePeekVariables(bIn3D, bIsExitGame);
	return true;
}

void F4IReader::UnsafePeekVariables(bool& bIn3D, bool& bIsExitGame)
{
	// This reads the data with no safety checks. This is why it's protected. The checks are done elsewhere.
	// This might need to be refactored into the safe version.
	bIn3D = m_ivData->In3D;
	bIsExitGame = m_ivData->IsExitGame;
}

bool F4IReader::ConnectSharedMemory()
{
	DisconnectSharedMemory();
	m_hMapping = OpenFileMapping(FILE_MAP_READ, FALSE, c_szSharedNameSpace);
	if (m_hMapping)
	{
		m_hView = MapViewOfFile(m_hMapping, FILE_MAP_READ, 0, 0, 0);
		if (m_hView)
		{
			m_ivData = reinterpret_cast<IntellivibeData *>(m_hView);
			return true;
		}
	}
	return false;
}

void F4IReader::DisconnectSharedMemory()
{
	m_ivData = nullptr;
	UnmapViewOfFile(m_hView);
	CloseHandle(m_hMapping);
}