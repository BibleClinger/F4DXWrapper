#include "d3d11_main.h"

inline static const char* szRealDLLPath = "C:\\Windows\\system32\\d3d11.dll";

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	(void)hinstDLL; // Unreferences formal parameter.
	(void)lpvReserved; // Unreferences formal parameter.

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		return TRUE;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return FALSE;
}

