//Copyright 2015-2019, All Rights Reserved.

/**

## HashMap

**Class:**  HashMapC

Not yet implemented, will be a wrapper around a std::unordered_map.

*/

#pragma once

#include <unordered_map>

template <typename K, typename V>
class HashMapC
{

public:


	void Add(K NewK, V NewV)
	{
		Map.insert({ NewK , NewV });
	}

	V& Find(K Key)
	{
		std::unordered_map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			return it->second;
		}
	}

	bool Try(K Key, V& Ref)
	{
		std::unordered_map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			Ref = it->second;
			return true;
		}

		return false;
	}

	void Remove(K Key)
	{
		Map.erase(Key);
	}

	bool Contains(K Key)
	{
		std::unordered_map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			return true;
		}

		return false;
	}

	V& operator[](K Key)
	{
		std::unordered_map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			return it->second;
		}

		throw("Error");
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
			std::unordered_map<K, V>::iterator it = Map.begin();
			int i = 0;
			while (i < Index)
			{
				++it;
				i++;
			}

			return it->second;
		}

		std::unordered_map<K, V>::iterator it = Map.end();

		return it->second;
	}

	std::unordered_map <K, V> Map;

};
