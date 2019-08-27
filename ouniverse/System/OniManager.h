//Copyright 2015-2019, All Rights Reserved.

/**

## Ini

**Class:**  IniC

Loads and saves ini documents from a path.

#### Features
* Can restore any value to default.
* Only writes altered values.
* Access values by exact type.

#### Additions
**Entry:**  Abstract Ini Entry.
**String:**  Entry extension which contains a StringC.
**Float:**  Entry extension which contains a float.
**Int:**  Entry extension which contains an int.
**Bool:**  Entry extension which contains a bool.

 */

#pragma once

#include "Interface/File.h"
#include "System/OniType.h"

class OniC;

class OUNIVERSE_API OniManagerC
{

public:

	OniManagerC();
	
	void Load(OniTypeC::Type InType, FileC InPath);

private:

	ArrayC<OniC*>Lib_;

};