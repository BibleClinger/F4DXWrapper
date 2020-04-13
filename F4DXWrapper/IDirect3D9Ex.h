#pragma once

#include "IDirect3D9.h"

namespace D9Wrapper
{
	class IDirect3DDevice9Ex;

	class IDirect3D9Ex : public IDirect3D9
	{
	protected:
		D9Real::IDirect3D9Ex *m_IDirect3D9Ex;
	public:
		IDirect3D9Ex(D9Real::IDirect3D9Ex* direct3d) : IDirect3D9(direct3d)
		{
			m_IDirect3D9Ex = direct3d; // This points to the same object as inherited member m_IDirect3D9.
		}

		STDMETHOD_(UINT, GetAdapterModeCountEx)(THIS_ UINT Adapter, CONST D9Real::D3DDISPLAYMODEFILTER* pFilter);
		STDMETHOD(EnumAdapterModesEx)(THIS_ UINT Adapter, CONST D9Real::D3DDISPLAYMODEFILTER* pFilter, UINT Mode, D9Real::D3DDISPLAYMODEEX* pMode);
		STDMETHOD(GetAdapterDisplayModeEx)(THIS_ UINT Adapter, D9Real::D3DDISPLAYMODEEX* pMode, D9Real::D3DDISPLAYROTATION* pRotation);
		STDMETHOD(CreateDeviceEx)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::D3DDISPLAYMODEEX* pFullscreenDisplayMode, IDirect3DDevice9Ex** ppReturnedDeviceInterface);
		STDMETHOD(GetAdapterLUID)(THIS_ UINT Adapter, LUID* pLUID);
	};
}