#include "ID3D11DeviceContext.h"

namespace D11Wrapper
{
	// IUnknown Functions
	STDMETHODIMP ID3D11DeviceContext::QueryInterface(THIS_ REFIID riid, void** ppvObject)
	{
		return m_ID3D11DeviceContext->QueryInterface(riid, ppvObject);
	}

	STDMETHODIMP_(ULONG) ID3D11DeviceContext::AddRef(THIS)
	{
		return m_ID3D11DeviceContext->AddRef();
	}

	STDMETHODIMP_(ULONG) ID3D11DeviceContext::Release(THIS)
	{
		return m_ID3D11DeviceContext->Release();
	}

	// ID3D11DeviceChild Functions

	void STDMETHODCALLTYPE ID3D11DeviceContext::GetDevice(THIS_ D11Real::ID3D11Device** ppDevice)
	{
		m_ID3D11DeviceContext->GetDevice(ppDevice);
	}

	STDMETHODIMP_(HRESULT) ID3D11DeviceContext::GetPrivateData(THIS_ REFGUID guid, UINT* pDataSize, void* pData)
	{
		return m_ID3D11DeviceContext->GetPrivateData(guid, pDataSize, pData);
	}

	STDMETHODIMP_(HRESULT) ID3D11DeviceContext::SetPrivateData(THIS_ REFGUID guid, UINT DataSize, const void* pData)
	{
		return m_ID3D11DeviceContext->SetPrivateData(guid, DataSize, pData);
	}

	STDMETHODIMP_(HRESULT) ID3D11DeviceContext::SetPrivateDataInterface(THIS_ REFGUID guid, const IUnknown* pData)
	{
		return m_ID3D11DeviceContext->SetPrivateDataInterface(guid, pData);
	}

	// ID3D11DeviceContext Functions

