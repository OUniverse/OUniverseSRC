//Copyright 2015-2019, All Rights Reserved.

/**

## Dat

**Class:**  DatC

A commonly used pairing of int + int as a dual map key representing the Atlas ID + Form ID.
This was converted to an interface due to it's core functionality in OUniverse's Data/Atlas strategy.

*/

#pragma once

#include <unordered_map>

#include "Interface/Int.h"
#include "Interface/String.h"

struct DuoS
{


	DuoS(int InA, int InB)
	{
		Atlas_ = InA;
		Form_ = InB;
	}

	DuoS(StringC InString)
	{
		ArrayC<StringC> Arr = InString.Split('.');
		Arr[0].BeInt(Atlas_);
		Arr[1].BeInt(Form_);
	}

	U32 Atlas()
	{
		return Atlas_;
	}

	U32 Form()
	{
		return Form_;
	}

private:

	U32 Atlas_;
	U32 Form_;

};


template <typename T>
class DuoMapC
{

public:


	int Alpha(int InAlpha)
	{
		std::unordered_map<int, std::unordered_map<int, T>>::const_iterator it = Gemini.find(InAlpha);
		if (it == Dat.end())
		{
			std::unordered_map<int, T> BetaMap;
			Gemini.insert({ InAlpha, BetaMap });
		}
	}

	int Add(int Alpha , int Beta, T Val)
	{
		Gemini.at(Alpha).at(Beta) = Val;
	}

	T Get(int Alpha, int Beta)
	{
		return Gemini.at(Alpha).at(Beta);
	}

	std::unordered_map<int, std::unordered_map<int,T>> Gemini;

};
