#include "d3d11_main.h"
#include "ID3D11DeviceContext.h" // This header needs to be specifically included, because we create an instance with new.

// All entry points should be defined in this file.

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

HRESULT D3D11CreateDevice(D11Real::IDXGIAdapter* pAdapter, D11Real::D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D11Real::D3D_FEATURE_LEVEL* pFeatureLevels,	UINT FeatureLevels, UINT SDKVersion, D11Real::ID3D11Device** ppDevice, D11Real::D3D_FEATURE_LEVEL* pFeatureLevel, D11Wrapper::ID3D11DeviceContext** ppImmediateContext)
{
#pragma F4DX_EXPORT
	fnD3D11CreateDevice real_D3D11CreateDevice = nullptr;
	HRESULT hr;
	D11Real::ID3D11DeviceContext *ppRealImmediateContext;

	real_D3D11CreateDevice = reinterpret_cast<fnD3D11CreateDevice>(F4DX_manager::getManager().loadFunction(szRealDLLPath, "D3D11CreateDevice"));
	if (!real_D3D11CreateDevice)
	{
		*ppDevice = nullptr;
		*ppImmediateContext = nullptr;
		return E_FAIL; // For now, we return E_FAIL, because we can't even find the real d3d11.dll. Something is wrong.
	}
	hr = real_D3D11CreateDevice(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, ppDevice, pFeatureLevel, &ppRealImmediateContext);
	if (hr == S_OK)
	{
		// This is where we want to hook.
		*ppImmediateContext = new D11Wrapper::ID3D11DeviceContext(ppRealImmediateContext);
	}
	return hr;
}

HRESULT D3D11CreateDeviceAndSwapChain(D11Real::IDXGIAdapter* pAdapter, D11Real::D3D_DRIVER_TYPE DriverType, HMODULE Software, UINT Flags, const D11Real::D3D_FEATURE_LEVEL* pFeatureLevels,	UINT FeatureLevels, UINT SDKVersion, const D11Real::DXGI_SWAP_CHAIN_DESC* pSwapChainDesc, D11Real::IDXGISwapChain** ppSwapChain, D11Real::ID3D11Device** ppDevice, D11Real::D3D_FEATURE_LEVEL* pFeatureLevel, D11Wrapper::ID3D11DeviceContext** ppImmediateContext)
{
#pragma F4DX_EXPORT
	fnD3D11CreateDeviceAndSwapChain real_D3D11CreateDeviceAndSwapChain = nullptr;
	HRESULT hr;
	D11Real::ID3D11DeviceContext* ppRealImmediateContext;

	real_D3D11CreateDeviceAndSwapChain = reinterpret_cast<fnD3D11CreateDeviceAndSwapChain>(F4DX_manager::getManager().loadFunction(szRealDLLPath, "D3D11CreateDeviceAndSwapChain"));
	if (!real_D3D11CreateDeviceAndSwapChain)
	{
		*ppSwapChain = nullptr;
		*ppDevice = nullptr;
		*ppImmediateContext = nullptr;
		return E_FAIL; // For now, we return E_FAIL, because we can't even find the real d3d11.dll. Something is wrong.
	}
	hr = real_D3D11CreateDeviceAndSwapChain(pAdapter, DriverType, Software, Flags, pFeatureLevels, FeatureLevels, SDKVersion, pSwapChainDesc, ppSwapChain, ppDevice, pFeatureLevel, &ppRealImmediateContext);
	if (hr == S_OK)
	{
		// This is where we want to hook.
		*ppImmediateContext = new D11Wrapper::ID3D11DeviceContext(ppRealImmediateContext);
	}
	return hr;
}