//Copyright 2015-2019, All Rights Reserved.

/**
An Atlas is OUniverse's version of a standard Mod/Plugin.
Each Atlas is a folder directory which holds JSON data documents
Atlasi can contain a number of data documents so they are represented by a directory folder to contain multiple docs.

Atlas Class Abilities;
-Check if an Atlas is valid..
-Check if an Atlas is formated correctly.
-Do an abbreviated scan on the contents on the directory.
	(This prevents having to load the database of mods the player has not activated)
- Unpack the interiors of the folder.
 */

#pragma once

#include "CoreMinimal.h"
#include "Object.h"
#include "Json.h"
#include "Atlas.generated.h"

struct FDataScribe;

UCLASS(BlueprintType)
class OUNIVERSE_API UAtlas : public UObject
{

	GENERATED_BODY()

public:

	UAtlas();

	UPROPERTY(BlueprintReadWrite)
	FString Id;
	UPROPERTY()
	TArray<FString> PodPaths;

	TSharedPtr<FJsonObject> Datra;
	bool IsViable();
	void Datify(TSharedPtr<FJsonObject> InDatra);
	void Scan(FDataScribe Scribe);
	void Unpack(FDataScribe Scribe);

	void UnpackPod(TSharedPtr<FJsonObject> PodData, FDataScribe Scribe);
	

};
