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


class OUNIVERSE_API OniCategoryC
{

public:

	class Internal
	{
	public:
		static const int All;
	};

	class Global
	{
	public:
		static const int Boot;
	};

	class User
	{
	public:
		static const int General;
		static const int Graphics;
		static const int Audio;
		static const int Controls;
		static const int Keybinds;
	};

};