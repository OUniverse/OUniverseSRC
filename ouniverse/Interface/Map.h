//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <map>

template <typename K, typename V>
class MapC
{

public:


	void Add(K NewK, V NewV)
	{
		Map.insert({ NewK , NewV });
	}

	V& Find (K Key)
	{
		std::map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			return it->second;
		}		
	}

	bool Try(K Key, V& Ref)
	{
		std::map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			Ref = it->second;
			return true;
		}

		return false;
	}
	
	bool Contains(K Key)
	{
		std::map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			return true;
		}

		return false;
	}

	V& operator[](K Key)
	{
		std::map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			return it->second;
		}
	}

	int Len()
	{
		return Map.size();
	}

	bool IsEmpty()
	{
		return Map.empty();
	}

	V& At(int Index)
	{
		int L = Len();
		if (Index < L)
		{
			std::map<K, V>::iterator it = Map.begin();
			int i = 0;
			while (i < Index)
			{
				++it;
				i++;
			}

			return it->second;
		}

		std::map<K, V>::iterator it = Map.end();

		return it->second;
	}

	std::map <K,V> Map;

};
