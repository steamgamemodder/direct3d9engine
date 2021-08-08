#pragma once

#include <windows.h>
#include "direct3d9main.h"

LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
    switch (msg)
    {
    case WM_CLOSE:
        DestroyWindow(hWnd);
        break;

    case WM_PAINT:
    {
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