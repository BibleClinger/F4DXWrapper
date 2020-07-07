#include "d3d9_main.h"
#include "IDirect3D9Ex.h" // This header needs to be specifically included, because we create an instance with new.

inline static const char* szRealDLLPath = "C:\\Windows\\system32\\d3d9.dll";

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

D9Wrapper::IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
#pragma F4DX_EXPORT
	// BMS never calls this function as of 4.33.0 to 4.34.3, but it needs to be found as anyway as part of the d3d9.dll.
	// It's implemented anyway, since it's not difficult.
	F4DX_manager& m = F4DX_manager::getManager();
	fnDirect3DCreate9 real_Direct3DCreate9 = nullptr;
	D9Real::IDirect3D9 * pRIDirect3D9 = nullptr;
	D9Wrapper::IDirect3D9 * pWIDirect3D9 = nullptr;

	real_Direct3DCreate9 = reinterpret_cast<fnDirect3DCreate9>(m.loadFunction(szRealDLLPath, "Direct3DCreate9"));
	if (!real_Direct3DCreate9)
	{
		return nullptr;
	}
	pRIDirect3D9 = real_Direct3DCreate9(SDKVersion);
	if (pRIDirect3D9)
	{
		pWIDirect3D9 = new D9Wrapper::IDirect3D9(pRIDirect3D9);
	}
	return pWIDirect3D9;
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, D9Wrapper::IDirect3D9Ex** ppWIDirect3D9Ex)
{
#pragma F4DX_EXPORT
	F4DX_manager& m = F4DX_manager::getManager();
	fnDirect3DCreate9Ex real_Direct3DCreate9Ex = nullptr;
	D9Real::IDirect3D9Ex* pRIDirect3D9Ex = nullptr;
	HRESULT hr;
	
	real_Direct3DCreate9Ex = reinterpret_cast<fnDirect3DCreate9Ex>(m.loadFunction(szRealDLLPath, "Direct3DCreate9Ex"));
	if (!real_Direct3DCreate9Ex)
	{
		*ppWIDirect3D9Ex = nullptr;
		return D3DERR_NOTAVAILABLE;
	}
	hr = real_Direct3DCreate9Ex(SDKVersion, &pRIDirect3D9Ex);
	if (hr == S_OK)
	{
		*ppWIDirect3D9Ex = new D9Wrapper::IDirect3D9Ex(pRIDirect3D9Ex);
	}
	return hr;
}