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

#include "Interface/Map.h"
#include "System/DuetUID.h"
#include "Form/FormD.h"

class OUNIVERSE_API DatLibC
{

public:

	DatLibC();
	static DatLibC* Create();

private:

	MapC<DuetUID, FormD*> Lib_;
};
