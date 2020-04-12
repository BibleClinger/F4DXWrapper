#pragma once

#include "d3d9_main.h"

namespace D9Wrapper
{
	class IDirect3D9 : public IUnknown //ID9WrapperUnknown
	{
	protected:
		D9Real::IDirect3D9* m_IDirect3D9;
	public:
		IDirect3D9(D9Real::IDirect3D9* direct3d)
		{
			m_IDirect3D9 = direct3d;
		}

		/*** IUnknown methods ***/
		STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
		STDMETHOD_(ULONG, AddRef)(THIS);
		STDMETHOD_(ULONG, Release)(THIS);
		/*** IDirect3D9 methods ***/
		STDMETHOD(RegisterSoftwareDevice)(THIS_ void* pInitializeFunction);
		STDMETHOD_(UINT, GetAdapterCount)(THIS);
		STDMETHOD(GetAdapterIdentifier)(THIS_ UINT Adapter, DWORD Flags, D9Real::D3DADAPTER_IDENTIFIER9* pIdentifier);
		STDMETHOD_(UINT, GetAdapterModeCount)(THIS_ UINT Adapter, D9Real::D3DFORMAT Format);
		STDMETHOD(EnumAdapterModes)(THIS_ UINT Adapter, D9Real::D3DFORMAT Format, UINT Mode, D9Real::D3DDISPLAYMODE* pMode);
		STDMETHOD(GetAdapterDisplayMode)(THIS_ UINT Adapter, D9Real::D3DDISPLAYMODE* pMode);
		STDMETHOD(CheckDeviceType)(THIS_ UINT iAdapter, D9Real::D3DDEVTYPE DevType, D9Real::D3DFORMAT DisplayFormat, D9Real::D3DFORMAT BackBufferFormat, BOOL bWindowed);
		STDMETHOD(CheckDeviceFormat)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT AdapterFormat, DWORD Usage, D9Real::D3DRESOURCETYPE RType, D9Real::D3DFORMAT CheckFormat);
		STDMETHOD(CheckDeviceMultiSampleType)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT SurfaceFormat, BOOL Windowed, D9Real::D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels);
		STDMETHOD(CheckDepthStencilMatch)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT AdapterFormat, D9Real::D3DFORMAT RenderTargetFormat, D9Real::D3DFORMAT DepthStencilFormat);
		STDMETHOD(CheckDeviceFormatConversion)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT SourceFormat, D9Real::D3DFORMAT TargetFormat);
		STDMETHOD(GetDeviceCaps)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DCAPS9* pCaps);
		STDMETHOD_(HMONITOR, GetAdapterMonitor)(THIS_ UINT Adapter);
		STDMETHOD(CreateDevice)(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Wrapper::IDirect3DDevice9** ppReturnedDeviceInterface);
	};
}