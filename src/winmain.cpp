#include <windows.h>
#include "winmain.h"
#include "winmsghandler.h"
#include "windowcreationhandler.h"

UINT windowWidth = 800;
UINT windowHeight = 600;

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)//win32 main function
{
    WNDCLASS wc = {};
    LPCWSTR wndClass = L"d3d9app";

    wc.lpfnWndProc = WindowProc; //the default message procedure
    wc.hInstance = hInst; //the handle to the instance
    wc.lpszClassName = wndClass; //the class name
    wc.hIcon = nullptr; //the icon
    RegisterClass(&wc); //register the class

    //define vars for hwnd

    UINT windowX = CW_USEDEFAULT;
    UINT windowY = CW_USEDEFAULT;

    LPCWSTR wndCaption = L"Direct 3D 9 Application";
    DWORD wndStyle = WS_OVERLAPPED | WS_CAPTION | WS_VISIBLE | WS_SYSMENU;

    //create the window
    HWND hWnd = CreateWindowEx(
        0,                              // Optional window styles.
        wndClass,                     // Window class
        wndCaption,    // Window text
        wndStyle,            // Window style

        // Size and position
        windowX, windowY, windowWidth, windowHeight,

        nullptr,       // Parent window    
        nullptr,       // Menu
        hInst,  // Instance handle
        NULL        // Additional application data
    );

    if (hWnd == NULL)
    {
        MessageBox(hWnd, L"Failed to generate a valid main window.", L"Failure", MB_OK);
        return 0;
    }

    MSG msg = { };

    while (GetMessage(&msg, NULL, 0, 0) > 0)
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    while (1) {}
}