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

#include "Interface/Array.h"
#include "System/InputSchema.h"

class BootC;
class MajorC;

class ProtocolP;

class GlobalP;
class SymP;
class OpenWorldP;

class OUNIVERSE_API MaestroC
{

	friend BootC;

private:


	static MaestroC* Create(MajorC* Major);
	MaestroC(MajorC* Major);

	void Start();

public:

	enum ProtocolUID
	{
		Global,
		Sym,
		OpenWorld,
		Scribe,
		MAX,
	};


private:

	GlobalP*		GlobalP_;
	SymP*			SymP_;
	OpenWorldP*		OpenWorldP_;

	int InputStackLen_;
	ArrayC<ProtocolP*> InputStack_;

public:

	InputReplyS OnCommand(InputSchemaC::Commands Command, bool UpDown, bool PostUI);

};