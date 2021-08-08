#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>

class d3d9render
{
public:

	LPDIRECT3D9 g_pD3D = NULL; //d3d9 setup
	D3DPRESENT_PARAMETERS d3dpp;
	IDirect3DDevice9** devicepointer;
	LPDIRECT3DDEVICE9 d3ddev;

	void CreateD3D(UINT adapter, D3DDEVTYPE devicetype, HWND hwnd, DWORD flags, bool windowed, UINT refreshrate, UINT bufferheight, UINT bufferwidth)
	{
		g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
		ZeroMemory(&d3dpp, sizeof(d3dpp));
		d3dpp.hDeviceWindow = hwnd;
		d3dpp.Windowed = windowed;
		d3dpp.FullScreen_RefreshRateInHz = 0;
		d3dpp.BackBufferHeight = 0;
		d3dpp.BackBufferWidth = 0;
		d3dpp.BackBufferCount = 1;
		d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

		if (!windowed) //if fullscreen
		{
			d3dpp.FullScreen_RefreshRateInHz = refreshrate;
			d3dpp.BackBufferHeight = bufferheight;
			d3dpp.BackBufferWidth = bufferwidth;
		}

		g_pD3D->CreateDevice(adapter, devicetype, hwnd, flags, &d3dpp, &d3ddev);
	}
	void CloseD3D() {}
	void SwapBackBuf() {}
};