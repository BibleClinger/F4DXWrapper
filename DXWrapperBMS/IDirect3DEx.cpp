#include "IDirect3D9Ex.h"
#include "IDirect3DDevice9Ex.h"

namespace D9Wrapper
{
	IDirect3D9Ex::IDirect3D9Ex(D9Real::IDirect3D9Ex* obj) : IDirect3D9(obj)
	{
		m_IDirect3D9Ex = obj;
	}

	// IUnknown methods
	STDMETHODIMP IDirect3D9Ex::QueryInterface(THIS_ REFIID riid, void** ppvObj)
	{
		return m_IDirect3D9Ex->QueryInterface(riid, ppvObj);
	}
	STDMETHODIMP_(ULONG) IDirect3D9Ex::AddRef(THIS)
	{
		return m_IDirect3D9Ex->AddRef();
	}
	STDMETHODIMP_(ULONG) IDirect3D9Ex::Release(THIS)
	{
		return m_IDirect3D9Ex->Release();
	}

	/*** IDirect3D9 methods ***/

	STDMETHODIMP IDirect3D9Ex::RegisterSoftwareDevice(THIS_ void* pInitializeFunction)
	{
		return m_IDirect3D9Ex->RegisterSoftwareDevice(pInitializeFunction);
	}
	STDMETHODIMP_(UINT) IDirect3D9Ex::GetAdapterCount(THIS)
	{
		return m_IDirect3D9Ex->GetAdapterCount();
	}
	STDMETHODIMP IDirect3D9Ex::GetAdapterIdentifier(THIS_ UINT Adapter, DWORD Flags, D9Real::D3DADAPTER_IDENTIFIER9* pIdentifier)
	{
		return m_IDirect3D9Ex->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
	}
	STDMETHODIMP_(UINT) IDirect3D9Ex::GetAdapterModeCount(THIS_ UINT Adapter, D9Real::D3DFORMAT Format)
	{
		return m_IDirect3D9Ex->GetAdapterModeCount(Adapter, Format);
	}
	STDMETHODIMP IDirect3D9Ex::EnumAdapterModes(THIS_ UINT Adapter, D9Real::D3DFORMAT Format, UINT Mode, D9Real::D3DDISPLAYMODE* pMode)
	{
		return m_IDirect3D9Ex->EnumAdapterModes(Adapter, Format, Mode, pMode);
	}
	STDMETHODIMP IDirect3D9Ex::GetAdapterDisplayMode(THIS_ UINT Adapter, D9Real::D3DDISPLAYMODE* pMode)
	{
		return m_IDirect3D9Ex->GetAdapterDisplayMode(Adapter, pMode);
	}
	STDMETHODIMP IDirect3D9Ex::CheckDeviceType(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DevType, D9Real::D3DFORMAT AdapterFormat, D9Real::D3DFORMAT BackBufferFormat, BOOL bWindowed)
	{
		return m_IDirect3D9Ex->CheckDeviceType(Adapter, DevType, AdapterFormat, BackBufferFormat, bWindowed);
	}
	STDMETHODIMP IDirect3D9Ex::CheckDeviceFormat(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT AdapterFormat, DWORD Usage, D9Real::D3DRESOURCETYPE RType, D9Real::D3DFORMAT CheckFormat)
	{
		return m_IDirect3D9Ex->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
	}
	STDMETHODIMP IDirect3D9Ex::CheckDeviceMultiSampleType(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT SurfaceFormat, BOOL Windowed, D9Real::D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
	{
		return m_IDirect3D9Ex->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
	}
	STDMETHODIMP IDirect3D9Ex::CheckDepthStencilMatch(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT AdapterFormat, D9Real::D3DFORMAT RenderTargetFormat, D9Real::D3DFORMAT DepthStencilFormat)
	{
		return m_IDirect3D9Ex->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
	}
	STDMETHODIMP IDirect3D9Ex::CheckDeviceFormatConversion(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT SourceFormat, D9Real::D3DFORMAT TargetFormat)
	{
		return m_IDirect3D9Ex->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
	}
	STDMETHODIMP IDirect3D9Ex::GetDeviceCaps(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DCAPS9* pCaps)
	{
		return m_IDirect3D9Ex->GetDeviceCaps(Adapter, DeviceType, pCaps);
	}
	STDMETHODIMP_(HMONITOR) IDirect3D9Ex::GetAdapterMonitor(THIS_ UINT Adapter)
	{
		return m_IDirect3D9Ex->GetAdapterMonitor(Adapter);
	}
	STDMETHODIMP IDirect3D9Ex::CreateDevice(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
	{
		HRESULT hr;
		D9Real::IDirect3DDevice9* real_ppReturnedDeviceInterface;

		hr = m_IDirect3D9Ex->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &real_ppReturnedDeviceInterface);
		if (hr == D3D_OK)
		{
			*ppReturnedDeviceInterface = new IDirect3DDevice9(real_ppReturnedDeviceInterface, this);
		}
		else *ppReturnedDeviceInterface = NULL;
		return hr;
	}
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
		else *ppReturnedDeviceInterface = NULL;
		return hr;
	}
	STDMETHODIMP IDirect3D9Ex::GetAdapterLUID(THIS_ UINT Adapter, LUID* pLUID)
	{
		return m_IDirect3D9Ex->GetAdapterLUID(Adapter, pLUID);
	}
}