//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <functional>
#include <vector>
#include <typeinfo>


#include "Interface/Array.h"

#include "Min/DebugM.h"


struct Void {};

template<typename R, typename P1, typename P2>
class EventC {

public:


	class Listener2C
	{
	public:

		Listener2C()
		{

		};

		R Fire(P1 InP1, P2 InP2)
		{
			return Delegate(InP1, InP2);
		};

		void Bind()
		{
			Event->Bind(this);
		}

		EventC* Event;
		std::function<R(P1, P2)> Delegate;
	};

	template<class T>
	Listener2C* Create(T* const object, R(T::* const mf)(P1, P2))
	{
		Listener2C* NewListener = new Listener2C();
		NewListener->Event = this;
		NewListener->Delegate = std::bind(mf, object, std::placeholders::_1, std::placeholders::_2);
		return NewListener;
	};

	template<class T>
	Listener2C* Create(R(*const fun)(P1, P2))
	{
		Listener2C* NewListener = new Listener2C();
		NewListener->Delegate = fun;
		return NewListener;
	};

	void Bind(Listener2C* NewListener)
	{
		Listeners.emplace_back(NewListener);
	}

	void Trigger(P1 InP1, P2 InP2)
	{
		for (const auto& L : Listeners)
		{
			L->Fire(InP1, InP2);
		}
	};


	ArrayC<R> Gather(P1 InP1, P2 InP2)
	{
		ArrayC<R> Responses;

		for (const auto& L : Listeners)
		{			
			Responses.Add(L->Fire(InP1, InP2));
		}

		return Responses;
	};

private:
	std::vector<Listener2C*> Listeners;
};