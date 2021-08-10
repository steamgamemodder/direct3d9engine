#pragma once
#include "renderprimitives.h"

class meshtypes 
{
	struct UNTEXTURED_MESH_XYZ_RHW
	{
		VERTEX_XYZRHW vertices[];
	};

	struct UNTEXTURED_MESH_XYZ
	{
		VERTEX_XYZ vertices[];
	};
};