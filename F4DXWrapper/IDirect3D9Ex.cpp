#include "IDirect3D9Ex.h"
#include "IDirect3DDevice9Ex.h"

#pragma warning(push)
#pragma warning(disable : 26812) // Temporarily disable warnings over enums not being enum classes

namespace D9Wrapper
{
	STDMETHODIMP_(UINT) IDirect3D9Ex::GetAdapterModeCountEx(THIS_ UINT Adapter, CONST D9Real::D3DDISPLAYMODEFILTER* pFilter)
	{
		return m_IDirect3D9Ex->GetAdapterModeCountEx(Adapter, pFilter);
	}
	STDMETHODIMP IDirect3D9Ex::EnumAdapterModesEx(THIS_ UINT Adapter, CONST D9Real::D3DDISPLAYMODEFILTER* pFilter, UINT Mode, D9Real::D3DDISPLAYMODEEX* pMode)
	{
		return m_IDirect3D9Ex->EnumAdapterModesEx(Adapter, pFilter, Mode, pMode);
	}
	STDMETHODIMP IDirect3D9Ex::GetAdapterDisplayModeEx(THIS_ UINT Adapter, D9Real::D3DDISPLAYMODEEX* pMode, D9Real::D3DDISPLAYROTATION* pRotation)
	{
		return m_IDirect3D9Ex->GetAdapterDisplayModeEx(Adapter, pMode, pRotation);
	}
	STDMETHODIMP IDirect3D9Ex::CreateDeviceEx(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface)
	{
		HRESULT hr;
		D9Real::IDirect3DDevice9Ex* real_ppReturnedDeviceInterface;

		hr = m_IDirect3D9Ex->CreateDeviceEx(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, pFullscreenDisplayMode, &real_ppReturnedDeviceInterface);
		if (hr == D3D_OK)
		{
			*ppReturnedDeviceInterface = new IDirect3DDevice9Ex(real_ppReturnedDeviceInterface, this);
		}
		else *ppReturnedDeviceInterface = nullptr;
		return hr;
	}
	STDMETHODIMP IDirect3D9Ex::GetAdapterLUID(THIS_ UINT Adapter, LUID* pLUID)
	{
		return m_IDirect3D9Ex->GetAdapterLUID(Adapter, pLUID);
	}
}

#pragma warning(pop)