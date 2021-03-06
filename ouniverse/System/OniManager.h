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

#include "Interface/Url.h"
#include "System/OniType.h"

class OniC;

class OUNIVERSE_API OniManagerC
{

public:

	OniManagerC();
	
	void Load(OniTypeC::Type InType, FileC InPath);

	bool GetBool(OniTypeC::Type InType, int OniKey);

	int GetInt(OniTypeC::Type InType, int OniKey);

	StringC GetString(OniTypeC::Type InType, int OniKey);

	float GetFloat(OniTypeC::Type InType, int OniKey);

	StringC GetSerializedCategory(OniTypeC::Type InType, int InCategory);

private:

	ArrayC<OniC*>Lib_;

};