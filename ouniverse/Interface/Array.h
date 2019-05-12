//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <vector>

template <typename T>
class ArrayC
{

public:

	void Init(int Amount, T Default)
	{		
		Vector.assign(Amount, Default);
	}

	void Add(T NewT)
	{
		Vector.push_back(NewT);
	}

	T& operator[] (int Index)
	{
		return Vector[Index];
	}

	void operator+=(T NewT)
	{
		return Vector.push_back(NewT);
	}

	std::vector <T> Vector;

};
