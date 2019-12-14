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

#include "System/Input.h"
#include "Protocol/Protocol.h"
#include "Interface/Map.h"
#include "Interface/String.h"


class BootC;
class UMajor;
class UUi;

class ConsoleNewPro;
class ProtocolC;
class SystemPro;
class GlobalPro;
class WorldPro;
class WriterPro;

class InputC;

class OUNIVERSE_API MaestroC : public InputStackC, public ProtocolC
{


public:

	MaestroC();
	static MaestroC* Create();

	void Initialize(UMajor* InMajor);

	void Start();


public:

	void ProSystem();
	void ProWriter();

public:

	ConsoleNewPro* Console_;
	SystemPro* System_;
	GlobalPro* Global_;
	WorldPro* World_;
	WriterPro* Writer_;

private:


	UUi* Ui_;

};