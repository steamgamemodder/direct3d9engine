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
	LPDIRECT3D9 g_pD3D; //d3d9 setup

	void CreateD3D(HWND hWnd);

	void CloseD3D();

	void RenderFrame(void);

	bool CheckD3DActive();
};