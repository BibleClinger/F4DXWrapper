#include "d3d9_manager.h"
#include "IDirect3D9.h"
#include "IDirect3D9Ex.h"

D9Wrapper::IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion)
{
#pragma D9EXPORT
	// BMS never calls this function as of 4.33.0 to 4.34.3, but it needs to be found as anyway as part of the d3d9.dll.
	// It's implemented anyway, since it's not difficult.
	d3d9_manager& m = d3d9_manager::getManager();
	D9Real::IDirect3D9 * pRIDirect3D9 = nullptr;
	D9Wrapper::IDirect3D9 * pWIDirect3D9 = nullptr;

	pRIDirect3D9 = (m.getRealCreate9fn())(SDKVersion);
	if(pRIDirect3D9)
	{
		pWIDirect3D9 = new D9Wrapper::IDirect3D9(pRIDirect3D9);
	}
	return pWIDirect3D9;
}

HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, D9Wrapper::IDirect3D9Ex** ppWIDirect3D9Ex)
{
#pragma D9EXPORT
	d3d9_manager& m = d3d9_manager::getManager();
	D9Real::IDirect3D9Ex* pRIDirect3D9Ex = nullptr;
	HRESULT hr;
	
	hr = (m.getRealCreate9Exfn())(SDKVersion, &pRIDirect3D9Ex);
	if (hr == S_OK)
	{
		*ppWIDirect3D9Ex = new D9Wrapper::IDirect3D9Ex(pRIDirect3D9Ex);
	}
	return hr;
}