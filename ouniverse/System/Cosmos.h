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

class BootC;

class OUNIVERSE_API CosmosC
{

	friend BootC;

public:

	static CosmosC* Create();

	static CosmosC* Get();

	CosmosC();

	void NewLevel();

	void Mount();
	void FauxMount();
	void Dismount();

	void NewLevelLoaded();

	void SpawnParty();
};