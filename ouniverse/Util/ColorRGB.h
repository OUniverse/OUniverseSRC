//Copyright 2015-2019, All Rights Reserved.

/**
Holds 3 8Bs to make an RGB color.
 */

#pragma once

#include "CoreMinimal.h"

struct ColorRGB
{
	uint8 R;
	uint8 G;
	uint8 B;

	ColorRGB(uint8 inR, uint8 inG, uint8 inB)
	{
		R = inR;
		G = inG;
		B = inB;
	}

	ColorRGB()
	{
		R = 255;
		G = 255;
		B = 255;
	}
};