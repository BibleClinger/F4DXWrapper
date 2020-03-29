#pragma once

#include "IDirect3DDevice9.h"

namespace D9Wrapper
{
	class IDirect3D9;
	class IDirect3D9Ex;

	class IDirect3DDevice9Ex : public IDirect3DDevice9
	{
	protected:
		D9Real::IDirect3DDevice9Ex* m_IDirect3DDevice9Ex;
		IDirect3D9* m_IDirect3D9Ex;
		bool bInsideScene;
		bool bSceneHandledByWrapper;
	public:
		IDirect3DDevice9Ex(D9Real::IDirect3DDevice9Ex* obj, IDirect3D9Ex *obj2);
		/*** IUnknown methods ***/
		STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
		STDMETHOD_(ULONG, AddRef)(THIS);
		STDMETHOD_(ULONG, Release)(THIS);

		/*** IDirect3DDevice9 methods ***/
		STDMETHOD(TestCooperativeLevel)(THIS);
		STDMETHOD_(UINT, GetAvailableTextureMem)(THIS);
		STDMETHOD(EvictManagedResources)(THIS);
		STDMETHOD(GetDirect3D)(THIS_ IDirect3D9** ppD3D9);
		STDMETHOD(GetDeviceCaps)(THIS_ D9Real::D3DCAPS9* pCaps);
		STDMETHOD(GetDisplayMode)(THIS_ UINT iSwapChain, D9Real::D3DDISPLAYMODE* pMode);
		STDMETHOD(GetCreationParameters)(THIS_ D9Real::D3DDEVICE_CREATION_PARAMETERS* pParameters);
		STDMETHOD(SetCursorProperties)(THIS_ UINT XHotSpot, UINT YHotSpot, D9Real::IDirect3DSurface9* pCursorBitmap);
		STDMETHOD_(void, SetCursorPosition)(THIS_ int X, int Y, DWORD Flags);
		STDMETHOD_(BOOL, ShowCursor)(THIS_ BOOL bShow);
		STDMETHOD(CreateAdditionalSwapChain)(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters, D9Real::IDirect3DSwapChain9** pSwapChain);
		STDMETHOD(GetSwapChain)(THIS_ UINT iSwapChain, D9Real::IDirect3DSwapChain9** pSwapChain);
		STDMETHOD_(UINT, GetNumberOfSwapChains)(THIS);
		STDMETHOD(Reset)(THIS_ D9Real::D3DPRESENT_PARAMETERS* pPresentationParameters);
		STDMETHOD(Present)(THIS_ CONST RECT* pSourceRect, CONST RECT* pDestRect, HWND hDestWindowOverride, CONST RGNDATA* pDirtyRegion);
		STDMETHOD(GetBackBuffer)(THIS_ UINT iSwapChain, UINT iBackBuffer, D9Real::D3DBACKBUFFER_TYPE Type, D9Real::IDirect3DSurface9** ppBackBuffer);
		STDMETHOD(GetRasterStatus)(THIS_ UINT iSwapChain, D9Real::D3DRASTER_STATUS* pRasterStatus);
		STDMETHOD(SetDialogBoxMode)(THIS_ BOOL bEnableDialogs);
		STDMETHOD_(void, SetGammaRamp)(THIS_ UINT iSwapChain, DWORD Flags, CONST D9Real::D3DGAMMARAMP* pRamp);
		STDMETHOD_(void, GetGammaRamp)(THIS_ UINT iSwapChain, D9Real::D3DGAMMARAMP* pRamp);
		STDMETHOD(CreateTexture)(THIS_ UINT Width, UINT Height, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DTexture9** ppTexture, HANDLE* pSharedHandle);
		STDMETHOD(CreateVolumeTexture)(THIS_ UINT Width, UINT Height, UINT Depth, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DVolumeTexture9** ppVolumeTexture, HANDLE* pSharedHandle);
		STDMETHOD(CreateCubeTexture)(THIS_ UINT EdgeLength, UINT Levels, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DCubeTexture9** ppCubeTexture, HANDLE* pSharedHandle);
		STDMETHOD(CreateVertexBuffer)(THIS_ UINT Length, DWORD Usage, DWORD FVF, D9Real::D3DPOOL Pool, D9Real::IDirect3DVertexBuffer9** ppVertexBuffer, HANDLE* pSharedHandle);
		STDMETHOD(CreateIndexBuffer)(THIS_ UINT Length, DWORD Usage, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DIndexBuffer9** ppIndexBuffer, HANDLE* pSharedHandle);
		STDMETHOD(CreateRenderTarget)(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Lockable, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
		STDMETHOD(CreateDepthStencilSurface)(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DMULTISAMPLE_TYPE MultiSample, DWORD MultisampleQuality, BOOL Discard, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
		STDMETHOD(UpdateSurface)(THIS_ D9Real::IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, D9Real::IDirect3DSurface9* pDestinationSurface, CONST POINT* pDestPoint);
		STDMETHOD(UpdateTexture)(THIS_ D9Real::IDirect3DBaseTexture9* pSourceTexture, D9Real::IDirect3DBaseTexture9* pDestinationTexture);
		STDMETHOD(GetRenderTargetData)(THIS_ D9Real::IDirect3DSurface9* pRenderTarget, D9Real::IDirect3DSurface9* pDestSurface);
		STDMETHOD(GetFrontBufferData)(THIS_ UINT iSwapChain, D9Real::IDirect3DSurface9* pDestSurface);
		STDMETHOD(StretchRect)(THIS_ D9Real::IDirect3DSurface9* pSourceSurface, CONST RECT* pSourceRect, D9Real::IDirect3DSurface9* pDestSurface, CONST RECT* pDestRect, D9Real::D3DTEXTUREFILTERTYPE Filter);
		STDMETHOD(ColorFill)(THIS_ D9Real::IDirect3DSurface9* pSurface, CONST RECT* pRect, D9Real::D3DCOLOR color);
		STDMETHOD(CreateOffscreenPlainSurface)(THIS_ UINT Width, UINT Height, D9Real::D3DFORMAT Format, D9Real::D3DPOOL Pool, D9Real::IDirect3DSurface9** ppSurface, HANDLE* pSharedHandle);
		STDMETHOD(SetRenderTarget)(THIS_ DWORD RenderTargetIndex, D9Real::IDirect3DSurface9* pRenderTarget);
		STDMETHOD(GetRenderTarget)(THIS_ DWORD RenderTargetIndex, D9Real::IDirect3DSurface9** ppRenderTarget);
		STDMETHOD(SetDepthStencilSurface)(THIS_ D9Real::IDirect3DSurface9* pNewZStencil);
		STDMETHOD(GetDepthStencilSurface)(THIS_ D9Real::IDirect3DSurface9** ppZStencilSurface);
		STDMETHOD(BeginScene)(THIS);
		STDMETHOD(EndScene)(THIS);
		STDMETHOD(Clear)(THIS_ DWORD Count, CONST D9Real::D3DRECT* pRects, DWORD Flags, D9Real::D3DCOLOR Color, float Z, DWORD Stencil);
		STDMETHOD(SetTransform)(THIS_ D9Real::D3DTRANSFORMSTATETYPE State, CONST D9Real::D3DMATRIX* pMatrix);
		STDMETHOD(GetTransform)(THIS_ D9Real::D3DTRANSFORMSTATETYPE State, D9Real::D3DMATRIX* pMatrix);
		STDMETHOD(MultiplyTransform)(THIS_ D9Real::D3DTRANSFORMSTATETYPE, CONST D9Real::D3DMATRIX*);
		STDMETHOD(SetViewport)(THIS_ CONST D9Real::D3DVIEWPORT9* pViewport);
		STDMETHOD(GetViewport)(THIS_ D9Real::D3DVIEWPORT9* pViewport);
		STDMETHOD(SetMaterial)(THIS_ CONST D9Real::D3DMATERIAL9* pMaterial);
		STDMETHOD(GetMaterial)(THIS_ D9Real::D3DMATERIAL9* pMaterial);
		STDMETHOD(SetLight)(THIS_ DWORD Index, CONST D9Real::D3DLIGHT9*);
		STDMETHOD(GetLight)(THIS_ DWORD Index, D9Real::D3DLIGHT9*);
		STDMETHOD(LightEnable)(THIS_ DWORD Index, BOOL Enable);
		STDMETHOD(GetLightEnable)(THIS_ DWORD Index, BOOL* pEnable);
		STDMETHOD(SetClipPlane)(THIS_ DWORD Index, CONST float* pPlane);
		STDMETHOD(GetClipPlane)(THIS_ DWORD Index, float* pPlane);
		STDMETHOD(SetRenderState)(THIS_ D9Real::D3DRENDERSTATETYPE State, DWORD Value);
		STDMETHOD(GetRenderState)(THIS_ D9Real::D3DRENDERSTATETYPE State, DWORD* pValue);
		STDMETHOD(CreateStateBlock)(THIS_ D9Real::D3DSTATEBLOCKTYPE Type, D9Real::IDirect3DStateBlock9** ppSB);
		STDMETHOD(BeginStateBlock)(THIS);
		STDMETHOD(EndStateBlock)(THIS_ D9Real::IDirect3DStateBlock9** ppSB);
		STDMETHOD(SetClipStatus)(THIS_ CONST D9Real::D3DCLIPSTATUS9* pClipStatus);
		STDMETHOD(GetClipStatus)(THIS_ D9Real::D3DCLIPSTATUS9* pClipStatus);
		STDMETHOD(GetTexture)(THIS_ DWORD Stage, D9Real::IDirect3DBaseTexture9** ppTexture);
		STDMETHOD(SetTexture)(THIS_ DWORD Stage, D9Real::IDirect3DBaseTexture9* pTexture);
		STDMETHOD(GetTextureStageState)(THIS_ DWORD Stage, D9Real::D3DTEXTURESTAGESTATETYPE Type, DWORD* pValue);
		STDMETHOD(SetTextureStageState)(THIS_ DWORD Stage, D9Real::D3DTEXTURESTAGESTATETYPE Type, DWORD Value);
		STDMETHOD(GetSamplerState)(THIS_ DWORD Sampler, D9Real::D3DSAMPLERSTATETYPE Type, DWORD* pValue);
		STDMETHOD(SetSamplerState)(THIS_ DWORD Sampler, D9Real::D3DSAMPLERSTATETYPE Type, DWORD Value);
		STDMETHOD(ValidateDevice)(THIS_ DWORD* pNumPasses);
		STDMETHOD(SetPaletteEntries)(THIS_ UINT PaletteNumber, CONST PALETTEENTRY* pEntries);
		STDMETHOD(GetPaletteEntries)(THIS_ UINT PaletteNumber, PALETTEENTRY* pEntries);
		STDMETHOD(SetCurrentTexturePalette)(THIS_ UINT PaletteNumber);
		STDMETHOD(GetCurrentTexturePalette)(THIS_ UINT* PaletteNumber);
		STDMETHOD(SetScissorRect)(THIS_ CONST RECT* pRect);
		STDMETHOD(GetScissorRect)(THIS_ RECT* pRect);
		STDMETHOD(SetSoftwareVertexProcessing)(THIS_ BOOL bSoftware);
		STDMETHOD_(BOOL, GetSoftwareVertexProcessing)(THIS);
		STDMETHOD(SetNPatchMode)(THIS_ float nSegments);
		STDMETHOD_(float, GetNPatchMode)(THIS);
		STDMETHOD(DrawPrimitive)(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT StartVertex, UINT PrimitiveCount);
		STDMETHOD(DrawIndexedPrimitive)(THIS_ D9Real::D3DPRIMITIVETYPE, INT BaseVertexIndex, UINT MinVertexIndex, UINT NumVertices, UINT startIndex, UINT primCount);
		STDMETHOD(DrawPrimitiveUP)(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT PrimitiveCount, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
		STDMETHOD(DrawIndexedPrimitiveUP)(THIS_ D9Real::D3DPRIMITIVETYPE PrimitiveType, UINT MinVertexIndex, UINT NumVertices, UINT PrimitiveCount, CONST void* pIndexData, D9Real::D3DFORMAT IndexDataFormat, CONST void* pVertexStreamZeroData, UINT VertexStreamZeroStride);
		STDMETHOD(ProcessVertices)(THIS_ UINT SrcStartIndex, UINT DestIndex, UINT VertexCount, D9Real::IDirect3DVertexBuffer9* pDestBuffer, D9Real::IDirect3DVertexDeclaration9* pVertexDecl, DWORD Flags);
		STDMETHOD(CreateVertexDeclaration)(THIS_ CONST D9Real::D3DVERTEXELEMENT9* pVertexElements, D9Real::IDirect3DVertexDeclaration9** ppDecl);
		STDMETHOD(SetVertexDeclaration)(THIS_ D9Real::IDirect3DVertexDeclaration9* pDecl);
		STDMETHOD(GetVertexDeclaration)(THIS_ D9Real::IDirect3DVertexDeclaration9** ppDecl);
		STDMETHOD(SetFVF)(THIS_ DWORD FVF);
		STDMETHOD(GetFVF)(THIS_ DWORD* pFVF);
		STDMETHOD(CreateVertexShader)(THIS_ CONST DWORD* pFunction, D9Real::IDirect3DVertexShader9** ppShader);
		STDMETHOD(SetVertexShader)(THIS_ D9Real::IDirect3DVertexShader9* pShader);
		STDMETHOD(GetVertexShader)(THIS_ D9Real::IDirect3DVertexShader9** ppShader);
		STDMETHOD(SetVertexShaderConstantF)(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
		STDMETHOD(GetVertexShaderConstantF)(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount);
		STDMETHOD(SetVertexShaderConstantI)(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
		STDMETHOD(GetVertexShaderConstantI)(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount);
		STDMETHOD(SetVertexShaderConstantB)(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount);
		STDMETHOD(GetVertexShaderConstantB)(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
		STDMETHOD(SetStreamSource)(THIS_ UINT StreamNumber, D9Real::IDirect3DVertexBuffer9* pStreamData, UINT OffsetInBytes, UINT Stride);
		STDMETHOD(GetStreamSource)(THIS_ UINT StreamNumber, D9Real::IDirect3DVertexBuffer9** ppStreamData, UINT* pOffsetInBytes, UINT* pStride);
		STDMETHOD(SetStreamSourceFreq)(THIS_ UINT StreamNumber, UINT Setting);
		STDMETHOD(GetStreamSourceFreq)(THIS_ UINT StreamNumber, UINT* pSetting);
		STDMETHOD(SetIndices)(THIS_ D9Real::IDirect3DIndexBuffer9* pIndexData);
		STDMETHOD(GetIndices)(THIS_ D9Real::IDirect3DIndexBuffer9** ppIndexData);
		STDMETHOD(CreatePixelShader)(THIS_ CONST DWORD* pFunction, D9Real::IDirect3DPixelShader9** ppShader);
		STDMETHOD(SetPixelShader)(THIS_ D9Real::IDirect3DPixelShader9* pShader);
		STDMETHOD(GetPixelShader)(THIS_ D9Real::IDirect3DPixelShader9** ppShader);
		STDMETHOD(SetPixelShaderConstantF)(THIS_ UINT StartRegister, CONST float* pConstantData, UINT Vector4fCount);
		STDMETHOD(GetPixelShaderConstantF)(THIS_ UINT StartRegister, float* pConstantData, UINT Vector4fCount);
		STDMETHOD(SetPixelShaderConstantI)(THIS_ UINT StartRegister, CONST int* pConstantData, UINT Vector4iCount);
		STDMETHOD(GetPixelShaderConstantI)(THIS_ UINT StartRegister, int* pConstantData, UINT Vector4iCount);
		STDMETHOD(SetPixelShaderConstantB)(THIS_ UINT StartRegister, CONST BOOL* pConstantData, UINT  BoolCount);
		STDMETHOD(GetPixelShaderConstantB)(THIS_ UINT StartRegister, BOOL* pConstantData, UINT BoolCount);
		STDMETHOD(DrawRectPatch)(THIS_ UINT Handle, CONST float* pNumSegs, CONST D9Real::D3DRECTPATCH_INFO* pRectPatchInfo);
		STDMETHOD(DrawTriPatch)(THIS_ UINT Handle, CONST float* pNumSegs, CONST D9Real::D3DTRIPATCH_INFO* pTriPatchInfo);
		STDMETHOD(DeletePatch)(THIS_ UINT Handle);
		STDMETHOD(CreateQuery)(THIS_ D9Real::D3DQUERYTYPE Type, D9Real::IDirect3DQuery9** ppQuery);
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