#pragma once
#include <IntSafe.h> //header for DWORD

#define VERTEX_XYZ_FVF (D3DFVF_XYZ | D3DFVF_DIFFUSE)
#define VERTEX_XYZRHW_FVF (D3DFVF_XYZRHW | D3DFVF_DIFFUSE)

struct VERTEX_XYZ
{
	float x;
	float y;
	float z;
	DWORD color_32;
};

struct VERTEX_XYZRHW
{
	float x;
	float y;
	float z;
	float rhw;
	DWORD color_32;
};