	void STDMETHODCALLTYPE ID3D11DeviceContext::Begin(THIS_ D11Real::ID3D11Asynchronous* pAsync)
	{
		m_ID3D11DeviceContext->Begin(pAsync);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::ClearDepthStencilView(THIS_ D11Real::ID3D11DepthStencilView* pDepthStencilView, UINT ClearFlags, FLOAT Depth, UINT8 Stencil)
	{
		m_ID3D11DeviceContext->ClearDepthStencilView(pDepthStencilView, ClearFlags, Depth, Stencil);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::ClearRenderTargetView(THIS_ D11Real::ID3D11RenderTargetView* pRenderTargetView, const FLOAT ColorRGBA[4])
	{
		m_ID3D11DeviceContext->ClearRenderTargetView(pRenderTargetView, ColorRGBA);
	}


	void STDMETHODCALLTYPE ID3D11DeviceContext::ClearState(THIS)
	{
		m_ID3D11DeviceContext->ClearState();
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::ClearUnorderedAccessViewFloat(THIS_ D11Real::ID3D11UnorderedAccessView* pUnorderedAccessView, const FLOAT Values[4])
	{
		m_ID3D11DeviceContext->ClearUnorderedAccessViewFloat(pUnorderedAccessView, Values);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::ClearUnorderedAccessViewUint(THIS_ D11Real::ID3D11UnorderedAccessView* pUnorderedAccessView, const UINT Values[4])
	{
		m_ID3D11DeviceContext->ClearUnorderedAccessViewUint(pUnorderedAccessView, Values);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CopyResource(THIS_ D11Real::ID3D11Resource* pDstResource, D11Real::ID3D11Resource* pSrcResource)
	{
		m_ID3D11DeviceContext->CopyResource(pDstResource, pSrcResource);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CopyStructureCount(THIS_ D11Real::ID3D11Buffer* pDstBuffer, UINT DstAlignedByteOffset, D11Real::ID3D11UnorderedAccessView* pSrcView)
	{
		m_ID3D11DeviceContext->CopyStructureCount(pDstBuffer, DstAlignedByteOffset, pSrcView);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CopySubresourceRegion(THIS_ D11Real::ID3D11Resource* pDstResource, UINT DstSubresource, UINT DstX, UINT DstY, UINT DstZ, D11Real::ID3D11Resource* pSrcResource, UINT SrcSubresource, __in_opt  const D11Real::D3D11_BOX* pSrcBox)
	{
		m_ID3D11DeviceContext->CopySubresourceRegion(pDstResource, DstSubresource, DstX, DstY, DstZ, pSrcResource, SrcSubresource, pSrcBox);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers)
	{
		m_ID3D11DeviceContext->CSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers)
	{
		m_ID3D11DeviceContext->CSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSGetShader(THIS_ D11Real::ID3D11ComputeShader** ppComputeShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
	{
		m_ID3D11DeviceContext->CSGetShader(ppComputeShader, ppClassInstances, pNumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->CSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSGetUnorderedAccessViews(THIS_ UINT StartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView** ppUnorderedAccessViews)
	{
		m_ID3D11DeviceContext->CSGetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers)
	{
		m_ID3D11DeviceContext->CSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers)
	{
		m_ID3D11DeviceContext->CSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSSetShader(THIS_ D11Real::ID3D11ComputeShader* pComputeShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
	{
		m_ID3D11DeviceContext->CSSetShader(pComputeShader, ppClassInstances, NumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->CSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::CSSetUnorderedAccessViews(THIS_ UINT StartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView* const* ppUnorderedAccessViews, const UINT* pUAVInitialCounts)
	{
		m_ID3D11DeviceContext->CSSetUnorderedAccessViews(StartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::Dispatch(THIS_ UINT ThreadGroupCountX, UINT ThreadGroupCountY, UINT ThreadGroupCountZ)
	{
		m_ID3D11DeviceContext->Dispatch(ThreadGroupCountX, ThreadGroupCountY, ThreadGroupCountZ);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DispatchIndirect(THIS_ D11Real::ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		m_ID3D11DeviceContext->DispatchIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::Draw(THIS_ UINT VertexCount, UINT StartVertexLocation)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->Draw(VertexCount, StartVertexLocation);
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DrawAuto(THIS)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->DrawAuto();
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DrawIndexed(THIS_ UINT IndexCount, UINT StartIndexLocation, INT BaseVertexLocation)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->DrawIndexed(IndexCount, StartIndexLocation, BaseVertexLocation);
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DrawIndexedInstanced(THIS_ UINT IndexCountPerInstance, UINT InstanceCount, UINT StartIndexLocation, INT BaseVertexLocation, UINT StartInstanceLocation)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->DrawIndexedInstanced(IndexCountPerInstance, InstanceCount, StartIndexLocation, BaseVertexLocation, StartInstanceLocation);
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DrawIndexedInstancedIndirect(THIS_ D11Real::ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->DrawIndexedInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DrawInstanced(THIS_ UINT VertexCountPerInstance, UINT InstanceCount, UINT StartVertexLocation, UINT StartInstanceLocation)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->DrawInstanced(VertexCountPerInstance, InstanceCount, StartVertexLocation, StartInstanceLocation);
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DrawInstancedIndirect(THIS_ D11Real::ID3D11Buffer* pBufferForArgs, UINT AlignedByteOffsetForArgs)
	{
		if (F4DX_manager::getManager().shouldDraw())
		{
			m_ID3D11DeviceContext->DrawInstancedIndirect(pBufferForArgs, AlignedByteOffsetForArgs);
		}
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers)
	{
		m_ID3D11DeviceContext->DSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers)
	{
		m_ID3D11DeviceContext->DSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSGetShader(THIS_ D11Real::ID3D11DomainShader** ppDomainShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
	{
		m_ID3D11DeviceContext->DSGetShader(ppDomainShader, ppClassInstances, pNumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->DSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers)
	{
		m_ID3D11DeviceContext->DSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers)
	{
		m_ID3D11DeviceContext->DSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSSetShader(THIS_ D11Real::ID3D11DomainShader* pDomainShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
	{
		m_ID3D11DeviceContext->DSSetShader(pDomainShader, ppClassInstances, NumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::DSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->DSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::End(THIS_ D11Real::ID3D11Asynchronous* pAsync)
	{
		m_ID3D11DeviceContext->End(pAsync);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::ExecuteCommandList(THIS_ D11Real::ID3D11CommandList* pCommandList, BOOL RestoreContextState)
	{
		m_ID3D11DeviceContext->ExecuteCommandList(pCommandList, RestoreContextState);
	}

	STDMETHODIMP_(HRESULT) ID3D11DeviceContext::FinishCommandList(THIS_ BOOL RestoreDeferredContextState, D11Real::ID3D11CommandList** ppCommandList)
	{
		return m_ID3D11DeviceContext->FinishCommandList(RestoreDeferredContextState, ppCommandList);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::Flush(THIS)
	{
		m_ID3D11DeviceContext->Flush();
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GenerateMips(THIS_ D11Real::ID3D11ShaderResourceView* pShaderResourceView)
	{
		m_ID3D11DeviceContext->GenerateMips(pShaderResourceView);
	}

	STDMETHODIMP_(UINT) ID3D11DeviceContext::GetContextFlags(THIS)
	{
		return m_ID3D11DeviceContext->GetContextFlags();
	}

	STDMETHODIMP_(HRESULT) ID3D11DeviceContext::GetData(THIS_ D11Real::ID3D11Asynchronous* pAsync, void* pData, UINT DataSize, UINT GetDataFlags)
	{
		return m_ID3D11DeviceContext->GetData(pAsync, pData, DataSize, GetDataFlags);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GetPredication(THIS_ D11Real::ID3D11Predicate** ppPredicate, BOOL* pPredicateValue)
	{
		m_ID3D11DeviceContext->GetPredication(ppPredicate, pPredicateValue);
	}

	STDMETHODIMP_(FLOAT) ID3D11DeviceContext::GetResourceMinLOD(THIS_ D11Real::ID3D11Resource* pResource)
	{
		return m_ID3D11DeviceContext->GetResourceMinLOD(pResource);
	}

	STDMETHODIMP_(D11Real::D3D11_DEVICE_CONTEXT_TYPE) ID3D11DeviceContext::GetType(THIS)
	{
		return m_ID3D11DeviceContext->GetType();
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers)
	{
		m_ID3D11DeviceContext->GSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers)
	{
		m_ID3D11DeviceContext->GSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSGetShader(THIS_ D11Real::ID3D11GeometryShader** ppGeometryShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
	{
		m_ID3D11DeviceContext->GSGetShader(ppGeometryShader, ppClassInstances, pNumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->GSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers)
	{
		m_ID3D11DeviceContext->GSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers)
	{
		m_ID3D11DeviceContext->GSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSSetShader(THIS_ D11Real::ID3D11GeometryShader* pShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
	{
		m_ID3D11DeviceContext->GSSetShader(pShader, ppClassInstances, NumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::GSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->GSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers)
	{
		m_ID3D11DeviceContext->HSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers)
	{
		m_ID3D11DeviceContext->HSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSGetShader(THIS_ D11Real::ID3D11HullShader** ppHullShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
	{
		m_ID3D11DeviceContext->HSGetShader(ppHullShader, ppClassInstances, pNumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->HSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers)
	{
		m_ID3D11DeviceContext->HSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers)
	{
		m_ID3D11DeviceContext->HSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSSetShader(THIS_ D11Real::ID3D11HullShader* pHullShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
	{
		m_ID3D11DeviceContext->HSSetShader(pHullShader, ppClassInstances, NumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::HSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->HSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IAGetIndexBuffer(THIS_ D11Real::ID3D11Buffer** pIndexBuffer, D11Real::DXGI_FORMAT* Format, UINT* Offset)
	{
		m_ID3D11DeviceContext->IAGetIndexBuffer(pIndexBuffer, Format, Offset);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IAGetInputLayout(THIS_ D11Real::ID3D11InputLayout** ppInputLayout)
	{
		m_ID3D11DeviceContext->IAGetInputLayout(ppInputLayout);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IAGetPrimitiveTopology(THIS_ D11Real::D3D11_PRIMITIVE_TOPOLOGY* pTopology)
	{
		m_ID3D11DeviceContext->IAGetPrimitiveTopology(pTopology);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IAGetVertexBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppVertexBuffers, UINT* pStrides, UINT* pOffsets)
	{
		m_ID3D11DeviceContext->IAGetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IASetIndexBuffer(THIS_ D11Real::ID3D11Buffer* pIndexBuffer, D11Real::DXGI_FORMAT Format, UINT Offset)
	{
		m_ID3D11DeviceContext->IASetIndexBuffer(pIndexBuffer, Format, Offset);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IASetInputLayout(THIS_ D11Real::ID3D11InputLayout* pInputLayout)
	{
		m_ID3D11DeviceContext->IASetInputLayout(pInputLayout);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IASetPrimitiveTopology(THIS_ D11Real::D3D11_PRIMITIVE_TOPOLOGY Topology)
	{
		m_ID3D11DeviceContext->IASetPrimitiveTopology(Topology);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::IASetVertexBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppVertexBuffers, const UINT* pStrides, const UINT* pOffsets)
	{
		m_ID3D11DeviceContext->IASetVertexBuffers(StartSlot, NumBuffers, ppVertexBuffers, pStrides, pOffsets);
	}

	STDMETHODIMP_(HRESULT) ID3D11DeviceContext::Map(THIS_ D11Real::ID3D11Resource* pResource, UINT Subresource, D11Real::D3D11_MAP MapType, UINT MapFlags, D11Real::D3D11_MAPPED_SUBRESOURCE* pMappedResource)
	{
		return m_ID3D11DeviceContext->Map(pResource, Subresource, MapType, MapFlags, pMappedResource);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMSetBlendState(THIS_ D11Real::ID3D11BlendState* pBlendState, const FLOAT BlendFactor[4], UINT SampleMask)
	{
		m_ID3D11DeviceContext->OMSetBlendState(pBlendState, BlendFactor, SampleMask);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMSetDepthStencilState(THIS_ D11Real::ID3D11DepthStencilState* pDepthStencilState, UINT StencilRef)
	{
		m_ID3D11DeviceContext->OMSetDepthStencilState(pDepthStencilState, StencilRef);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMGetRenderTargets(THIS_ UINT NumViews, D11Real::ID3D11RenderTargetView** ppRenderTargetViews, D11Real::ID3D11DepthStencilView** ppDepthStencilView)
	{
		m_ID3D11DeviceContext->OMGetRenderTargets(NumViews, ppRenderTargetViews, ppDepthStencilView);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMGetRenderTargetsAndUnorderedAccessViews(THIS_ UINT NumRTVs, D11Real::ID3D11RenderTargetView** ppRenderTargetViews, D11Real::ID3D11DepthStencilView** ppDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView** ppUnorderedAccessViews)
	{
		m_ID3D11DeviceContext->OMGetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, ppDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMGetBlendState(THIS_ D11Real::ID3D11BlendState** ppBlendState, FLOAT BlendFactor[4], UINT* pSampleMask)
	{
		m_ID3D11DeviceContext->OMGetBlendState(ppBlendState, BlendFactor, pSampleMask);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMGetDepthStencilState(THIS_ D11Real::ID3D11DepthStencilState** ppDepthStencilState, UINT* pStencilRef)
	{
		m_ID3D11DeviceContext->OMGetDepthStencilState(ppDepthStencilState, pStencilRef);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMSetRenderTargets(THIS_ UINT NumViews, D11Real::ID3D11RenderTargetView* const* ppRenderTargetViews, D11Real::ID3D11DepthStencilView* pDepthStencilView)
	{
		m_ID3D11DeviceContext->OMSetRenderTargets(NumViews, ppRenderTargetViews, pDepthStencilView);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::OMSetRenderTargetsAndUnorderedAccessViews(THIS_ UINT NumRTVs, D11Real::ID3D11RenderTargetView* const* ppRenderTargetViews, D11Real::ID3D11DepthStencilView* pDepthStencilView, UINT UAVStartSlot, UINT NumUAVs, D11Real::ID3D11UnorderedAccessView* const* ppUnorderedAccessViews, const UINT* pUAVInitialCounts)
	{
		m_ID3D11DeviceContext->OMSetRenderTargetsAndUnorderedAccessViews(NumRTVs, ppRenderTargetViews, pDepthStencilView, UAVStartSlot, NumUAVs, ppUnorderedAccessViews, pUAVInitialCounts);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers)
	{
		m_ID3D11DeviceContext->PSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers)
	{
		m_ID3D11DeviceContext->PSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSGetShader(THIS_ D11Real::ID3D11PixelShader** ppPixelShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
	{
		m_ID3D11DeviceContext->PSGetShader(ppPixelShader, ppClassInstances, pNumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->PSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers)
	{
		m_ID3D11DeviceContext->PSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers)
	{
		m_ID3D11DeviceContext->PSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSSetShader(THIS_ D11Real::ID3D11PixelShader* pPixelShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
	{
		m_ID3D11DeviceContext->PSSetShader(pPixelShader, ppClassInstances, NumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::PSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->PSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::ResolveSubresource(THIS_ D11Real::ID3D11Resource* pDstResource, UINT DstSubresource, D11Real::ID3D11Resource* pSrcResource, UINT SrcSubresource, D11Real::DXGI_FORMAT Format)
	{
		m_ID3D11DeviceContext->ResolveSubresource(pDstResource, DstSubresource, pSrcResource, SrcSubresource, Format);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::RSGetScissorRects(THIS_ UINT* pNumRects, D11Real::D3D11_RECT* pRects)
	{
		m_ID3D11DeviceContext->RSGetScissorRects(pNumRects, pRects);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::RSGetState(THIS_ D11Real::ID3D11RasterizerState** ppRasterizerState)
	{
		m_ID3D11DeviceContext->RSGetState(ppRasterizerState);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::RSGetViewports(THIS_ UINT* pNumViewports, D11Real::D3D11_VIEWPORT* pViewports)
	{
		m_ID3D11DeviceContext->RSGetViewports(pNumViewports, pViewports);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::RSSetScissorRects(THIS_ UINT NumRects, const D11Real::D3D11_RECT* pRects)
	{
		m_ID3D11DeviceContext->RSSetScissorRects(NumRects, pRects);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::RSSetState(THIS_ D11Real::ID3D11RasterizerState* pRasterizerState)
	{
		m_ID3D11DeviceContext->RSSetState(pRasterizerState);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::RSSetViewports(THIS_ UINT NumViewports, const D11Real::D3D11_VIEWPORT* pViewports)
	{
		m_ID3D11DeviceContext->RSSetViewports(NumViewports, pViewports);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::SetPredication(THIS_ D11Real::ID3D11Predicate* pPredicate, BOOL PredicateValue)
	{
		m_ID3D11DeviceContext->SetPredication(pPredicate, PredicateValue);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::SetResourceMinLOD(THIS_ D11Real::ID3D11Resource* pResource, FLOAT MinLOD)
	{
		m_ID3D11DeviceContext->SetResourceMinLOD(pResource, MinLOD);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::SOGetTargets(THIS_ UINT NumBuffers, D11Real::ID3D11Buffer** ppSOTargets)
	{
		m_ID3D11DeviceContext->SOGetTargets(NumBuffers, ppSOTargets);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::SOSetTargets(THIS_ UINT NumBuffers, D11Real::ID3D11Buffer* const* ppSOTargets, const UINT* pOffsets)
	{
		m_ID3D11DeviceContext->SOSetTargets(NumBuffers, ppSOTargets, pOffsets);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::Unmap(THIS_ D11Real::ID3D11Resource* pResource, UINT Subresource)
	{
		m_ID3D11DeviceContext->Unmap(pResource, Subresource);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::UpdateSubresource(THIS_ D11Real::ID3D11Resource* pDstResource, UINT DstSubresource, const D11Real::D3D11_BOX* pDstBox, const void* pSrcData, UINT SrcRowPitch, UINT SrcDepthPitch)
	{
		m_ID3D11DeviceContext->UpdateSubresource(pDstResource, DstSubresource, pDstBox, pSrcData, SrcRowPitch, SrcDepthPitch);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSGetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer** ppConstantBuffers)
	{
		m_ID3D11DeviceContext->VSGetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSGetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState** ppSamplers)
	{
		m_ID3D11DeviceContext->VSGetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSGetShader(THIS_ D11Real::ID3D11VertexShader** ppVertexShader, D11Real::ID3D11ClassInstance** ppClassInstances, UINT* pNumClassInstances)
	{
		m_ID3D11DeviceContext->VSGetShader(ppVertexShader, ppClassInstances, pNumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSGetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView** ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->VSGetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSSetConstantBuffers(THIS_ UINT StartSlot, UINT NumBuffers, D11Real::ID3D11Buffer* const* ppConstantBuffers)
	{
		m_ID3D11DeviceContext->VSSetConstantBuffers(StartSlot, NumBuffers, ppConstantBuffers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSSetSamplers(THIS_ UINT StartSlot, UINT NumSamplers, D11Real::ID3D11SamplerState* const* ppSamplers)
	{
		m_ID3D11DeviceContext->VSSetSamplers(StartSlot, NumSamplers, ppSamplers);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSSetShader(THIS_ D11Real::ID3D11VertexShader* pVertexShader, D11Real::ID3D11ClassInstance* const* ppClassInstances, UINT NumClassInstances)
	{
		m_ID3D11DeviceContext->VSSetShader(pVertexShader, ppClassInstances, NumClassInstances);
	}

	void STDMETHODCALLTYPE ID3D11DeviceContext::VSSetShaderResources(THIS_ UINT StartSlot, UINT NumViews, D11Real::ID3D11ShaderResourceView* const* ppShaderResourceViews)
	{
		m_ID3D11DeviceContext->VSSetShaderResources(StartSlot, NumViews, ppShaderResourceViews);
	}
}