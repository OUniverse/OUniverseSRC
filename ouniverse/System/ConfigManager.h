//Copyright 2015-2019, All Rights Reserved.

/**

## ConfigManager

> **Singleton Service: Created once only by the boot process.**

A service singleton which loads the configuration ini files at boot and stores them for use throughout the lifetime.

**Additionals:**
**IniKey:** Namespace control over an enum system for each possible ini entry.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"

#define INI_NULLSTRING "$NULL"

class OniManagerC;
class BootC;

class OUNIVERSE_API ConfigManager
{
	friend BootC;

private:

	ConfigManager(OniManagerC* InOni);

public:


	OniManagerC* Oni_;
};
