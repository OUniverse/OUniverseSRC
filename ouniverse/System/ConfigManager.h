//Copyright 2015-2019, All Rights Reserved.

/**
The ConfigManager is a Singleton extension to MAJOR and manages global user and game configuration settings.
Primarily it loads, unpacks, and resaves configuration files.
 */

#pragma once

#include "CoreMinimal.h"
#include <vector>

#define INI_NAME_GLOBAL "global.ini"
#define INI_NULLSTRING "$"
#define OINI_LAST_USER "lastUserID"
#define OINI_FIRST_RUN "bFirstRun"
#define OINI_SKIP_INTRO "bSkipIntro"
#define OINI_AUTOLOG_SINGLE_USER "bAutoLoginSingleUser"
#define OINI_AUTOLOG_LAST_USER "bAutoLoginLastUser"

#define UINI_LAST_PLAYTHROUGH "lastPlaythroughID"

class IniBeacon;

class OUNIVERSE_API ConfigManager
{

private:

	ConfigManager(FString ConfigIniPath, FString UserIniPath);

public:

	static ConfigManager* Create(FString ConfigIniPath, FString UserIniPath);

	enum IniTypes : uint8
	{
		Global,
		User,
	};

	std::vector <IniBeacon*> IniVector;

	IniBeacon* GetIni(IniTypes Type);

	FString GetAsString(IniTypes Type, FString Key);
	int GetAsInt(IniTypes Type, FString Key);
	float GetAsFloat(IniTypes Type, FString Key);
	bool GetAsBool(IniTypes Type, FString Key);


	void LoadUserINI(FString ActiveUserPath);

};
