//Copyright 2015-2019, All Rights Reserved.

/**
Simplified storage of X,Y Coordinates as integers.

UE4 has 2D Vector storage but it stores them as float.
I thought reimplementing this would be a little more efficient and faster.

Used mainly to store mouse coordinates, line traces, or hold the player location in the world streaming grid.
 */

#pragma once
#include "CoreTypes.h"

struct FInt2D
{
	int X;
	int Y;

public:

	/** Global 2D zero vector constant (0,0) */
	static CORE_API const FInt2D ZeroVector;

	/** Global 2D unit vector constant (1,1) */
	static CORE_API const FInt2D UnitVector;

	FORCEINLINE FInt2D();

	FORCEINLINE FInt2D(int InX, int InY);

};

FORCEINLINE FInt2D::FInt2D()
	: X(0), Y(0)
{ }


FORCEINLINE FInt2D::FInt2D(int InX, int InY)
	: X(InX), Y(InY)
{ }
