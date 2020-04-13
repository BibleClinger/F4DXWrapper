#include "d3d9_manager.h"

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	(void)lpvReserved; // Unreferences formal parameter.

	switch (fdwReason)
	{
	case DLL_PROCESS_ATTACH:
		d3d9_manager::getManager().setDLL(hinstDLL);
		return TRUE;
	case DLL_PROCESS_DETACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
		break;
	}
	return FALSE;
}