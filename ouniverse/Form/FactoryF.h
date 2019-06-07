//Copyright 2015-2019, All Rights Reserved.

/**
Payload is the top level unpacked of the Atlas data system.
- Scans the Atlas Folder (Potentially multiple folders if needed)
- Creates Atlases
- Creates PreForms 
- Creates Forms and maintains them all in a map with a uint32 key.
	- Creates a factory vector with pointers to each form type's creation function.

 */

#pragma once

#include "Interface/Array.h"
#include "Interface/String.h"
