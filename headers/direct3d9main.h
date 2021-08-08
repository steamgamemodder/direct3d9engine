#pragma once

#include <d3d9.h>
#include <d3dx9.h>
#include <windows.h>
#include <windowsx.h>

#pragma comment (lib, "d3d9.lib")

class d3d9render //rendering function class
{
public:

	LPDIRECT3DDEVICE9 d3ddev;
	IDirect3DDevice9** devicepointer;
	LPDIRECT3D9 g_pD3D = NULL; //d3d9 setup

	void CreateD3D(HWND hWnd) //create the d3d device
	{
		g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
		D3DPRESENT_PARAMETERS d3dpp;
		ZeroMemory(&d3dpp, sizeof(d3dpp));

		d3dpp.Windowed = TRUE;
		d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
		d3dpp.hDeviceWindow = hWnd;
		d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;

		g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &d3ddev);
	}

	void CloseD3D() //destroy the d3d device
	{
		d3ddev->Release();
		g_pD3D->Release();
	}

	void RenderFrame(void) //render and present the d3d frame
	{
		d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0); //clear to background color
		d3ddev->BeginScene();
		//render
		d3ddev->EndScene();
		d3ddev->Present(NULL, NULL, NULL, NULL);
	}

	//void CreateD3D(UINT adapter, D3DDEVTYPE devicetype, HWND hwnd, DWORD flags, bool windowed, UINT refreshrate, UINT bufferheight, UINT bufferwidth)
	//{
	//	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	//	ZeroMemory(&d3dpp, sizeof(d3dpp));
	//	d3dpp.hDeviceWindow = hwnd;
	//	d3dpp.Windowed = windowed;
	//	d3dpp.FullScreen_RefreshRateInHz = 0;
	//	d3dpp.BackBufferHeight = 0;
	//	d3dpp.BackBufferWidth = 0;
	//	d3dpp.BackBufferCount = 1;
	//	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	//	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	//	if (!windowed) //if fullscreen
	//	{
	//		d3dpp.FullScreen_RefreshRateInHz = refreshrate;
	//		d3dpp.BackBufferHeight = bufferheight;
	//		d3dpp.BackBufferWidth = bufferwidth;
	//	}

	//	g_pD3D->CreateDevice(adapter, devicetype, hwnd, flags, &d3dpp, &d3ddev);
	//}
};