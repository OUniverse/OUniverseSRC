//Copyright 2015-2019, All Rights Reserved.

/**

## SaveFolder

A Save Folder is a marshalling of the results of scanning a folder in the Save directory.

**Creator:** SaveLib
**Holder:** SaveLib

 */

#pragma once

#include "Interface/Event.h"

class SaveC;

class OUNIVERSE_API SaveDaisC
{

public:

	SaveDaisC();

	void Set(SaveC* InSave);

	SaveC* Get();
	
	Event1C<EventLife,SaveC*> E_Set;

private:

	SaveC* Save_;
};