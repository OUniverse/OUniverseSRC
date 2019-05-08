//Copyright 2015-2019, All Rights Reserved.

/**
ConfigBeacons assist in managing OUniverse's .ini config files (.oni).
It stacks a list of OniFlex objects in a map which link a key to a default and optional override.
It can print out the oni document so the user can update changes.
 */

#pragma once

#include "CoreMinimal.h"
#include <map>

struct IniFlex
{
public:
	FString Flex;
	FString Default;

	IniFlex(FString InDefault);

	FString Get();

	void SetFlex(FString InFlex);

	void Reset();
};


class OUNIVERSE_API IniBeacon
{

public:

	IniBeacon();

	FString IniPath;

	std::map <FName,IniFlex*> Map;

	void ParseIni();

	void SetPath(FString Path);

	void Add(FString Key, FString Default, bool IsTemplate);

	void Set(FString Key, FString Val);

	FString GetAsString(FString Key);
	int GetAsInt(FString Key);
	float GetAsFloat(FString Key);
	bool GetAsBool(FString Key);

	void SaveIni();
	void SaveIniTemplate();
	void SetAndSave(FString Key,FString Val, bool bSave);

	void Reset();
};

