#include "IDirect3DDevice9Ex.h"
#include "IDirect3D9Ex.h"

#include "d3d9_manager.h"

namespace D9Wrapper
{
	IDirect3DDevice9Ex::IDirect3DDevice9Ex(D9Real::IDirect3DDevice9Ex* obj, IDirect3D9Ex* obj2) : IDirect3DDevice9(obj, obj2)
	{
		m_IDirect3DDevice9Ex = obj;
		m_IDirect3D9Ex = obj2;
		bInsideScene = false;
		bSceneHandledByWrapper = false;
	}
	// IUnknown methods 
	STDMETHODIMP IDirect3DDevice9Ex::QueryInterface(THIS_ REFIID riid, void** ppvObj)
	{
		return m_IDirect3DDevice9Ex->QueryInterface(riid, ppvObj);
	}
	STDMETHODIMP_(ULONG) IDirect3DDevice9Ex::AddRef(THIS)
	{
		return m_IDirect3DDevice9Ex->AddRef();
	}
	STDMETHODIMP_(ULONG) IDirect3DDevice9Ex::Release(THIS)
	{
		return m_IDirect3DDevice9Ex->Release();
	}
	// IDirect3DDevice9 methods

	STDMETHODIMP IDirect3DDevice9Ex::TestCooperativeLevel(THIS)
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->TestCooperativeLevel();
		}
		else return D3D_OK;
	}
	STDMETHODIMP_(UINT) IDirect3DDevice9Ex::GetAvailableTextureMem(THIS)
	{
		return m_IDirect3DDevice9Ex->GetAvailableTextureMem();
	}
	STDMETHODIMP IDirect3DDevice9Ex::EvictManagedResources(THIS)
	{
		return m_IDirect3DDevice9Ex->EvictManagedResources();
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetDirect3D(THIS_ IDirect3D9** ppD3D9)
	{
		if (m_IDirect3D9Ex != NULL)
		{
			m_IDirect3D9Ex->AddRef(); // We have to add a ref directly, since we are NOT passing this on to m_IDirect3DDevice9Ex.
			*ppD3D9 = m_IDirect3D9Ex;
			return D3D_OK;
		}
		else return D3DERR_INVALIDCALL;
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetDeviceCaps(THIS_ D9Real::D3DCAPS9* pCaps)
	{
		return m_IDirect3DDevice9Ex->GetDeviceCaps(pCaps);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetDisplayMode(THIS_ UINT iSwapChain, D9Real::D3DDISPLAYMODE* pMode)
	{
		return m_IDirect3DDevice9Ex->GetDisplayMode(iSwapChain, pMode);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetCreationParameters(THIS_ D9Real::D3DDEVICE_CREATION_PARAMETERS* pParameters)
	{
		return m_IDirect3DDevice9Ex->GetCreationParameters(pParameters);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetCursorProperties(THIS_ UINT XHotSpot, UINT YHotSpot, D9Real::IDirect3DSurface9* pCursorBitmap)
	{
		return m_IDirect3DDevice9Ex->SetCursorProperties(XHotSpot, YHotSpot, pCursorBitmap);
	}
	STDMETHODIMP_(void) IDirect3DDevice9Ex::SetCursorPosition(THIS_ int X, int Y, DWORD Flags)
	{
		return m_IDirect3DDevice9Ex->SetCursorPosition(X, Y, Flags);
	}
	STDMETHODIMP_(BOOL) IDirect3DDevice9Ex::ShowCursor(THIS_ BOOL bShow)
	{
		return m_IDirect3DDevice9Ex->ShowCursor(bShow);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateAdditionalSwapChain(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::IDirect3DSwapChain9** pSwapChain)
	{
		return m_IDirect3DDevice9Ex->CreateAdditionalSwapChain(pPresentationParameters, pSwapChain);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetSwapChain(THIS_ UINT iSwapChain, D9Real::IDirect3DSwapChain9** pSwapChain)
	{
		return m_IDirect3DDevice9Ex->GetSwapChain(iSwapChain, pSwapChain);
	}
	STDMETHODIMP_(UINT) IDirect3DDevice9Ex::GetNumberOfSwapChains(THIS)
	{
		return m_IDirect3DDevice9Ex->GetNumberOfSwapChains();
	}
	STDMETHODIMP IDirect3DDevice9Ex::Reset(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters)
	{
		return m_IDirect3DDevice9Ex->Reset(pPresentationParameters);
	}
	STDMETHODIMP IDirect3DDevice9Ex::Present(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion)
	{
		//d3d9_manager::getManager().getFPS().AddFrameCount();
		// If calculating FPS ourselves, we should do it here.
		if (bInsideScene)
		{
			return D3DERR_INVALIDCALL;
		}
		if (bSceneHandledByWrapper)
		{
			return D3D_OK;
		}
		else return m_IDirect3DDevice9Ex->Present(pSourceRect, pDestRect, hDestWindowOverride, pDirtyRegion);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetBackBuffer(THIS_ UINT iSwapChain, UINT iBackBuffer, D9Real::D3DBACKBUFFER_TYPE Type, D9Real::IDirect3DSurface9** ppBackBuffer)
	{
		return m_IDirect3DDevice9Ex->GetBackBuffer(iSwapChain, iBackBuffer, Type, ppBackBuffer);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetRasterStatus(THIS_ UINT iSwapChain, D9Real::D3DRASTER_STATUS* pRasterStatus)
	{
		return m_IDirect3DDevice9Ex->GetRasterStatus(iSwapChain, pRasterStatus);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetDialogBoxMode(THIS_ BOOL bEnableDialogs)
	{
		return m_IDirect3DDevice9Ex->SetDialogBoxMode(bEnableDialogs);
	}
	STDMETHODIMP_(void) IDirect3DDevice9Ex::SetGammaRamp(THIS_ UINT iSwapChain, DWORD Flags, CONST D9Real::D3DGAMMARAMP* pRamp)
	{
		return m_IDirect3DDevice9Ex->SetGammaRamp(iSwapChain, Flags, pRamp);
	}
	STDMETHODIMP_(void) IDirect3DDevice9Ex::GetGammaRamp(THIS_ UINT iSwapChain, D9Real::D3DGAMMARAMP* pRamp)
	{
		return m_IDirect3DDevice9Ex->GetGammaRamp(iSwapChain, pRamp);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateTexture(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateTexture(Width, Height, Levels, Usage, Format, Pool, ppTexture, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateVolumeTexture(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateVolumeTexture(Width, Height, Depth, Levels, Usage, Format, Pool, ppVolumeTexture, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateCubeTexture(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateCubeTexture(EdgeLength, Levels, Usage, Format, Pool, ppCubeTexture, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateVertexBuffer(THIS_ UINT Length, DWORD Usage, DWORD FVF, D9Real::D3DPOOL Pool, D9Real::IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateVertexBuffer(Length, Usage, FVF, Pool, ppVertexBuffer, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateIndexBuffer(THIS_ UINT Length, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateIndexBuffer(Length, Usage, Format, Pool, ppIndexBuffer, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateRenderTarget(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateRenderTarget(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateDepthStencilSurface(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateDepthStencilSurface(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::UpdateSurface(THIS_ D9Real::IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, D9Real::IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint)
	{
		return m_IDirect3DDevice9Ex->UpdateSurface(pSourceSurface, pSourceRect, pDestinationSurface, pDestPoint);
	}
	STDMETHODIMP IDirect3DDevice9Ex::UpdateTexture(THIS_ D9Real::IDirect3DBaseTexture9* pSourceTexture, D9Real::IDirect3DBaseTexture9* pDestinationTexture)
	{
		return m_IDirect3DDevice9Ex->UpdateTexture(pSourceTexture, pDestinationTexture);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetRenderTargetData(THIS_ D9Real::IDirect3DSurface9* pRenderTarget, D9Real::IDirect3DSurface9* pDestSurface)
	{
		return m_IDirect3DDevice9Ex->GetRenderTargetData(pRenderTarget, pDestSurface);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetFrontBufferData(THIS_ UINT iSwapChain, D9Real::IDirect3DSurface9* pDestSurface)
	{
		return m_IDirect3DDevice9Ex->GetFrontBufferData(iSwapChain, pDestSurface);
	}
	STDMETHODIMP IDirect3DDevice9Ex::StretchRect(THIS_ D9Real::IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, D9Real::IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D9Real::D3DTEXTUREFILTERTYPE Filter)
	{
		return m_IDirect3DDevice9Ex->StretchRect(pSourceSurface, pSourceRect, pDestSurface, pDestRect, Filter);
	}
	STDMETHODIMP IDirect3DDevice9Ex::ColorFill(THIS_ D9Real::IDirect3DSurface9* pSurface, CONST RECT* pRect, D9Real::D3DCOLOR color)
	{
		return m_IDirect3DDevice9Ex->ColorFill(pSurface, pRect, color);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateOffscreenPlainSurface(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle)
	{
		return m_IDirect3DDevice9Ex->CreateOffscreenPlainSurface(Width, Height, Format, Pool, ppSurface, pSharedHandle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetRenderTarget(THIS_ DWORD RenderTargetIndex, D9Real::IDirect3DSurface9* pRenderTarget)
	{
		return m_IDirect3DDevice9Ex->SetRenderTarget(RenderTargetIndex, pRenderTarget);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetRenderTarget(THIS_ DWORD RenderTargetIndex, D9Real::IDirect3DSurface9** ppRenderTarget)
	{
		return m_IDirect3DDevice9Ex->GetRenderTarget(RenderTargetIndex, ppRenderTarget);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetDepthStencilSurface(THIS_ D9Real::IDirect3DSurface9* pNewZStencil)
	{
		return m_IDirect3DDevice9Ex->SetDepthStencilSurface(pNewZStencil);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetDepthStencilSurface(THIS_ D9Real::IDirect3DSurface9** ppZStencilSurface)
	{
		return m_IDirect3DDevice9Ex->GetDepthStencilSurface(ppZStencilSurface);
	}
	STDMETHODIMP IDirect3DDevice9Ex::BeginScene(THIS)
	{
		if(bInsideScene)
		{
			bInsideScene = false;
			return D3DERR_INVALIDCALL;
		}
		bInsideScene = true;
		if(d3d9_manager::getManager().shouldDraw())
		{
			bSceneHandledByWrapper = false;
			return m_IDirect3DDevice9Ex->BeginScene();
		}
		else
		{
			bSceneHandledByWrapper = true;
			return D3D_OK;
		}
	}
	STDMETHODIMP IDirect3DDevice9Ex::EndScene(THIS)
	{
		if(!bInsideScene)
		{
			return D3DERR_INVALIDCALL;
		}
		bInsideScene = false;
		if(bSceneHandledByWrapper)
		{
			return D3D_OK;
		}
		else
		{
			return m_IDirect3DDevice9Ex->EndScene();
		}
	}
	STDMETHODIMP IDirect3DDevice9Ex::Clear(THIS_ DWORD Count, CONST D9Real::D3DRECT* pRects, DWORD Flags, D9Real::D3DCOLOR Color, float Z, DWORD Stencil)
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->Clear(Count, pRects, Flags, Color, Z, Stencil);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetTransform(THIS_ D9Real::D3DTRANSFORMSTATETYPE State, CONST D9Real::D3DMATRIX* pMatrix)
	{
		return m_IDirect3DDevice9Ex->SetTransform(State, pMatrix);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetTransform(THIS_ D9Real::D3DTRANSFORMSTATETYPE State, D9Real::D3DMATRIX* pMatrix)
	{
		return m_IDirect3DDevice9Ex->GetTransform(State, pMatrix);
	}
	STDMETHODIMP IDirect3DDevice9Ex::MultiplyTransform(THIS_ D9Real::D3DTRANSFORMSTATETYPE a, CONST D9Real::D3DMATRIX* b) // missing var names
	{
		return m_IDirect3DDevice9Ex->MultiplyTransform(a, b);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetViewport(THIS_ CONST D9Real::D3DVIEWPORT9* pViewport)
	{
		return m_IDirect3DDevice9Ex->SetViewport(pViewport);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetViewport(THIS_ D9Real::D3DVIEWPORT9* pViewport)
	{
		return m_IDirect3DDevice9Ex->GetViewport(pViewport);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetMaterial(THIS_ CONST D9Real::D3DMATERIAL9* pMaterial)
	{
		return m_IDirect3DDevice9Ex->SetMaterial(pMaterial);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetMaterial(THIS_ D9Real::D3DMATERIAL9* pMaterial)
	{
		return m_IDirect3DDevice9Ex->GetMaterial(pMaterial);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetLight(THIS_ DWORD Index, CONST D9Real::D3DLIGHT9* b) // Missing second argument name
	{
		return m_IDirect3DDevice9Ex->SetLight(Index, b);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetLight(THIS_ DWORD Index, D9Real::D3DLIGHT9* b) // Missing second argument name
	{
		return m_IDirect3DDevice9Ex->GetLight(Index, b);
	}
	STDMETHODIMP IDirect3DDevice9Ex::LightEnable(THIS_ DWORD Index, BOOL Enable)
	{
		return m_IDirect3DDevice9Ex->LightEnable(Index, Enable);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetLightEnable(THIS_ DWORD Index, BOOL* pEnable)
	{
		return m_IDirect3DDevice9Ex->GetLightEnable(Index, pEnable);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetClipPlane(THIS_ DWORD Index, CONST float* pPlane)
	{
		return m_IDirect3DDevice9Ex->SetClipPlane(Index, pPlane);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetClipPlane(THIS_ DWORD Index, float* pPlane)
	{
		return m_IDirect3DDevice9Ex->GetClipPlane(Index, pPlane);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetRenderState(THIS_ D9Real::D3DRENDERSTATETYPE State, DWORD Value)
	{
		return m_IDirect3DDevice9Ex->SetRenderState(State, Value);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetRenderState(THIS_ D9Real::D3DRENDERSTATETYPE State, DWORD* pValue)
	{
		return m_IDirect3DDevice9Ex->GetRenderState(State, pValue);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateStateBlock(THIS_ D9Real::D3DSTATEBLOCKTYPE Type, D9Real::IDirect3DStateBlock9** ppSB)
	{
		return m_IDirect3DDevice9Ex->CreateStateBlock(Type, ppSB);
	}
	STDMETHODIMP IDirect3DDevice9Ex::BeginStateBlock(THIS)
	{
		return m_IDirect3DDevice9Ex->BeginStateBlock();
	}
	STDMETHODIMP IDirect3DDevice9Ex::EndStateBlock(THIS_ D9Real::IDirect3DStateBlock9** ppSB)
	{
		return m_IDirect3DDevice9Ex->EndStateBlock(ppSB);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetClipStatus(THIS_ CONST D9Real::D3DCLIPSTATUS9* pClipStatus)
	{
		return m_IDirect3DDevice9Ex->SetClipStatus(pClipStatus);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetClipStatus(THIS_ D9Real::D3DCLIPSTATUS9* pClipStatus)
	{
		return m_IDirect3DDevice9Ex->GetClipStatus(pClipStatus);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetTexture(THIS_ DWORD Stage, D9Real::IDirect3DBaseTexture9** ppTexture)
	{
		return m_IDirect3DDevice9Ex->GetTexture(Stage, ppTexture);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetTexture(THIS_ DWORD Stage, D9Real::IDirect3DBaseTexture9* pTexture)
	{
		return m_IDirect3DDevice9Ex->SetTexture(Stage, pTexture);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetTextureStageState(THIS_ DWORD Stage, D9Real::D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue)
	{
		return m_IDirect3DDevice9Ex->GetTextureStageState(Stage, Type, pValue);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetTextureStageState(THIS_ DWORD Stage, D9Real::D3DTEXTURESTAGESTATETYPE Type, DWORD Value)
	{
		return m_IDirect3DDevice9Ex->SetTextureStageState(Stage, Type, Value);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetSamplerState(THIS_ DWORD Sampler, D9Real::D3DSAMPLERSTATETYPE Type, DWORD* pValue)
	{
		return m_IDirect3DDevice9Ex->GetSamplerState(Sampler, Type, pValue);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetSamplerState(THIS_ DWORD Sampler, D9Real::D3DSAMPLERSTATETYPE Type, DWORD Value)
	{
		return m_IDirect3DDevice9Ex->SetSamplerState(Sampler, Type, Value);
	}
	STDMETHODIMP IDirect3DDevice9Ex::ValidateDevice(THIS_ DWORD* pNumPasses)
	{
		return m_IDirect3DDevice9Ex->ValidateDevice(pNumPasses);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetPaletteEntries(THIS_ UINT PaletteNumber, CONST PALETTEENTRY* pEntries)
	{
		return m_IDirect3DDevice9Ex->SetPaletteEntries(PaletteNumber, pEntries);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetPaletteEntries(THIS_ UINT PaletteNumber, PALETTEENTRY* pEntries)
	{
		return m_IDirect3DDevice9Ex->GetPaletteEntries(PaletteNumber, pEntries);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetCurrentTexturePalette(THIS_ UINT PaletteNumber)
	{
		return m_IDirect3DDevice9Ex->SetCurrentTexturePalette(PaletteNumber);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetCurrentTexturePalette(THIS_ UINT* PaletteNumber)
	{
		return m_IDirect3DDevice9Ex->GetCurrentTexturePalette(PaletteNumber);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetScissorRect(THIS_ CONST RECT* pRect)
	{
		return m_IDirect3DDevice9Ex->SetScissorRect(pRect);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetScissorRect(THIS_ RECT* pRect)
	{
		return m_IDirect3DDevice9Ex->GetScissorRect(pRect);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetSoftwareVertexProcessing(THIS_ BOOL bSoftware)
	{
		return m_IDirect3DDevice9Ex->SetSoftwareVertexProcessing(bSoftware);
	}
	STDMETHODIMP_(BOOL) IDirect3DDevice9Ex::GetSoftwareVertexProcessing(THIS)
	{
		return m_IDirect3DDevice9Ex->GetSoftwareVertexProcessing();
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetNPatchMode(THIS_ float nSegments)
	{
		return m_IDirect3DDevice9Ex->SetNPatchMode(nSegments);
	}
	STDMETHODIMP_(float) IDirect3DDevice9Ex::GetNPatchMode(THIS)
	{
		return m_IDirect3DDevice9Ex->GetNPatchMode();
	}
	STDMETHODIMP IDirect3DDevice9Ex::DrawPrimitive(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount)
	{
		if(d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->DrawPrimitive(PrimitiveType, StartVertex, PrimitiveCount);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::DrawIndexedPrimitive(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount) // Missing PrimitiveType name
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->DrawIndexedPrimitive(PrimitiveType, BaseVertexIndex, MinVertexIndex, NumVertices, startIndex, primCount);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::DrawPrimitiveUP(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->DrawPrimitiveUP(PrimitiveType, PrimitiveCount, pVertexStreamZeroData, VertexStreamZeroStride);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::DrawIndexedPrimitiveUP(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D9Real::D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride)
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->DrawIndexedPrimitiveUP(PrimitiveType, MinVertexIndex, NumVertices, PrimitiveCount, pIndexData, IndexDataFormat, pVertexStreamZeroData, VertexStreamZeroStride);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::ProcessVertices(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, D9Real::IDirect3DVertexBuffer9* pDestBuffer, D9Real::IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags)
	{
		return m_IDirect3DDevice9Ex->ProcessVertices(SrcStartIndex, DestIndex, VertexCount, pDestBuffer, pVertexDecl, Flags);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateVertexDeclaration(THIS_ CONST D9Real::D3DVERTEXELEMENT9* pVertexElements, D9Real::IDirect3DVertexDeclaration9** ppDecl)
	{
		return m_IDirect3DDevice9Ex->CreateVertexDeclaration(pVertexElements, ppDecl);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetVertexDeclaration(THIS_ D9Real::IDirect3DVertexDeclaration9* pDecl)
	{
		return m_IDirect3DDevice9Ex->SetVertexDeclaration(pDecl);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetVertexDeclaration(THIS_ D9Real::IDirect3DVertexDeclaration9** ppDecl)
	{	
		return m_IDirect3DDevice9Ex->GetVertexDeclaration(ppDecl);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetFVF(THIS_ DWORD FVF)
	{
		return m_IDirect3DDevice9Ex->SetFVF(FVF);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetFVF(THIS_ DWORD* pFVF)
	{
		return m_IDirect3DDevice9Ex->GetFVF(pFVF);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateVertexShader(THIS_ CONST DWORD* pFunction, D9Real::IDirect3DVertexShader9** ppShader)
	{
		return m_IDirect3DDevice9Ex->CreateVertexShader(pFunction, ppShader);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetVertexShader(THIS_ D9Real::IDirect3DVertexShader9* pShader)
	{
		return m_IDirect3DDevice9Ex->SetVertexShader(pShader);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetVertexShader(THIS_ D9Real::IDirect3DVertexShader9** ppShader)
	{
		return m_IDirect3DDevice9Ex->GetVertexShader(ppShader);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetVertexShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
	{
		return m_IDirect3DDevice9Ex->SetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetVertexShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
	{
		return m_IDirect3DDevice9Ex->GetVertexShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetVertexShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
	{
		return m_IDirect3DDevice9Ex->SetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetVertexShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
	{
		return m_IDirect3DDevice9Ex->GetVertexShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetVertexShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
	{
		return m_IDirect3DDevice9Ex->SetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetVertexShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
	{
		return m_IDirect3DDevice9Ex->GetVertexShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetStreamSource(THIS_ UINT StreamNumber, D9Real::IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride)
	{
		return m_IDirect3DDevice9Ex->SetStreamSource(StreamNumber, pStreamData, OffsetInBytes, Stride);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetStreamSource(THIS_ UINT StreamNumber, D9Real::IDirect3DVertexBuffer9** ppStreamData, UINT* OffsetInBytes, UINT* pStride)
	{
		return m_IDirect3DDevice9Ex->GetStreamSource(StreamNumber, ppStreamData, OffsetInBytes, pStride);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetStreamSourceFreq(THIS_ UINT StreamNumber, UINT Divider)
	{
		return m_IDirect3DDevice9Ex->SetStreamSourceFreq(StreamNumber, Divider);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetStreamSourceFreq(THIS_ UINT StreamNumber, UINT* Divider)
	{
		return m_IDirect3DDevice9Ex->GetStreamSourceFreq(StreamNumber, Divider);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetIndices(THIS_ D9Real::IDirect3DIndexBuffer9* pIndexData)
	{
		return m_IDirect3DDevice9Ex->SetIndices(pIndexData);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetIndices(THIS_ D9Real::IDirect3DIndexBuffer9** ppIndexData)
	{
		return m_IDirect3DDevice9Ex->GetIndices(ppIndexData);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreatePixelShader(THIS_ CONST DWORD* pFunction, D9Real::IDirect3DPixelShader9** ppShader)
	{
		return m_IDirect3DDevice9Ex->CreatePixelShader(pFunction, ppShader);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetPixelShader(THIS_ D9Real::IDirect3DPixelShader9* pShader)
	{
		return m_IDirect3DDevice9Ex->SetPixelShader(pShader);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetPixelShader(THIS_ D9Real::IDirect3DPixelShader9** ppShader)
	{
		return m_IDirect3DDevice9Ex->GetPixelShader(ppShader);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetPixelShaderConstantF(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount)
	{
		return m_IDirect3DDevice9Ex->SetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetPixelShaderConstantF(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount)
	{
		return m_IDirect3DDevice9Ex->GetPixelShaderConstantF(StartRegister, pConstantData, Vector4fCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetPixelShaderConstantI(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount)
	{
		return m_IDirect3DDevice9Ex->SetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetPixelShaderConstantI(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount)
	{
		return m_IDirect3DDevice9Ex->GetPixelShaderConstantI(StartRegister, pConstantData, Vector4iCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetPixelShaderConstantB(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount)
	{
		return m_IDirect3DDevice9Ex->SetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetPixelShaderConstantB(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount)
	{
		return m_IDirect3DDevice9Ex->GetPixelShaderConstantB(StartRegister, pConstantData, BoolCount);
	}
	STDMETHODIMP IDirect3DDevice9Ex::DrawRectPatch(THIS_ UINT Handle, CONST float* pNumSegs, CONST D9Real::D3DRECTPATCH_INFO* pRectPatchInfo)
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->DrawRectPatch(Handle, pNumSegs, pRectPatchInfo);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::DrawTriPatch(THIS_ UINT Handle, CONST float* pNumSegs, CONST D9Real::D3DTRIPATCH_INFO* pTriPatchInfo)
	{
		if (d3d9_manager::getManager().shouldDraw())
		{
			return m_IDirect3DDevice9Ex->DrawTriPatch(Handle, pNumSegs, pTriPatchInfo);
		}
		else return D3D_OK;
	}
	STDMETHODIMP IDirect3DDevice9Ex::DeletePatch(THIS_ UINT Handle)
	{
		return m_IDirect3DDevice9Ex->DeletePatch(Handle);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateQuery(THIS_ D9Real::D3DQUERYTYPE Type, D9Real::IDirect3DQuery9** ppQuery)
	{
		return m_IDirect3DDevice9Ex->CreateQuery(Type, ppQuery);
	}

	// 9Ex functions

	STDMETHODIMP IDirect3DDevice9Ex::SetConvolutionMonoKernel(THIS_ UINT width, UINT height, float* rows, float* columns)
	{
		return m_IDirect3DDevice9Ex->SetConvolutionMonoKernel(width, height, rows, columns);
	}
	STDMETHODIMP IDirect3DDevice9Ex::ComposeRects(THIS_ D9Real::IDirect3DSurface9* pSrc, D9Real::IDirect3DSurface9* pDst, D9Real::IDirect3DVertexBuffer9* pSrcRectDescs, UINT NumRects, D9Real::IDirect3DVertexBuffer9* pDstRectDescs, D9Real::D3DCOMPOSERECTSOP Operation, int Xoffset, int Yoffset)
	{
		return m_IDirect3DDevice9Ex->ComposeRects(pSrc, pDst, pSrcRectDescs, NumRects, pDstRectDescs, Operation, Xoffset, Yoffset);
	}
	STDMETHODIMP IDirect3DDevice9Ex::PresentEx(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion, DWORD dwFlags)
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
	STDMETHODIMP IDirect3DDevice9Ex::GetGPUThreadPriority(THIS_ INT* pPriority)
	{
		return m_IDirect3DDevice9Ex->GetGPUThreadPriority(pPriority);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetGPUThreadPriority(THIS_ INT Priority)
	{
		return m_IDirect3DDevice9Ex->SetGPUThreadPriority(Priority);
	}
	STDMETHODIMP IDirect3DDevice9Ex::WaitForVBlank(THIS_ UINT iSwapChain)
	{
		return m_IDirect3DDevice9Ex->WaitForVBlank(iSwapChain);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CheckResourceResidency(THIS_ D9Real::IDirect3DResource9** pResourceArray, UINT32 NumResources)
	{
		return m_IDirect3DDevice9Ex->CheckResourceResidency(pResourceArray, NumResources);
	}
	STDMETHODIMP IDirect3DDevice9Ex::SetMaximumFrameLatency(THIS_ UINT MaxLatency)
	{
		return m_IDirect3DDevice9Ex->SetMaximumFrameLatency(MaxLatency);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetMaximumFrameLatency(THIS_ UINT* pMaxLatency)
	{
		return m_IDirect3DDevice9Ex->GetMaximumFrameLatency(pMaxLatency);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CheckDeviceState(THIS_ HWND hDestinationWindow)
	{
		return m_IDirect3DDevice9Ex->CheckDeviceState(hDestinationWindow);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateRenderTargetEx(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage)
	{
		return m_IDirect3DDevice9Ex->CreateRenderTargetEx(Width, Height, Format, MultiSample, MultisampleQuality, Lockable, ppSurface, pSharedHandle, Usage);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateOffscreenPlainSurfaceEx(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage)
	{
		return m_IDirect3DDevice9Ex->CreateOffscreenPlainSurfaceEx(Width,Height,Format, Pool, ppSurface, pSharedHandle, Usage);
	}
	STDMETHODIMP IDirect3DDevice9Ex::CreateDepthStencilSurfaceEx(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle, DWORD Usage)
	{
		return m_IDirect3DDevice9Ex->CreateDepthStencilSurfaceEx(Width, Height, Format, MultiSample, MultisampleQuality, Discard, ppSurface, pSharedHandle, Usage);
	}
	STDMETHODIMP IDirect3DDevice9Ex::ResetEx(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::D3DDISPLAYMODEEX* pFullscreenDisplayMode)
	{
		return m_IDirect3DDevice9Ex->ResetEx(pPresentationParameters, pFullscreenDisplayMode);
	}
	STDMETHODIMP IDirect3DDevice9Ex::GetDisplayModeEx(THIS_ UINT iSwapChain, D9Real::D3DDISPLAYMODEEX* pMode, D9Real::D3DDISPLAYROTATION* pRotation)
	{
		return m_IDirect3DDevice9Ex->GetDisplayModeEx(iSwapChain, pMode, pRotation);
	}
}