//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <functional>
#include <vector>

template<typename P1, typename P2>
class EventC {

public:

	template<class T> 
	void Listen(T* const object, void(T::* const mf)(P1, P2))
	{
		Listeners.emplace_back(std::bind(mf, object, std::placeholders::_1, std::placeholders::_2));
	}

	void Listen(void(*const fun)(P1, P2))
	{
		Listeners.emplace_back(fun);
	}

	void Trigger(P1 firstval, P2 secondval)
	{
		for (const auto& L : Listeners)
		{
			L(firstval, secondval);
		}
	}

private:
	std::vector<std::function<void(P1, P2)>> Listeners;
};