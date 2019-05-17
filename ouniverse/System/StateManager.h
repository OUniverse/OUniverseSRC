//Copyright 2015-2019, All Rights Reserved.

/**

## StateManager

> **Singleton Service: Created once only by the boot process.**

A service singleton that handle the logic of different modes the game can be in.

An example of different states would be the System Menu compared to Open World. The usage in either state is significantly different from each other.

#### Tasks
* Loads the State subclasses like a cartridge to run which change the logic.
* Handles the loading and unloading of States.
* Synchronizes a change in States by ensuring an old one is unloaded before loading in a new one.

**Creator:** UBoot
**Holder:** Major
 
 */

#pragma once

#include <vector>

class State;
class UBoot;

class OUNIVERSE_API StateManager
{

	friend UBoot;

private:

	static StateManager* Create();
	StateManager();

public:

	enum Types
	{
		SystemMenu,
		Creation,
		MAX,
	};

	State* Activate(Types Type);

private:

	State* GetState(Types Type);

	std::vector <State*> StateVector;

};