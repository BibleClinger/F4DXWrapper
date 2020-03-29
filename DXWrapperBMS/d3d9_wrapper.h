#pragma once
#define D9EXPORT comment(linker, "/EXPORT:" __FUNCTION__ "=" __FUNCDNAME__)

namespace D9Wrapper
{
	//class ID9WrapperUnknown;
	class IDirect3D9;
	class IDirect3D9Ex;
	class IDirect3DDevice9;
	class IDirect3DDevice9Ex;
}

// Typedefs

typedef D9Real::IDirect3D9* (WINAPI* fnDirect3DCreate9)(UINT);
typedef HRESULT (WINAPI* fnDirect3DCreate9Ex)(UINT, D9Real::IDirect3D9Ex**);

// DX9 Hook function

D9Wrapper::IDirect3D9* WINAPI Direct3DCreate9(UINT SDKVersion);
HRESULT WINAPI Direct3DCreate9Ex(UINT SDKVersion, D9Wrapper::IDirect3D9Ex**);