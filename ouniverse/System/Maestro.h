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
#include "Interface/String.h"

#include "System/Input.h"
#include "Maestro.generated.h"

class BootC;
class UMajor;
class UUi;

class UProtocol;
class UGlobalPro;
class UWorldPro;
class UWriterPro;

UCLASS()
class OUNIVERSE_API UMaestro : public UInputSchemaStack
{
	GENERATED_BODY()

public:

	UMaestro();
	static UMaestro* Create(UMajor* Major);
	void Init(UMajor* Major);

	void Start();
	void FauxStart();
	void WriterStart();

	UPROPERTY()
	UGlobalPro* Global_;
	UPROPERTY()
	UWorldPro* World_;
	UPROPERTY()
	UWriterPro* Writer_;

	UUi* Ui_;

public:

	//void Action(InputSchemaC::Command InAction, InputStrokeS InStroke);

	enum ProtocolUID
	{
		Global,
		Sym,
		OpenWorld,
		Writer,
		MAX,
	};
};