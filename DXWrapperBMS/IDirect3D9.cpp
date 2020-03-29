#include "IDirect3D9.h"
#include "IDirect3DDevice9.h"

namespace D9Wrapper
{
	IDirect3D9::IDirect3D9(D9Real::IDirect3D9* obj)
	{
		m_IDirect3D9 = obj;
	}

	STDMETHODIMP IDirect3D9::QueryInterface(THIS_ REFIID riid, void** ppvObj)
	{
		return m_IDirect3D9->QueryInterface(riid, ppvObj);
	}
	STDMETHODIMP_(ULONG) IDirect3D9::AddRef(THIS)
	{
		return m_IDirect3D9->AddRef();
	}
	STDMETHODIMP_(ULONG) IDirect3D9::Release(THIS)
	{
		return m_IDirect3D9->Release();
	}

	STDMETHODIMP IDirect3D9::RegisterSoftwareDevice(THIS_ void* pInitializeFunction)
	{
		return m_IDirect3D9->RegisterSoftwareDevice(pInitializeFunction);
	}

	STDMETHODIMP_(UINT) IDirect3D9::GetAdapterCount(THIS)
	{
		return m_IDirect3D9->GetAdapterCount();
	}

	STDMETHODIMP IDirect3D9::GetAdapterIdentifier(THIS_ UINT Adapter, DWORD Flags, D9Real::D3DADAPTER_IDENTIFIER9* pIdentifier)
	{
		return m_IDirect3D9->GetAdapterIdentifier(Adapter, Flags, pIdentifier);
	}

	STDMETHODIMP_(UINT) IDirect3D9::GetAdapterModeCount(THIS_ UINT Adapter, D9Real::D3DFORMAT Format)
	{
		return m_IDirect3D9->GetAdapterModeCount(Adapter, Format);
	}

	STDMETHODIMP IDirect3D9::EnumAdapterModes(THIS_ UINT Adapter, D9Real::D3DFORMAT Format, UINT Mode, D9Real::D3DDISPLAYMODE* pMode)
	{
		return m_IDirect3D9->EnumAdapterModes(Adapter, Format, Mode, pMode);
	}

	STDMETHODIMP IDirect3D9::GetAdapterDisplayMode(THIS_ UINT Adapter, D9Real::D3DDISPLAYMODE* pMode)
	{
		return m_IDirect3D9->GetAdapterDisplayMode(Adapter, pMode);
	}

	STDMETHODIMP IDirect3D9::CheckDeviceType(THIS_ UINT iAdapter, D9Real::D3DDEVTYPE DevType, D9Real::D3DFORMAT DisplayFormat, D9Real::D3DFORMAT BackBufferFormat, BOOL bWindowed)
	{
		return m_IDirect3D9->CheckDeviceType(iAdapter, DevType, DisplayFormat, BackBufferFormat, bWindowed);
	}

	STDMETHODIMP IDirect3D9::CheckDeviceFormat(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT AdapterFormat, DWORD Usage, D9Real::D3DRESOURCETYPE RType, D9Real::D3DFORMAT CheckFormat)
	{
		return m_IDirect3D9->CheckDeviceFormat(Adapter, DeviceType, AdapterFormat, Usage, RType, CheckFormat);
	}

	STDMETHODIMP IDirect3D9::CheckDeviceMultiSampleType(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT SurfaceFormat, BOOL Windowed, D9Real::D3DMULTISAMPLE_TYPE MultiSampleType, DWORD* pQualityLevels)
	{
		return m_IDirect3D9->CheckDeviceMultiSampleType(Adapter, DeviceType, SurfaceFormat, Windowed, MultiSampleType, pQualityLevels);
	}

	STDMETHODIMP IDirect3D9::CheckDepthStencilMatch(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT AdapterFormat, D9Real::D3DFORMAT RenderTargetFormat, D9Real::D3DFORMAT DepthStencilFormat)
	{
		return m_IDirect3D9->CheckDepthStencilMatch(Adapter, DeviceType, AdapterFormat, RenderTargetFormat, DepthStencilFormat);
	}

	STDMETHODIMP IDirect3D9::CheckDeviceFormatConversion(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DFORMAT SourceFormat, D9Real::D3DFORMAT TargetFormat)
	{
		return m_IDirect3D9->CheckDeviceFormatConversion(Adapter, DeviceType, SourceFormat, TargetFormat);
	}

	STDMETHODIMP IDirect3D9::GetDeviceCaps(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, D9Real::D3DCAPS9* pCaps)
	{
		return m_IDirect3D9->GetDeviceCaps(Adapter, DeviceType, pCaps);
	}

	STDMETHODIMP_(HMONITOR) IDirect3D9::GetAdapterMonitor(THIS_ UINT Adapter)
	{
		return m_IDirect3D9->GetAdapterMonitor(Adapter);
	}

	STDMETHODIMP IDirect3D9::CreateDevice(THIS_ UINT Adapter, D9Real::D3DDEVTYPE DeviceType, HWND hFocusWindow, DWORD BehaviorFlags, D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, IDirect3DDevice9** ppReturnedDeviceInterface)
	{
		HRESULT hr;
		D9Real::IDirect3DDevice9* real_pReturnedDeviceInterface;

		hr = m_IDirect3D9->CreateDevice(Adapter, DeviceType, hFocusWindow, BehaviorFlags, pPresentationParameters, &real_pReturnedDeviceInterface);
		if (hr == D3D_OK)
		{
			*ppReturnedDeviceInterface = new IDirect3DDevice9(real_pReturnedDeviceInterface, NULL);
		}
		else *ppReturnedDeviceInterface = NULL;
		return hr;
	}
}