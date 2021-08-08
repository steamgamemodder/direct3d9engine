#include <windows.h>
#include "winmain.h"
#include "winmsghandler.h"
#include "windowcreationhandler.h"

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hInstPrev, PSTR cmdline, int cmdshow)//win32 main function
{
    WNDCLASS wc = { };

    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInst;
    wc.lpszClassName = wndClass;
    RegisterClass(&wc);

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
    while (1) {};
}