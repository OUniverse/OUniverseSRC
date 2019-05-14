//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <unordered_map>

template <typename T>
class GeminiC
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
