//Copyright 2015-2019, All Rights Reserved.

/**
ProtocolManager is a Singleton extension to MAJOR (GameInstance) and handles different modes the game can be in.
For example the login or title screen requires different logic compared to playing the game.
Protocols serves as the base logic and drive for different modes the game can be in.

- Handles the load/unload of Protocols.
- Synchronizes a change in Protocols by ensuring an old one is unloaded before loading in a new one.
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