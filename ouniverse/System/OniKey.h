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


class OUNIVERSE_API OniInternalC
{

public:

	static const int LAST_USER;
	static const int LAST_LOGIN;

};

class OUNIVERSE_API OniGlobalC
{

public:

	static const int AUTOLOGIN_SINGLE_USER;
	static const int AUTOLOGIN_LAST_USER;
	static const int SKIP_SPLASH_MOVIES;
};

class OUNIVERSE_API OniUserC
{

public:

	static const int LOADOUT_LAST;
	static const int LOADOUT_BYPASS;
	static const int LOADOUT_AUTOSELECT_SINGLE;
	static const int LOADOUT_AUTOSELECT_LAST;

};