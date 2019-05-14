//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include <functional>
#include "Interface/Array.h"



template<typename R>
class Event0C {

public:


	class Listener0C
	{
	public:

		Listener0C()
		{

		};

		R Fire()
		{
			return Delegate();
		};

		void Bind()
		{
			Event->Bind(this);
		}

		Event0C* Event;
		std::function<R()> Delegate;
	};

	template<class T>
	Listener0C* Create(T* const object, R(T::* const mf)())
	{
		Listener0C* NewListener = new Listener0C();
		NewListener->Event = this;
		NewListener->Delegate = std::bind(mf, object, std::placeholders::_1);
		return NewListener;
	};

	template<class T>
	Listener0C* Create(R(*const fun)())
	{
		Listener0C* NewListener = new Listener0C();
		NewListener->Delegate = fun;
		return NewListener;
	};

	void Bind(Listener0C* NewListener)
	{
		Listeners.emplace_back(NewListener);
	}

	void Trigger()
	{
		for (const auto& L : Listeners)
		{
			L->Fire();
		}
	};

	ArrayC<R> Gather()
	{
		ArrayC<R> Responses;

		for (const auto& L : Listeners)
		{
			Responses.Add(L->Fire());
		}

		return Responses;
	};

private:
	std::vector<Listener0C*> Listeners;
};


template<typename R, typename P1>
class Event1C {

public:


	class Listener1C
	{
	public:

		Listener1C()
		{

		};

		R Fire(P1 InP1)
		{
			return Delegate(InP1);
		};

		void Bind()
		{
			Event->Bind(this);
		}

		Event1C* Event;
		std::function<R(P1)> Delegate;
	};

	template<class T>
	Listener1C* Create(T* const object, R(T::* const mf)(P1))
	{
		Listener1C* NewListener = new Listener1C();
		NewListener->Event = this;
		NewListener->Delegate = std::bind(mf, object, std::placeholders::_1);
		return NewListener;
	};

	template<class T>
	Listener1C* Create(R(*const fun)(P1))
	{
		Listener1C* NewListener = new Listener1C();
		NewListener->Delegate = fun;
		return NewListener;
	};

	void Bind(Listener1C* NewListener)
	{
		Listeners.emplace_back(NewListener);
	}

	void Trigger(P1 InP1)
	{
		for (const auto& L : Listeners)
		{
			L->Fire(InP1);
		}
	};

	ArrayC<R> Gather(P1 InP1)
	{
		ArrayC<R> Responses;

		for (const auto& L : Listeners)
		{
			Responses.Add(L->Fire(InP1));
		}

		return Responses;
	};

private:
	std::vector<Listener1C*> Listeners;
};


template<typename R, typename P1, typename P2>
class Event2C {

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

		Event2C* Event;
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