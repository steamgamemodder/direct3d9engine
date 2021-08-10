#pragma once

#include <windows.h>
#include "direct3d9main.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {

    case WM_PAINT:
    {
        d3d9render d3d;

        d3d.CreateD3D(hWnd);
        d3d.RenderFrame();
        break;
    }

    case WM_CLOSE:
    {
        DestroyWindow(hWnd);
        break;
    }

    default:
        break;

    case WM_DESTROY:
        PostQuitMessage(0);
        return 0;
        break;
    }

    return DefWindowProc(hWnd, msg, wParam, lParam);
}