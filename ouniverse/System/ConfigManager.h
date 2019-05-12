//Copyright 2015-2019, All Rights Reserved.

/**
The ConfigManager is a Singleton extension to MAJOR and manages global user and game configuration settings.
Primarily it loads, unpacks, and resaves configuration files.
 */

#pragma once

#include "CoreMinimal.h"
#include "Interface/String.h"
#include "Interface/Array.h"

#define INI_NAME_GLOBAL "global.ini"
#define INI_NULLSTRING "$"


struct IniS;
struct DirS;

namespace IniKey
{
	namespace Global
	{
		namespace Bool
		{
			enum Entry
			{
				FirstRun,
				SkipIntro,
				LoginSingleUser,
				LoginLastUser,
				MAX,
			};
		}

		namespace Int
		{
			enum Entry
			{
				MAX,
			};
		}

		namespace Float
		{
			enum Entry
			{
				MAX,
			};
		}

		namespace String
		{
			enum Entry
			{
				LastUser,
				MAX,
			};
		}
	}

	namespace User
	{
		namespace Bool
		{
			enum Entry
			{
				MAX,
			};
		}

		namespace Int
		{
			enum Entry
			{
				MAX,
			};
		}

		namespace Float
		{
			enum Entry
			{
				MAX,
			};
		}

		namespace String
		{
			enum Entry
			{
				LastPlaythrough,
				MAX,
			};
		}
	}

}

class OUNIVERSE_API ConfigManager
{

private:

	ConfigManager(DirS* ConfigIniDirPTR, DirS* UserIniDirPTR);

public:

	enum IniTypes : uint8
	{
		Global,
		User,
		MAX,
	};

	static ConfigManager* Create(DirS* ConfigIniDirPTR, DirS* UserIniDirPTR);



	ArrayC<IniS*> IniVector;

	IniS* GetIni(IniTypes Type);

	StringC GetString(IniTypes Type, int Key);
	int GetInt(IniTypes Type, int Key);
	float GetFloat(IniTypes Type, int Key);
	bool GetBool(IniTypes Type, int Key);


	void LoadUserINI();

};
