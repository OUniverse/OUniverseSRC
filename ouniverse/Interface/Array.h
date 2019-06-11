//Copyright 2015-2019, All Rights Reserved.

/**

## Array

**Class:** ArrayC

Generic array implementation.
> Wrapper around a std::vector

*/

#pragma once

#include <vector>

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"

template <typename T>
class ArrayC
{

public:

	void Init(int Amount, T Default)
	{		
		Vector_.assign(Amount, Default);
	}

	void Add(T NewT)
	{
		Vector_.push_back(NewT);
	}

	T& operator[] (int Index)
	{
		return Vector_[Index];
	}

	void operator+=(T NewT)
	{
		return Vector_.push_back(NewT);
	}

	int Len()
	{
		return Vector_.size();
	}

	std::vector <T> Vector()
	{
		return Vector_;
	}

	std::vector <T> Vector_;

};