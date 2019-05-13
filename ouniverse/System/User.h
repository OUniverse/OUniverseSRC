//Copyright 2015-2019, All Rights Reserved.

/**
A User represents the person that is playing. 

OUniverse supports multiple for the following situations:
- Multiple people playing on the same game.
- Multiple playthroughs and experimentation.

The USER class is created by the UserManager after it parses the User Directory and pulls dated documents.
Each user found is given a USER object.

- Unpacks JSON data and fills out a few special variables.
- Validates itself.
- Allows for editing and saving.

 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Json.h"
#include "User.generated.h"



USTRUCT()
struct FPlaythroughPilot
{
	GENERATED_BODY()

	UPROPERTY()
	FString ID;

	UPROPERTY()
	FString Glyph;

	UPROPERTY()
	TArray<int> Flags;

	FPlaythroughPilot()
	{

	}
};

USTRUCT()
struct FModProfile
{
	GENERATED_BODY()

	UPROPERTY()
	FString ID;

	UPROPERTY()
	FString Glyph;

	UPROPERTY()
	TArray<FString> AtlasID;

	FModProfile()
	{

	}
};

class OUNIVERSE_API UserC
{

public:	    
		UserC();	
		
		static UserC* Create();

		int VersionI;
		int VersionW;
		FString ID;
		int SN;

		FString Name;
		FString Glyph;

		TArray<int16> Achievements;
		TArray<int32> Records;

		int AchievementScore;
		bool IsViable();

		bool DeJson(TSharedPtr<FJsonObject> JData);
		FString ToJson();	
};