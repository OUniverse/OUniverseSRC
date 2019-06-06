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

class UBoot;
class PayloadC;
class LoadoutC;

class OUNIVERSE_API DataC
{
	friend UBoot;

private:

	static DataC* Create(StringC InPath);
	
	DataC(StringC InPath);
	
	PayloadC* Payload_;

	StringC Path_;

public:

	static DataC* Get();
	DataC();

	void ResetPayload(LoadoutC* InLoadout);
};
