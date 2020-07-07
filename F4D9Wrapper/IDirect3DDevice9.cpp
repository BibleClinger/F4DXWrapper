#include "IDirect3DDevice9.h"
#include "IDirect3D9.h"

#include "F4DX_manager.h"

#pragma warning(push)
#pragma warning(disable : 26812) // Temporarily disable warnings over enums not being enum classes

namespace D9Wrapper
{
	// IUnknown methods 
	STDMETHODIMP IDirect3DDevice9::QueryInterface(THIS_ REFIID riid, void** ppvObj) noexcept(true)
	{
		return m_IDirect3DDevice9->QueryInterface(riid, ppvObj);
	}
	STDMETHODIMP_(ULONG) IDirect3DDevice9::AddRef(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->AddRef();
	}
	STDMETHODIMP_(ULONG) IDirect3DDevice9::Release(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->Release();
	}
	// IDirect3DDevice9 methods

	STDMETHODIMP IDirect3DDevice9::TestCooperativeLevel(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->TestCooperativeLevel();
	}
	STDMETHODIMP_(UINT) IDirect3DDevice9::GetAvailableTextureMem(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->GetAvailableTextureMem();
	}
	STDMETHODIMP IDirect3DDevice9::EvictManagedResources(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->EvictManagedResources();
	}
	STDMETHODIMP IDirect3DDevice9::GetDirect3D(THIS_ IDirect3D9** ppD3D9) noexcept(true)
	{
		if (m_IDirect3D9 != nullptr)
		{
			m_IDirect3D9->AddRef(); // We have to add a ref directly, since we are NOT passing this on to m_IDirect3DDevice9.
			*ppD3D9 = m_IDirect3D9;
			return D3D_OK;
		}
		else return D3DERR_INVALIDCALL;
	}
	STDMETHODIMP IDirect3DDevice9::GetDeviceCaps(THIS_ D9Real::D3DCAPS9* pCaps) noexcept(true)
	{
		return m_IDirect3DDevice9->GetDeviceCaps(pCaps);
	}
	STDMETHODIMP IDirect3DDevice9::GetDisplayMode(THIS_ UINT iSwapChain, D9Real::D3DDISPLAYMODE* pMode) noexcept(true)
	{
		return m_IDirect3DDevice9->GetDisplayMode(iSwapChain, pMode);
	}
	STDMETHODIMP IDirect3DDevice9::GetCreationParameters(THIS_ D9Real::D3DDEVICE_CREATION_PARAMETERS* pParameters) noexcept(true)
	{
		return m_IDirect3DDevice9->GetCreationParameters(pParameters);
	}
	STDMETHODIMP IDirect3DDevice9::SetCursorProperties(THIS_ UINT XHotSpot, UINT YHotSpot, D9Real::IDirect3DSurface9* pCursorBitmap) noexcept(true)
	{
		return m_IDirect3DDevice9->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
	}
	STDMETHODIMP_(void) IDirect3DDevice9::SetCursorPosition(THIS_ int X, int Y, DWORD Flags) noexcept(true)
	{
		return m_IDirect3DDevice9->SetCursorPosition(X, Y, Flags);
	}
	STDMETHODIMP_(BOOL) IDirect3DDevice9::ShowCursor(THIS_ BOOL bShow) noexcept(true)
	{
		return m_IDirect3DDevice9->ShowCursor(bShow);
	}
	STDMETHODIMP IDirect3DDevice9::CreateAdditionalSwapChain(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::IDirect3DSwapChain9** pSwapChain) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
	}
	STDMETHODIMP IDirect3DDevice9::GetSwapChain(THIS_ UINT iSwapChain, D9Real::IDirect3DSwapChain9** pSwapChain) noexcept(true)
	{
		return m_IDirect3DDevice9->GetSwapChain(iSwapChain, pSwapChain);
	}
	STDMETHODIMP_(UINT) IDirect3DDevice9::GetNumberOfSwapChains(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->GetNumberOfSwapChains();
	}
	STDMETHODIMP IDirect3DDevice9::Reset(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters) noexcept(true)
	{
		return m_IDirect3DDevice9->Reset(pPresentationParameters);
	}
	STDMETHODIMP IDirect3DDevice9::Present(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion) noexcept(true)
	{
		//F4DX_manager::getManager().getFPS().AddFrameCount();
		// If calculating FPS ourselves, we should do it here.
		if (bInsideScene)
		{
			return D3DERR_INVALIDCALL;
		}
		if (bSceneHandledByWrapper)
		{
			return D3D_OK;
		}
		else return m_IDirect3DDevice9->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	}
	STDMETHODIMP IDirect3DDevice9::GetBackBuffer(THIS_ UINT iSwapChain, UINT iBackBuffer, D9Real::D3DBACKBUFFER_TYPE Type, D9Real::IDirect3DSurface9** ppBackBuffer) noexcept(true)
	{
		return m_IDirect3DDevice9->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
	}
	STDMETHODIMP IDirect3DDevice9::GetRasterStatus(THIS_ UINT iSwapChain, D9Real::D3DRASTER_STATUS* pRasterStatus) noexcept(true)
	{
		return m_IDirect3DDevice9->GetRasterStatus(iSwapChain, pRasterStatus);
	}
	STDMETHODIMP IDirect3DDevice9::SetDialogBoxMode(THIS_ BOOL bEnableDialogs) noexcept(true)
	{
		return m_IDirect3DDevice9->SetDialogBoxMode(bEnableDialogs);
	}
	STDMETHODIMP_(void) IDirect3DDevice9::SetGammaRamp(THIS_ UINT iSwapChain, DWORD Flags, CONST D9Real::D3DGAMMARAMP* pRamp) noexcept(true)
	{
		return m_IDirect3DDevice9->SetGammaRamp(iSwapChain, Flags, pRamp);
	}
	STDMETHODIMP_(void) IDirect3DDevice9::GetGammaRamp(THIS_ UINT iSwapChain, D9Real::D3DGAMMARAMP* pRamp) noexcept(true)
	{
		return m_IDirect3DDevice9->GetGammaRamp(iSwapChain, pRamp);
	}
	STDMETHODIMP IDirect3DDevice9::CreateTexture(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateVolumeTexture(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateCubeTexture(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateVertexBuffer(THIS_ UINT Length, DWORD Usage, DWORD FVF, D9Real::D3DPOOL Pool, D9Real::IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateIndexBuffer(THIS_ UINT Length, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateRenderTarget(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateDepthStencilSurface(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::UpdateSurface(THIS_ D9Real::IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, D9Real::IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint) noexcept(true)
	{
		return m_IDirect3DDevice9->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
	}
	STDMETHODIMP IDirect3DDevice9::UpdateTexture(THIS_ D9Real::IDirect3DBaseTexture9* pSourceTexture, D9Real::IDirect3DBaseTexture9* pDestinationTexture) noexcept(true)
	{
		return m_IDirect3DDevice9->UpdateTexture(pSourceTexture, pDestinationTexture);
	}
	STDMETHODIMP IDirect3DDevice9::GetRenderTargetData(THIS_ D9Real::IDirect3DSurface9* pRenderTarget, D9Real::IDirect3DSurface9* pDestSurface) noexcept(true)
	{
		return m_IDirect3DDevice9->GetRenderTargetData(pRenderTarget, pDestSurface);
	}
	STDMETHODIMP IDirect3DDevice9::GetFrontBufferData(THIS_ UINT iSwapChain, D9Real::IDirect3DSurface9* pDestSurface) noexcept(true)
	{
		return m_IDirect3DDevice9->GetFrontBufferData(iSwapChain, pDestSurface);
	}
	STDMETHODIMP IDirect3DDevice9::StretchRect(THIS_ D9Real::IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, D9Real::IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D9Real::D3DTEXTUREFILTERTYPE Filter) noexcept(true)
	{
		return m_IDirect3DDevice9->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
	}
	STDMETHODIMP IDirect3DDevice9::ColorFill(THIS_ D9Real::IDirect3DSurface9* pSurface, CONST RECT* pRect, D9Real::D3DCOLOR color) noexcept(true)
	{
		return m_IDirect3DDevice9->ColorFill(pSurface, pRect, color);
	}
	STDMETHODIMP IDirect3DDevice9::CreateOffscreenPlainSurface(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9::SetRenderTarget(THIS_ DWORD RenderTargetIndex, D9Real::IDirect3DSurface9* pRenderTarget) noexcept(true)
	{
		return m_IDirect3DDevice9->SetRenderTarget(RenderTargetIndex, pRenderTarget);
	}
	STDMETHODIMP IDirect3DDevice9::GetRenderTarget(THIS_ DWORD RenderTargetIndex, D9Real::IDirect3DSurface9** ppRenderTarget) noexcept(true)
	{
		return m_IDirect3DDevice9->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
	}
	STDMETHODIMP IDirect3DDevice9::SetDepthStencilSurface(THIS_ D9Real::IDirect3DSurface9* pNewZStencil) noexcept(true)
	{
		return m_IDirect3DDevice9->SetDepthStencilSurface(pNewZStencil);
	}
	STDMETHODIMP IDirect3DDevice9::GetDepthStencilSurface(THIS_ D9Real::IDirect3DSurface9** ppZStencilSurface) noexcept(true)
	{
		return m_IDirect3DDevice9->GetDepthStencilSurface(ppZStencilSurface);
	}
	STDMETHODIMP IDirect3DDevice9::BeginScene(THIS) noexcept(true)
	{
		if (bInsideScene)
		{
			bInsideScene = false;
			return D3DERR_INVALIDCALL;
		}
		bInsideScene = true;
		if (F4DX_manager::getManager().shouldDraw())
		{
			bSceneHandledByWrapper = false;
			return m_IDirect3DDevice9->BeginScene();
		}
		else
		{
			bSceneHandledByWrapper = true;
			return D3D_OK;
		}
	}
	STDMETHODIMP IDirect3DDevice9::EndScene(THIS) noexcept(true)
	{
		if (!bInsideScene)
		{
			return D3DERR_INVALIDCALL;
		}
		bInsideScene = false;
		if (bSceneHandledByWrapper)
		{
			return D3D_OK;
		}
		else
		{
			return m_IDirect3DDevice9->EndScene();
		}
	}
	STDMETHODIMP IDirect3DDevice9::Clear(THIS_ DWORD Count, CONST D9Real::D3DRECT* pRects, DWORD Flags, D9Real::D3DCOLOR Color, float Z, DWORD Stencil) noexcept(true)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->Clear(Count, pRects, Flags, Color, Z, Stencil);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::SetTransform(THIS_ D9Real::D3DTRANSFORMSTATETYPE State, CONST D9Real::D3DMATRIX* pMatrix) noexcept(true)
	{
		return m_IDirect3DDevice9->SetTransform(State, pMatrix);
	}
	STDMETHODIMP IDirect3DDevice9::GetTransform(THIS_ D9Real::D3DTRANSFORMSTATETYPE State, D9Real::D3DMATRIX* pMatrix) noexcept(true)
	{
		return m_IDirect3DDevice9->GetTransform(State, pMatrix);
	}
	STDMETHODIMP IDirect3DDevice9::MultiplyTransform(THIS_ D9Real::D3DTRANSFORMSTATETYPE a, CONST D9Real::D3DMATRIX* b) noexcept(true) // missing var names
	{
		return m_IDirect3DDevice9->MultiplyTransform(a, b);
	}
	STDMETHODIMP IDirect3DDevice9::SetViewport(THIS_ CONST D9Real::D3DVIEWPORT9* pViewport) noexcept(true)
	{
		return m_IDirect3DDevice9->SetViewport(pViewport);
	}
	STDMETHODIMP IDirect3DDevice9::GetViewport(THIS_ D9Real::D3DVIEWPORT9* pViewport) noexcept(true)
	{
		return m_IDirect3DDevice9->GetViewport(pViewport);
	}
	STDMETHODIMP IDirect3DDevice9::SetMaterial(THIS_ CONST D9Real::D3DMATERIAL9* pMaterial) noexcept(true)
	{
		return m_IDirect3DDevice9->SetMaterial(pMaterial);
	}
	STDMETHODIMP IDirect3DDevice9::GetMaterial(THIS_ D9Real::D3DMATERIAL9* pMaterial) noexcept(true)
	{
		return m_IDirect3DDevice9->GetMaterial(pMaterial);
	}
	STDMETHODIMP IDirect3DDevice9::SetLight(THIS_ DWORD Index, CONST D9Real::D3DLIGHT9* b) noexcept(true) // Missing second argument name
	{
		return m_IDirect3DDevice9->SetLight(Index, b);
	}
	STDMETHODIMP IDirect3DDevice9::GetLight(THIS_ DWORD Index, D9Real::D3DLIGHT9* b) noexcept(true) // Missing second argument name
	{
		return m_IDirect3DDevice9->GetLight(Index, b);
	}
	STDMETHODIMP IDirect3DDevice9::LightEnable(THIS_ DWORD Index, BOOL Enable) noexcept(true)
	{
		return m_IDirect3DDevice9->LightEnable(Index, Enable);
	}
	STDMETHODIMP IDirect3DDevice9::GetLightEnable(THIS_ DWORD Index, BOOL* pEnable) noexcept(true)
	{
		return m_IDirect3DDevice9->GetLightEnable(Index, pEnable);
	}
	STDMETHODIMP IDirect3DDevice9::SetClipPlane(THIS_ DWORD Index, CONST float* pPlane) noexcept(true)
	{
		return m_IDirect3DDevice9->SetClipPlane(Index, pPlane);
	}
	STDMETHODIMP IDirect3DDevice9::GetClipPlane(THIS_ DWORD Index, float* pPlane) noexcept(true)
	{
		return m_IDirect3DDevice9->GetClipPlane(Index, pPlane);
	}
	STDMETHODIMP IDirect3DDevice9::SetRenderState(THIS_ D9Real::D3DRENDERSTATETYPE State, DWORD Value) noexcept(true)
	{
		return m_IDirect3DDevice9->SetRenderState(State, Value);
	}
	STDMETHODIMP IDirect3DDevice9::GetRenderState(THIS_ D9Real::D3DRENDERSTATETYPE State, DWORD* pValue) noexcept(true)
	{
		return m_IDirect3DDevice9->GetRenderState(State, pValue);
	}
	STDMETHODIMP IDirect3DDevice9::CreateStateBlock(THIS_ D9Real::D3DSTATEBLOCKTYPE Type, D9Real::IDirect3DStateBlock9** ppSB) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateStateBlock(Type, ppSB);
	}
	STDMETHODIMP IDirect3DDevice9::BeginStateBlock(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->BeginStateBlock();
	}
	STDMETHODIMP IDirect3DDevice9::EndStateBlock(THIS_ D9Real::IDirect3DStateBlock9** ppSB) noexcept(true)
	{
		return m_IDirect3DDevice9->EndStateBlock(ppSB);
	}
	STDMETHODIMP IDirect3DDevice9::SetClipStatus(THIS_ CONST D9Real::D3DCLIPSTATUS9* pClipStatus) noexcept(true)
	{
		return m_IDirect3DDevice9->SetClipStatus(pClipStatus);
	}
	STDMETHODIMP IDirect3DDevice9::GetClipStatus(THIS_ D9Real::D3DCLIPSTATUS9* pClipStatus) noexcept(true)
	{
		return m_IDirect3DDevice9->GetClipStatus(pClipStatus);
	}
	STDMETHODIMP IDirect3DDevice9::GetTexture(THIS_ DWORD Stage, D9Real::IDirect3DBaseTexture9** ppTexture) noexcept(true)
	{
		return m_IDirect3DDevice9->GetTexture(Stage, ppTexture);
	}
	STDMETHODIMP IDirect3DDevice9::SetTexture(THIS_ DWORD Stage, D9Real::IDirect3DBaseTexture9* pTexture) noexcept(true)
	{
		return m_IDirect3DDevice9->SetTexture(Stage, pTexture);
	}
	STDMETHODIMP IDirect3DDevice9::GetTextureStageState(THIS_ DWORD Stage, D9Real::D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue) noexcept(true)
	{
		return m_IDirect3DDevice9->GetTextureStageState(Stage, Type, pValue);
	}
	STDMETHODIMP IDirect3DDevice9::SetTextureStageState(THIS_ DWORD Stage, D9Real::D3DTEXTURESTAGESTATETYPE Type, DWORD Value) noexcept(true)
	{
		return m_IDirect3DDevice9->SetTextureStageState(Stage, Type, Value);
	}
	STDMETHODIMP IDirect3DDevice9::GetSamplerState(THIS_ DWORD Sampler, D9Real::D3DSAMPLERSTATETYPE Type, DWORD* pValue) noexcept(true)
	{
		return m_IDirect3DDevice9->GetSamplerState(Sampler, Type, pValue);
	}
	STDMETHODIMP IDirect3DDevice9::SetSamplerState(THIS_ DWORD Sampler, D9Real::D3DSAMPLERSTATETYPE Type, DWORD Value) noexcept(true)
	{
		return m_IDirect3DDevice9->SetSamplerState(Sampler, Type, Value);
	}
	STDMETHODIMP IDirect3DDevice9::ValidateDevice(THIS_ DWORD* pNumPasses) noexcept(true)
	{
		return m_IDirect3DDevice9->ValidateDevice(pNumPasses);
	}
	STDMETHODIMP IDirect3DDevice9::SetPaletteEntries(THIS_ UINT PaletteNumber, CONST PALETTEENTRY* pEntries) noexcept(true)
	{
		return m_IDirect3DDevice9->SetPaletteEntries(PaletteNumber, pEntries);
	}
	STDMETHODIMP IDirect3DDevice9::GetPaletteEntries(THIS_ UINT PaletteNumber, PALETTEENTRY* pEntries) noexcept(true)
	{
		return m_IDirect3DDevice9->GetPaletteEntries(PaletteNumber, pEntries);
	}
	STDMETHODIMP IDirect3DDevice9::SetCurrentTexturePalette(THIS_ UINT PaletteNumber) noexcept(true)
	{
		return m_IDirect3DDevice9->SetCurrentTexturePalette(PaletteNumber);
	}
	STDMETHODIMP IDirect3DDevice9::GetCurrentTexturePalette(THIS_ UINT* PaletteNumber) noexcept(true)
	{
		return m_IDirect3DDevice9->GetCurrentTexturePalette(PaletteNumber);
	}
	STDMETHODIMP IDirect3DDevice9::SetScissorRect(THIS_ CONST RECT* pRect) noexcept(true)
	{
		return m_IDirect3DDevice9->SetScissorRect(pRect);
	}
	STDMETHODIMP IDirect3DDevice9::GetScissorRect(THIS_ RECT* pRect) noexcept(true)
	{
		return m_IDirect3DDevice9->GetScissorRect(pRect);
	}
	STDMETHODIMP IDirect3DDevice9::SetSoftwareVertexProcessing(THIS_ BOOL bSoftware) noexcept(true)
	{
		return m_IDirect3DDevice9->SetSoftwareVertexProcessing(bSoftware);
	}
	STDMETHODIMP_(BOOL) IDirect3DDevice9::GetSoftwareVertexProcessing(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->GetSoftwareVertexProcessing();
	}
	STDMETHODIMP IDirect3DDevice9::SetNPatchMode(THIS_ float nSegments) noexcept(true)
	{
		return m_IDirect3DDevice9->SetNPatchMode(nSegments);
	}
	STDMETHODIMP_(float) IDirect3DDevice9::GetNPatchMode(THIS) noexcept(true)
	{
		return m_IDirect3DDevice9->GetNPatchMode();
	}
	STDMETHODIMP IDirect3DDevice9::DrawPrimitive(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount) noexcept(true)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::DrawIndexedPrimitive(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount) noexcept(true) // Missing PrimitiveType name
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::DrawPrimitiveUP(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) noexcept(true)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::DrawIndexedPrimitiveUP(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D9Real::D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride) noexcept(true)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::ProcessVertices(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, D9Real::IDirect3DVertexBuffer9* pDestBuffer, D9Real::IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags) noexcept(true)
	{
		return m_IDirect3DDevice9->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
	}
	STDMETHODIMP IDirect3DDevice9::CreateVertexDeclaration(THIS_ CONST D9Real::D3DVERTEXELEMENT9* pVertexElements, D9Real::IDirect3DVertexDeclaration9** ppDecl) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateVertexDeclaration(pVertexElements, ppDecl);
	}
	STDMETHODIMP IDirect3DDevice9::SetVertexDeclaration(THIS_ D9Real::IDirect3DVertexDeclaration9* pDecl) noexcept(true)
	{
		return m_IDirect3DDevice9->SetVertexDeclaration(pDecl);
	}
	STDMETHODIMP IDirect3DDevice9::GetVertexDeclaration(THIS_ D9Real::IDirect3DVertexDeclaration9** ppDecl) noexcept(true)
	{
		return m_IDirect3DDevice9->GetVertexDeclaration(ppDecl);
	}
	STDMETHODIMP IDirect3DDevice9::SetFVF(THIS_ DWORD FVF) noexcept(true)
	{
		return m_IDirect3DDevice9->SetFVF(FVF);
	}
	STDMETHODIMP IDirect3DDevice9::GetFVF(THIS_ DWORD* pFVF) noexcept(true)
	{
		return m_IDirect3DDevice9->GetFVF(pFVF);
	}
	STDMETHODIMP IDirect3DDevice9::CreateVertexShader(THIS_ CONST DWORD* pFunction, D9Real::IDirect3DVertexShader9** ppShader) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateVertexShader(pFunction, ppShader);
	}
	STDMETHODIMP IDirect3DDevice9::SetVertexShader(THIS_ D9Real::IDirect3DVertexShader9* pShader) noexcept(true)
	{
		return m_IDirect3DDevice9->SetVertexShader(pShader);
	}
	STDMETHODIMP IDirect3DDevice9::GetVertexShader(THIS_ D9Real::IDirect3DVertexShader9** ppShader) noexcept(true)
	{
		return m_IDirect3DDevice9->GetVertexShader(ppShader);
	}
	STDMETHODIMP IDirect3DDevice9::SetVertexShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) noexcept(true)
	{
		return m_IDirect3DDevice9->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9::GetVertexShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount) noexcept(true)
	{
		return m_IDirect3DDevice9->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9::SetVertexShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount) noexcept(true)
	{
		return m_IDirect3DDevice9->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9::GetVertexShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount) noexcept(true)
	{
		return m_IDirect3DDevice9->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9::SetVertexShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount) noexcept(true)
	{
		return m_IDirect3DDevice9->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9::GetVertexShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount) noexcept(true)
	{
		return m_IDirect3DDevice9->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9::SetStreamSource(THIS_ UINT StreamNumber, D9Real::IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride) noexcept(true)
	{
		return m_IDirect3DDevice9->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
	}
	STDMETHODIMP IDirect3DDevice9::GetStreamSource(THIS_ UINT StreamNumber, D9Real::IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride) noexcept(true)
	{
		return m_IDirect3DDevice9->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
	}
	STDMETHODIMP IDirect3DDevice9::SetStreamSourceFreq(THIS_ UINT StreamNumber, UINT Divider) noexcept(true)
	{
		return m_IDirect3DDevice9->SetStreamSourceFreq(StreamNumber, Divider);
	}
	STDMETHODIMP IDirect3DDevice9::GetStreamSourceFreq(THIS_ UINT StreamNumber, UINT* Divider) noexcept(true)
	{
		return m_IDirect3DDevice9->GetStreamSourceFreq(StreamNumber, Divider);
	}
	STDMETHODIMP IDirect3DDevice9::SetIndices(THIS_ D9Real::IDirect3DIndexBuffer9* pIndexData) noexcept(true)
	{
		return m_IDirect3DDevice9->SetIndices(pIndexData);
	}
	STDMETHODIMP IDirect3DDevice9::GetIndices(THIS_ D9Real::IDirect3DIndexBuffer9** ppIndexData) noexcept(true)
	{
		return m_IDirect3DDevice9->GetIndices(ppIndexData);
	}
	STDMETHODIMP IDirect3DDevice9::CreatePixelShader(THIS_ CONST DWORD* pFunction, D9Real::IDirect3DPixelShader9** ppShader) noexcept(true)
	{
		return m_IDirect3DDevice9->CreatePixelShader(pFunction, ppShader);
	}
	STDMETHODIMP IDirect3DDevice9::SetPixelShader(THIS_ D9Real::IDirect3DPixelShader9* pShader) noexcept(true)
	{
		return m_IDirect3DDevice9->SetPixelShader(pShader);
	}
	STDMETHODIMP IDirect3DDevice9::GetPixelShader(THIS_ D9Real::IDirect3DPixelShader9** ppShader) noexcept(true)
	{
		return m_IDirect3DDevice9->GetPixelShader(ppShader);
	}
	STDMETHODIMP IDirect3DDevice9::SetPixelShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount) noexcept(true)
	{
		return m_IDirect3DDevice9->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9::GetPixelShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount) noexcept(true)
	{
		return m_IDirect3DDevice9->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9::SetPixelShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount) noexcept(true)
	{
		return m_IDirect3DDevice9->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9::GetPixelShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount) noexcept(true)
	{
		return m_IDirect3DDevice9->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9::SetPixelShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount) noexcept(true)
	{
		return m_IDirect3DDevice9->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9::GetPixelShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount) noexcept(true)
	{
		return m_IDirect3DDevice9->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9::DrawRectPatch(THIS_ UINT Handle, CONST float* pNumSegs, CONST D9Real::D3DRECTPATCH_INFO* pRectPatchInfo) noexcept(true)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::DrawTriPatch(THIS_ UINT Handle, CONST float* pNumSegs, CONST D9Real::D3DTRIPATCH_INFO* pTriPatchInfo) noexcept(true)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9::DeletePatch(THIS_ UINT Handle)
	{
		return m_IDirect3DDevice9->DeletePatch(Handle);
	}
	STDMETHODIMP IDirect3DDevice9::CreateQuery(THIS_ D9Real::D3DQUERYTYPE Type, D9Real::IDirect3DQuery9** ppQuery) noexcept(true)
	{
		return m_IDirect3DDevice9->CreateQuery(Type, ppQuery);
	}
}

#pragma warning(pop)