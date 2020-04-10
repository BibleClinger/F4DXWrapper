#include "F4IReader.h"

//void F4IReader::Monitor3DAsync(F4IREADER_CALLBACK_TYPE fn_usercallback)
//{
//	m_thread = new std::thread(&F4IReader::Monitor3DWrap, this, fn_usercallback);
//}
//
//void F4IReader::BeginMonitor(F4IREADER_CALLBACK_TYPE fn_usercallback)
//{
//	bMonitor = true;
//	m_thread = new std::thread(&F4IReader::Monitor, this, fn_usercallback);
//}
//
//
//void F4IReader::StopMonitor()
//{
//	bMonitor = false;
//	if (m_thread->joinable())
//	{
//		m_thread->join();
//	}
//}
//
//void F4IReader::Monitor3DWrap(F4IREADER_CALLBACK_TYPE fn_usercallback)
//{
//	bool bIn3D;
//	bool bIsExitGame;
//	bool bSucceeded;
//
//	while(Monitor3D(bSucceeded, bIn3D, bIsExitGame, bSucceeded))
//	{
//		fn_usercallback(bSucceeded, bIn3D, bIsExitGame);
//	}
//}
//
//void F4IReader::Monitor(F4IREADER_CALLBACK_TYPE fn_usercallback)
//{
//	bool bTemp3D;
//	bool bTempExit = false;
//	bool bFirst = true;
//	bool bOld3D;
//
//	bMonitor = true;
//
//	while (bMonitor)
//	{
//		if (!peekVariables(bTemp3D, bTempExit))
//		{
//			fn_usercallback(this, false, bTemp3D, bTempExit);
//			return;
//		}
//
//		if (bTempExit)
//		{
//			bIsExitGame = bTempExit;
//
//			bMonitor = false;
//			fn_usercallback(this, false, false, false);
//			SetConsoleTitle("Exiting Falcon BMS detected..."); // Change to an IO function in the manager.
//			return;
//		}
//
//		if (bFirst)
//		{
//			bMonitor = true;
//			bOld3D = bTemp3D;
//			bFirst = false;
//		}
//		else if (bTemp3D != bOld3D)
//		{
//			bIn3D = bTemp3D;
//			bMonitor = false;
//			DisconnectSharedMemory();
//			SetConsoleTitle("3D change in Falcon BMS detected..."); // Change to an IO function in the manager.
//			return true;
//		}
//		SleepEx(m_dwSleepDelay, FALSE);
//	}
//	// We didn't get a result, and we got kicked out of the loop. That means someone called StopMonitor(), or something crazy happened.
//	DisconnectSharedMemory();
//	return false;
//}

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