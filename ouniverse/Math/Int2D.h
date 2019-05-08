//Copyright 2015-2019, All Rights Reserved.

/**
Simple storage of X,Y Coordinates as integers.
 */

#pragma once
#include "CoreTypes.h"

struct FInt2D
{
	int X;
	int Y;

public:

	/** Global 2D zero vector constant (0,0) */
	static OUNIVERSE_API const FInt2D ZeroVector;

	/** Global 2D unit vector constant (1,1) */
	static OUNIVERSE_API const FInt2D UnitVector;

	FORCEINLINE FInt2D();

	FORCEINLINE FInt2D(int InX, int InY);

};

FORCEINLINE FInt2D::FInt2D()
	: X(0), Y(0)
{ }


FORCEINLINE FInt2D::FInt2D(int InX, int InY)
	: X(InX), Y(InY)
{ }
