#pragma once

LPCWSTR wndCaption = L"Direct 3D 9 Application";
LPCWSTR wndClass = L"d3d9app";

const UINT windowWidth = 640;
const UINT windowHeight = 480;

UINT windowX = CW_USEDEFAULT;
UINT windowY = CW_USEDEFAULT;

long wndStyle = WS_OVERLAPPED | WS_CAPTION | WS_VISIBLE | WS_SYSMENU;