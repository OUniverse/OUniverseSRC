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



class OUNIVERSE_API OniTypeC
{

public:

	static enum Type {
		Internal,
		Global,
		User,
		Scribe,
		TYPE_MAX,
	};
};