//Copyright 2015-2019, All Rights Reserved.

/**

## Data
> **Singleton Service: Created once only by the boot process.**

Data is a singleton which loads all the atlas style game data.

#### Tasks
* Creates and triggers a PayloadC which unpacks the entire atlas folder.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"

class UBoot;
class AtlasLibC;
class AtlasC;
struct FormPilotS;

class OUNIVERSE_API DataC
{
	friend UBoot;

private:

	static DataC* Create(StringC InPath);
	
	DataC(StringC InPath);
	
	StringC Path_;

	AtlasLibC* AtlasLib_;

public:

	static DataC* Get();
	DataC();

	AtlasLibC* GetAtlasLib();

	ArrayC<AtlasC*> GetAtlasPreArray();

	ArrayC<FormPilotS*> GetFormPilotList();
	
	//void Reset(LoadoutC* InLoadout);
	//void Evolve(CosmosC* InLoadout);
};
