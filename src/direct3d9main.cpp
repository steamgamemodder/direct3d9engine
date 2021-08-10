#include "direct3d9main.h"
#include "renderprimitives.h"
#include "winmain.h"

LPDIRECT3DDEVICE9 d3ddev;
IDirect3DDevice9** devicepointer;
LPDIRECT3D9 g_pD3D = NULL; //d3d9 setup

void d3d9render::CreateD3D(HWND hWnd) //create the d3d device
{
	g_pD3D = Direct3DCreate9(D3D_SDK_VERSION);
	D3DPRESENT_PARAMETERS d3dpp;
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = TRUE;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = windowWidth;
	d3dpp.BackBufferHeight = windowHeight;

	g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_MIXED_VERTEXPROCESSING, &d3dpp, &d3ddev);
}

void d3d9render::CloseD3D() //destroy the d3d device
{
	d3ddev->Release();
	g_pD3D->Release();
}

void d3d9render::RenderFrame(void) //render and present the d3d frame
{
	d3ddev->Clear(0, NULL, D3DCLEAR_TARGET, D3DCOLOR_XRGB(0, 0, 0), 1.0f, 0); //clear to background color
	d3ddev->BeginScene();

	d3ddev->EndScene();
	d3ddev->Present(NULL, NULL, NULL, NULL);
}