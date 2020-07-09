#pragma once

#include "F4DX_common.h"

// All entry points except for DLLMain() should be declared in this file.

namespace D11Real
{
#include <d3d11.h>
}
/*
namespace D9Wrapper
{
	class IDirect3D9;
	class IDirect3D9Ex;
	class IDirect3DDevice9;
	class IDirect3DDevice9Ex;
}
*/
// Typedefs

//typedef D9Real::IDirect3D9* (WINAPI* fnDirect3DCreate9)(UINT);
//typedef HRESULT(WINAPI* fnDirect3DCreate9Ex)(UINT, D9Real::IDirect3D9Ex**);

typedef HRESULT(WINAPI* fnD3D11CreateDevice)(D11Real::IDXGIAdapter* pAdapter,
	D11Real::D3D_DRIVER_TYPE         DriverType,
	HMODULE                 Software,
	UINT                    Flags,
	const D11Real::D3D_FEATURE_LEVEL* pFeatureLevels,
	UINT                    FeatureLevels,
	UINT                    SDKVersion,
	D11Real::ID3D11Device** ppDevice,
	D11Real::D3D_FEATURE_LEVEL* pFeatureLevel,
	D11Real::ID3D11DeviceContext** ppImmediateContext);

typedef HRESULT (WINAPI * fnD3D11CreateDeviceAndSwapChain)(
	D11Real::IDXGIAdapter* pAdapter,
	D11Real::D3D_DRIVER_TYPE            DriverType,
	HMODULE                    Software,
	UINT                       Flags,
	const D11Real::D3D_FEATURE_LEVEL* pFeatureLevels,
	UINT                       FeatureLevels,
	UINT                       SDKVersion,
	const D11Real::DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
	D11Real::IDXGISwapChain** ppSwapChain,
	D11Real::ID3D11Device** ppDevice,
	D11Real::D3D_FEATURE_LEVEL* pFeatureLevel,
	D11Real::ID3D11DeviceContext** ppImmediateContext
);

// DX9 Hook function

HRESULT D3D11CreateDevice(
	D11Real::IDXGIAdapter* pAdapter,
	D11Real::D3D_DRIVER_TYPE         DriverType,
	HMODULE                 Software,
	UINT                    Flags,
	const D11Real::D3D_FEATURE_LEVEL* pFeatureLevels,
	UINT                    FeatureLevels,
	UINT                    SDKVersion,
	D11Real::ID3D11Device** ppDevice,
	D11Real::D3D_FEATURE_LEVEL* pFeatureLevel,
	D11Real::ID3D11DeviceContext** ppImmediateContext
);

HRESULT D3D11CreateDeviceAndSwapChain(
	D11Real::IDXGIAdapter* pAdapter,
	D11Real::D3D_DRIVER_TYPE            DriverType,
	HMODULE                    Software,
	UINT                       Flags,
	const D11Real::D3D_FEATURE_LEVEL* pFeatureLevels,
	UINT                       FeatureLevels,
	UINT                       SDKVersion,
	const D11Real::DXGI_SWAP_CHAIN_DESC* pSwapChainDesc,
	D11Real::IDXGISwapChain** ppSwapChain,
	D11Real::ID3D11Device** ppDevice,
	D11Real::D3D_FEATURE_LEVEL* pFeatureLevel,
	D11Real::ID3D11DeviceContext** ppImmediateContext
);