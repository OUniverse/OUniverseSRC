//Copyright 2015-2019, All Rights Reserved.

/**
The DataManager is a singleton extension to MAJOR that manages data which is used to propogate the gameworld.

During the bootup process multiple ATLAS folders containing JSON data documents are loaded and parsed.
The documents are converted into data object classes that can be directly accessed by the game.

-Scans data folders.
-Guides the data unpacking process.
-Serves data requests.
-Validates data.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include <unordered_map>
#include "DataManager.generated.h"


#define EXT_ATLAS ".atlas"
#define EXT_POD ".pod"

using namespace std;

class UAtlas;
class UMajor;
class UDataManager;
class Data;
class DataFactory;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EAtlasFolder : uint8
{
	Global						UMETA(DisplayName = "MyDocuments")
};

USTRUCT()
struct FDataScribe
{
	GENERATED_BODY()

	UPROPERTY()
	FString Directory;
	UPROPERTY()
	UDataManager* DataManager;

	FDataScribe()
	{

	}
};


UCLASS()
class OUNIVERSE_API UDataManager : public UObject
{
	GENERATED_BODY()
	
public:
	
	UDataManager();
	void Init(UMajor* inMajor);

	FString AtlasDirectory;

	UPROPERTY()
	UMajor* Major;

	DataFactory* DataType[255];

	UPROPERTY()
	TArray<UAtlas*> GlobalAtlasi;
	UPROPERTY()
	TArray<UAtlas*> UserAtlasi;
	UPROPERTY(BlueprintReadWrite)
	TArray<UAtlas*> Atlasi;


	std::unordered_map <int, Data*> DataMap;

	void ScanAtlasi(EAtlasFolder Folder);

	void LoadData();
	void AddData(Data* InData);
	Data* GetData(FName Id);	
	
};

