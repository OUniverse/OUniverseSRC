//Copyright 2015-2019, All Rights Reserved.

/**

## Cosmos
> **Singleton Service: Created once only by the boot process.**

Cosmos is a singleton service that acts like a 3D space bucket. All 3D space objects are loaded into and by the Cosmos.

#### Tasks
* Handles loading and unloading levels smoothly.
* Loads world style levels
* Loads effect style levels such as 3D effects used by menus.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Interface/String.h"

class BootC;
class USpaceUE;

class ACharacterUE;

class EtherC 
{
	friend BootC;

public:

	static EtherC* Create(UObject* InWorldContext,UWorld* InScope);

	static EtherC* Get();
	EtherC(UObject* InWorldContext, UWorld* InScope);
	EtherC() {};
	void StreamLevel(StringC InLevelID);

	void OnLevelStreamed();

	ACharacterUE* Spawn();

private:

	USpaceUE* Space_;
};