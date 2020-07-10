#pragma once

#include "d3d11_main.h"

namespace D11Wrapper
{
	class ID3D11DeviceContext : public IUnknown
	{
	protected:
		D11Real::ID3D11DeviceContext* m_ID3D11DeviceContext;

	public:
		ID3D11DeviceContext(D11Real::ID3D11DeviceContext* deviceContext)
		{
			m_ID3D11DeviceContext = deviceContext;
		}

		/*** IUnknown methods ***/
		STDMETHOD(QueryInterface)(THIS_ REFIID riid, void** ppvObj);
		STDMETHOD_(ULONG, AddRef)(THIS);
		STDMETHOD_(ULONG, Release)(THIS);

		/*** ID3D11DeviceChild methods ***/

		virtual void STDMETHODCALLTYPE GetDevice(THIS_ D11Real::ID3D11Device** ppDevice);
		STDMETHOD(GetPrivateData)(THIS_ REFGUID guid, UINT* pDataSize, void* pData);
		STDMETHOD(SetPrivateData)(THIS_ REFGUID guid, UINT DataSize, const void* pData);
		STDMETHOD(SetPrivateDataInterface)(THIS_ REFGUID guid, const IUnknown* pData);

		/*** ID3D11DeviceContext methods ***/

		virtual void STDMETHODCALLTYPE Begin(THIS_ D11Real::ID3D11Asynchronous* pAsync);
		virtual void STDMETHODCALLTYPE ClearDepthStencilView(THIS_ D11Real::ID3D11DepthStencilView* pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil);
		virtual void STDMETHODCALLTYPE ClearRenderTargetView(THIS_ D11Real::ID3D11RenderTargetView* pRenderTargetView, const FLOAT ColorRGBA[4]);
		virtual void STDMETHODCALLTYPE ClearState(THIS);
		virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewFloat(THIS_ D11Real::ID3D11UnorderedAccessView* pUnorderedAccessView, const FLOAT Values[4]);
		virtual void STDMETHODCALLTYPE ClearUnorderedAccessViewUint(THIS_ D11Real::ID3D11UnorderedAccessView* pUnorderedAccessView, const UINT Values[4]);
		virtual void STDMETHODCALLTYPE CopyResource(THIS_ D11Real::ID3D11Resource* pDstResource, D11Real::ID3D11Resource* pSrcResource);
		virtual void STDMETHODCALLTYPE CopyStructureCount(THIS_ D11Real::ID3D11Buffer* pDstBuffer, UINT DstAlignedByteOffset, D11Real::ID3D11UnorderedAccessView* pSrcView);
		virtual void STDMETHODCALLTYPE CopySubresourceRegion(THIS_ D11Real::ID3D11Resource* pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, D11Real::ID3D11Resource* pSrcResource, UINT SrcSubresource, const D11Real::D3D11_BOX* pSrcBox);
		virtual void STDMETHODCALLTYPE CSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers);
		virtual void STDMETHODCALLTYPE CSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers);
		virtual void STDMETHODCALLTYPE CSGetShader(THIS_ D11Real::ID3D11ComputeShader** ppComputeShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances);
		virtual void STDMETHODCALLTYPE CSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE CSGetUnorderedAccessViews(THIS_ UINT StartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView** ppUnorderedAccessViews);
		virtual void STDMETHODCALLTYPE CSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers);
		virtual void STDMETHODCALLTYPE CSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers);
		virtual void STDMETHODCALLTYPE CSSetShader(THIS_ D11Real::ID3D11ComputeShader* pComputeShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances);
		virtual void STDMETHODCALLTYPE CSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE CSSetUnorderedAccessViews(THIS_ UINT StartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView* const* ppUnorderedAccessViews, const UINT* pUAVInitialCounts);
		virtual void STDMETHODCALLTYPE Dispatch(THIS_ UINT ThreadGroupCountX, UINT ThreadGroupCountY, UINT ThreadGroupCountZ);
		virtual void STDMETHODCALLTYPE DispatchIndirect(THIS_ D11Real::ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs);
		virtual void STDMETHODCALLTYPE Draw(THIS_ UINT VertexCount, UINT StartVertexLocation);
		virtual void STDMETHODCALLTYPE DrawAuto(THIS);
		virtual void STDMETHODCALLTYPE DrawIndexed(THIS_ UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation);
		virtual void STDMETHODCALLTYPE DrawIndexedInstanced(THIS_ UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation);
		virtual void STDMETHODCALLTYPE DrawIndexedInstancedIndirect(THIS_ D11Real::ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs);
		virtual void STDMETHODCALLTYPE DrawInstanced(THIS_ UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation);
		virtual void STDMETHODCALLTYPE DrawInstancedIndirect(THIS_ D11Real::ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs);
		virtual void STDMETHODCALLTYPE DSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers);
		virtual void STDMETHODCALLTYPE DSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers);
		virtual void STDMETHODCALLTYPE DSGetShader(THIS_ D11Real::ID3D11DomainShader** ppDomainShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances);
		virtual void STDMETHODCALLTYPE DSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE DSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers);
		virtual void STDMETHODCALLTYPE DSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers);
		virtual void STDMETHODCALLTYPE DSSetShader(THIS_ D11Real::ID3D11DomainShader* pDomainShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances);
		virtual void STDMETHODCALLTYPE DSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE End(THIS_ D11Real::ID3D11Asynchronous* pAsync);
		virtual void STDMETHODCALLTYPE ExecuteCommandList(THIS_ D11Real::ID3D11CommandList* pCommandList, BOOL RestoreContextState);
		STDMETHOD(FinishCommandList)(THIS_ BOOL RestoreDeferredContextState, D11Real::ID3D11CommandList** ppCommandList);
		virtual void STDMETHODCALLTYPE Flush(THIS);
		virtual void STDMETHODCALLTYPE GenerateMips(THIS_ D11Real::ID3D11ShaderResourceView* pShaderResourceView);
		STDMETHOD_(UINT, GetContextFlags)(THIS);
		STDMETHOD(GetData)(THIS_ D11Real::ID3D11Asynchronous* pAsync, void* pData, UINT DataSize, UINT GetDataFlags);
		virtual void STDMETHODCALLTYPE GetPredication(THIS_ D11Real::ID3D11Predicate** ppPredicate, BOOL* pPredicateValue);
		STDMETHOD_(FLOAT, GetResourceMinLOD)(THIS_ D11Real::ID3D11Resource* pResource);
		STDMETHOD_(D11Real::D3D11_DEVICE_CONTEXT_TYPE, GetType)(THIS);
		virtual void STDMETHODCALLTYPE GSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers);
		virtual void STDMETHODCALLTYPE GSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers);
		virtual void STDMETHODCALLTYPE GSGetShader(THIS_ D11Real::ID3D11GeometryShader** ppGeometryShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances);
		virtual void STDMETHODCALLTYPE GSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE GSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers);
		virtual void STDMETHODCALLTYPE GSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers);
		virtual void STDMETHODCALLTYPE GSSetShader(THIS_ D11Real::ID3D11GeometryShader* pShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances);
		virtual void STDMETHODCALLTYPE GSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE HSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers);
		virtual void STDMETHODCALLTYPE HSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers);
		virtual void STDMETHODCALLTYPE HSGetShader(THIS_ D11Real::ID3D11HullShader** ppHullShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances);
		virtual void STDMETHODCALLTYPE HSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE HSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers);
		virtual void STDMETHODCALLTYPE HSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers);
		virtual void STDMETHODCALLTYPE HSSetShader(THIS_ D11Real::ID3D11HullShader* pHullShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances);
		virtual void STDMETHODCALLTYPE HSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE IAGetIndexBuffer(THIS_ D11Real::ID3D11Buffer** pIndexBuffer, D11Real::DXGI_FORMAT* Format, UINT* Offset);
		virtual void STDMETHODCALLTYPE IAGetInputLayout(THIS_ D11Real::ID3D11InputLayout** ppInputLayout);
		virtual void STDMETHODCALLTYPE IAGetPrimitiveTopology(THIS_ D11Real::D3D11_PRIMITIVE_TOPOLOGY* pTopology);
		virtual void STDMETHODCALLTYPE IAGetVertexBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppVertexBuffers, UINT* pStrides, UINT* pOffsets);
		virtual void STDMETHODCALLTYPE IASetIndexBuffer(THIS_ D11Real::ID3D11Buffer* pIndexBuffer, D11Real::DXGI_FORMAT Format, UINT Offset);
		virtual void STDMETHODCALLTYPE IASetInputLayout(THIS_ D11Real::ID3D11InputLayout* pInputLayout);
		virtual void STDMETHODCALLTYPE IASetPrimitiveTopology(THIS_ D11Real::D3D11_PRIMITIVE_TOPOLOGY Topology);
		virtual void STDMETHODCALLTYPE IASetVertexBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppVertexBuffers, const UINT* pStrides, const UINT* pOffsets);
		STDMETHOD(Map)(THIS_ D11Real::ID3D11Resource* pResource, UINT Subresource, D11Real::D3D11_MAP MapType, UINT MapFlags, D11Real::D3D11_MAPPED_SUBRESOURCE* pMappedResource);
		virtual void STDMETHODCALLTYPE OMSetBlendState(THIS_ D11Real::ID3D11BlendState* pBlendState, const FLOAT BlendFactor[4], UINT SampleMask);
		virtual void STDMETHODCALLTYPE OMSetDepthStencilState(THIS_ D11Real::ID3D11DepthStencilState* pDepthStencilState, UINT StencilRef);
		virtual void STDMETHODCALLTYPE OMGetRenderTargets(THIS_ UINT NumViews, D11Real::ID3D11RenderTargetView** ppRenderTargetViews, D11Real::ID3D11DepthStencilView** ppDepthStencilView);
		virtual void STDMETHODCALLTYPE OMGetRenderTargetsAndUnorderedAccessViews(THIS_ UINT NumRTVs, D11Real::ID3D11RenderTargetView** ppRenderTargetViews, D11Real::ID3D11DepthStencilView** ppDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView** ppUnorderedAccessViews);
		virtual void STDMETHODCALLTYPE OMGetBlendState(THIS_ D11Real::ID3D11BlendState** ppBlendState, FLOAT BlendFactor[4], UINT* pSampleMask);
		virtual void STDMETHODCALLTYPE OMGetDepthStencilState(THIS_ D11Real::ID3D11DepthStencilState** ppDepthStencilState, UINT* pStencilRef);
		virtual void STDMETHODCALLTYPE OMSetRenderTargets(THIS_ UINT NumViews, D11Real::ID3D11RenderTargetView* const* ppRenderTargetViews, D11Real::ID3D11DepthStencilView* pDepthStencilView);
		virtual void STDMETHODCALLTYPE OMSetRenderTargetsAndUnorderedAccessViews(THIS_ UINT NumRTVs, D11Real::ID3D11RenderTargetView* const* ppRenderTargetViews, D11Real::ID3D11DepthStencilView* pDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView* const* ppUnorderedAccessViews, const UINT* pUAVInitialCounts);
		virtual void STDMETHODCALLTYPE PSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers);
		virtual void STDMETHODCALLTYPE PSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers);
		virtual void STDMETHODCALLTYPE PSGetShader(THIS_ D11Real::ID3D11PixelShader** ppPixelShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances);
		virtual void STDMETHODCALLTYPE PSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE PSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers);
		virtual void STDMETHODCALLTYPE PSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers);
		virtual void STDMETHODCALLTYPE PSSetShader(THIS_ D11Real::ID3D11PixelShader* pPixelShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances);
		virtual void STDMETHODCALLTYPE PSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE ResolveSubresource(THIS_ D11Real::ID3D11Resource* pDstResource, UINT DstSubresource, D11Real::ID3D11Resource* pSrcResource, UINT SrcSubresource, D11Real::DXGI_FORMAT Format);
		virtual void STDMETHODCALLTYPE RSGetScissorRects(THIS_ UINT* pNumRects, D11Real::D3D11_RECT* pRects);
		virtual void STDMETHODCALLTYPE RSGetState(THIS_ D11Real::ID3D11RasterizerState** ppRasterizerState);
		virtual void STDMETHODCALLTYPE RSGetViewports(THIS_ UINT* pNumViewports, D11Real::D3D11_VIEWPORT* pViewports);
		virtual void STDMETHODCALLTYPE RSSetScissorRects(THIS_ UINT NumRects, const D11Real::D3D11_RECT* pRects);
		virtual void STDMETHODCALLTYPE RSSetState(THIS_ D11Real::ID3D11RasterizerState* pRasterizerState);
		virtual void STDMETHODCALLTYPE RSSetViewports(THIS_ UINT NumViewports, const D11Real::D3D11_VIEWPORT* pViewports);
		virtual void STDMETHODCALLTYPE SetPredication(THIS_ D11Real::ID3D11Predicate* pPredicate, BOOL PredicateValue);
		virtual void STDMETHODCALLTYPE SetResourceMinLOD(THIS_ D11Real::ID3D11Resource* pResource, FLOAT MinLOD);
		virtual void STDMETHODCALLTYPE SOGetTargets(THIS_ UINT NumBuffers, D11Real::ID3D11Buffer** ppSOTargets);
		virtual void STDMETHODCALLTYPE SOSetTargets(THIS_ UINT NumBuffers, D11Real::ID3D11Buffer* const* ppSOTargets, const UINT* pOffsets);
		virtual void STDMETHODCALLTYPE Unmap(THIS_ D11Real::ID3D11Resource* pResource, UINT Subresource);
		virtual void STDMETHODCALLTYPE UpdateSubresource(THIS_ D11Real::ID3D11Resource* pDstResource, UINT DstSubresource, const D11Real::D3D11_BOX* pDstBox, const void* pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch);
		virtual void STDMETHODCALLTYPE VSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers);
		virtual void STDMETHODCALLTYPE VSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers);
		virtual void STDMETHODCALLTYPE VSGetShader(THIS_ D11Real::ID3D11VertexShader** ppVertexShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances);
		virtual void STDMETHODCALLTYPE VSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews);
		virtual void STDMETHODCALLTYPE VSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers);
		virtual void STDMETHODCALLTYPE VSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers);
		virtual void STDMETHODCALLTYPE VSSetShader(THIS_ D11Real::ID3D11VertexShader* pVertexShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances);
		virtual void STDMETHODCALLTYPE VSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews);
	};
}