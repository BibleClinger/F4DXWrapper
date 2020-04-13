#pragma once

#include "IDirect3DDevice9.h"

namespace D9Wrapper
{
	class IDirect3DDevice9Ex : public IDirect3DDevice9
	{
	private:
		D9Real::IDirect3DDevice9Ex *m_IDirect3DDevice9Ex;
	public:
		IDirect3DDevice9Ex(D9Real::IDirect3DDevice9Ex* device, IDirect3D9* direct3d) : IDirect3DDevice9(static_cast<D9Real::IDirect3DDevice9*>(device), direct3d)
		{
			m_IDirect3DDevice9Ex = device;
		}

		STDMETHOD(SetConvolutionMonoKernel)(THIS_ UINT width, UINT height, float* rows, float* columns);
		STDMETHOD(ComposeRects)(THIS_ D9Real::IDirect3DSurface9* pSrc, D9Real::IDirect3DSurface9* pDst, D9Real::IDirect3DVertexBuffer9* pSrcRectDescs, UINT NumRects, D9Real::IDirect3DVertexBuffer9* pDstRectDescs, D9Real::D3DCOMPOSERECTSOP Operation, int Xoffset, int Yoffset);
		STDMETHOD(PresentEx)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags);
		STDMETHOD(GetGPUThreadPriority)(THIS_ INT* pPriority);
		STDMETHOD(SetGPUThreadPriority)(THIS_ INT Priority);
		STDMETHOD(WaitForVBlank)(THIS_ UINT iSwapChain);
		STDMETHOD(CheckResourceResidency)(THIS_ D9Real::IDirect3DResource9** pResourceArray, UINT32 NumResources);
		STDMETHOD(SetMaximumFrameLatency)(THIS_ UINT MaxLatency);
		STDMETHOD(GetMaximumFrameLatency)(THIS_ UINT* pMaxLatency);
		STDMETHOD(CheckDeviceState)(THIS_ HWND hDestinationWindow);
		STDMETHOD(CreateRenderTargetEx)(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage);
		STDMETHOD(CreateOffscreenPlainSurfaceEx)(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage);
		STDMETHOD(CreateDepthStencilSurfaceEx)(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage);
		STDMETHOD(ResetEx)(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::D3DDISPLAYMODEEX* pFullscreenDisplayMode);
		STDMETHOD(GetDisplayModeEx)(THIS_ UINT iSwapChain, D9Real::D3DDISPLAYMODEEX* pMode, D9Real::D3DDISPLAYROTATION* pRotation);
	};
}