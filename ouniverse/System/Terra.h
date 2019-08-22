//Copyright 2015-2019, All Rights Reserved.

/**

## Terra

> **Singleton Service: Created once only by the boot process.**

A service singleton which handles worlds, universes, zones etc in an OOP style.

#### Tasks:
* Calculates the activities of citizens, the weather, and world events.
* Unpacks the form data for what objects should be placed in the 3D world.
* Does not spawn the 3D world itself but communicates with CosmosC to output the world.

**Creator:** UBoot
**Holder:** Major

 */


#pragma once

class BootC;

class OUNIVERSE_API TerraC
{
	friend BootC;

private:

	static TerraC* Create();

public:

	static TerraC* Get();
	TerraC();

};