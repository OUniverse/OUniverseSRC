//Copyright 2015-2019, All Rights Reserved.

/**

## Map

**Class:** MapC

Generic map implementation.
> Wrapper around a std::map

*/

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

		//ERROR HAPPENED
		return it->second;
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
	
	bool TryPointer(K Key, V*& Ref)
	{
		std::map<K, V>::iterator it;
		it = Map.find(Key);

		if (it != Map.end())
		{
			Ref = &it->second;
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

	void DeleteAndRemove(K Key)
	{
		delete Find(Key);
		Remove(Key);
	}

	void DeleteAndRemoveByIndex(int Index)
	{
		delete At(Index);

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

			Remove(it->first);
		}

	}

	void DeleteAndRemoveAll()
	{
		int l = Len();
		for (int i = 0; i < l; i++)
		{
			DeleteAndRemoveByIndex(i);
		}
	}

	void Clear()
	{
		Map.clear();
	}

	std::map <K,V> Map;

};