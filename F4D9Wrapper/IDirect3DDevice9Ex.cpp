#include "IDirect3DDevice9Ex.h"
#include "IDirect3D9Ex.h"

#include "F4DX_manager.h"

#pragma warning(push)
#pragma warning(disable : 26812) // Temporarily disable warnings over enums not being enum classes

namespace D9Wrapper
{
	STDMETHODIMP IDirect3DDevice9Ex::SetConvolutionMonoKernel(THIS_ UINT width, UINT height, float* rows, float* columns) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->SetConvolutionMonoKernel(width, height, rows, columns);
	}
	STDMETHODIMP IDirect3DDevice9Ex::ComposeRects(THIS_ D9Real::IDirect3DSurface9* pSrc, D9Real::IDirect3DSurface9* pDst, D9Real::IDirect3DVertexBuffer9* pSrcRectDescs, UINT NumRects, D9Real::IDirect3DVertexBuffer9* pDstRectDescs, D9Real::D3DCOMPOSERECTSOP Operation, int Xoffset, int Yoffset) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->ComposeRects(pSrc, pDst, pSrcRectDescs, NumRects, pDstRectDescs, Operation, Xoffset, Yoffset);
	}
	STDMETHODIMP IDirect3DDevice9Ex::PresentEx(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags) noexcept(true)
	{
		//d3d9_manager::getManager().getFPS().AddFrameCount();
		// Add FPS tracking code here if interested...
		if (bInsideScene)
		{
			return D3DERR_INVALIDCALL;
		}
		if (bSceneHandledByWrapper)
		{
			return D3D_OK;
		}
		else return m_IDirect3DDevice9Ex->PresentEx(pSourceRect,pDestRect,hDestWindowOverride,pDirtyRegion,dwFlags);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetGPUThreadPriority(THIS_ INT* pPriority) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->GetGPUThreadPriority(pPriority);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetGPUThreadPriority(THIS_ INT Priority) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->SetGPUThreadPriority(Priority);
	}
	STDMETHODIMP IDirect3DDevice9Ex::WaitForVBlank(THIS_ UINT iSwapChain) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->WaitForVBlank(iSwapChain);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CheckResourceResidency(THIS_ D9Real::IDirect3DResource9** pResourceArray, UINT32 NumResources) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->CheckResourceResidency(pResourceArray, NumResources);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetMaximumFrameLatency(THIS_ UINT MaxLatency) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->SetMaximumFrameLatency(MaxLatency);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetMaximumFrameLatency(THIS_ UINT* pMaxLatency) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->GetMaximumFrameLatency(pMaxLatency);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CheckDeviceState(THIS_ HWND hDestinationWindow) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->CheckDeviceState(hDestinationWindow);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateRenderTargetEx(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->CreateRenderTargetEx(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle, Usage);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateOffscreenPlainSurfaceEx(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->CreateOffscreenPlainSurfaceEx(Width,Height,Format, Pool, ppSurface, pSharedHandle, Usage);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateDepthStencilSurfaceEx(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->CreateDepthStencilSurfaceEx(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle, Usage);
	}
	STDMETHODIMP IDirect3DDevice9Ex::ResetEx(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::D3DDISPLAYMODEEX* pFullscreenDisplayMode) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->ResetEx(pPresentationParameters, pFullscreenDisplayMode);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetDisplayModeEx(THIS_ UINT iSwapChain, D9Real::D3DDISPLAYMODEEX* pMode, D9Real::D3DDISPLAYROTATION* pRotation) noexcept(true)
	{
		return m_IDirect3DDevice9Ex->GetDisplayModeEx(iSwapChain, pMode, pRotation);
	}
}

#pragma warning(pop)