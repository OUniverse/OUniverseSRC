//Copyright 2015-2019, All Rights Reserved.

#include "DataManager.h"
#include "System/Major.h"
#include "System/Atlas.h"
#include "Data/Data.h"
#include "Data/DataFactory.h"



UDataManager::UDataManager()
{
	AtlasDirectory = FPaths::ProjectContentDir() + "Atlas/";

#define DT_DATA			0
#define DT_REF			1
#define DT_ACTRA		2
#define DT_AREA			3

	DataType[DT_DATA]	=	new F_Data();
	DataType[DT_REF]	=	new F_Ref();
	DataType[DT_ACTRA]	=	new F_Actra();
	DataType[DT_AREA]	=	new F_Area();
}



void UDataManager::Init(UMajor* inMajor)
{
	Major = inMajor;
	LOG(LBOOT,1,"DataManager: On");
}


void UDataManager::AddData(Data* InData)
{
	DataMap[InData->ID.GetNumber()] = InData; 	
}

Data* UDataManager::GetData(FName DataID)
{
	return DataMap[DataID.GetNumber()];
}

void UDataManager::ScanAtlasi(EAtlasFolder folder)
{
	TArray<FString> FolderArr;
	FString Path = AtlasDirectory + FString("*");

	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(FolderArr, *Path, false, true);

	int32 Count = FolderArr.Num();
	TArray<UAtlas*>PreAtlasi;
	UAtlas* CurrentAtlas;

	LOG(LDATA,1,"DataManager.cpp | UDataManager::ScanAtlasi | Scanning for atlas folders: " + AtlasDirectory);
	LOG(LDATA,1,"- Found " + FString::FromInt(Count) + " potential atlas folders.");
	for (int i = 0; i < Count; i++)
	{
		FString Id = FolderArr[i];
		TSharedPtr<FJsonObject> RawData;
		FString RawDataString;
		
		FString FilePath = AtlasDirectory + Id + "/" + Id + EXT_ATLAS;

		LOG(LDATA,1,"- Checking: " + FilePath);

		FFileHelper::LoadFileToString(RawDataString, *FilePath);

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(RawDataString);
		if (FJsonSerializer::Deserialize(JsonReader, RawData))
		{
			LOG(LDATA,1,"- Folder passes validation 1.");
			CurrentAtlas = NewObject<UAtlas>();
			CurrentAtlas->Id = Id;
			CurrentAtlas->Datify(RawData);
			PreAtlasi.Emplace(CurrentAtlas);

		}
	}

	Count = PreAtlasi.Num();

	for (int i = 0; i < Count; i++)
	{

		if (PreAtlasi[i]->IsViable())
		{
			LOG(LDATA,1,"Viable Atlas");
			GlobalAtlasi.Emplace(PreAtlasi[i]);
		}
	}
}


void UDataManager::LoadData()
{
	FDataScribe Scribe = FDataScribe();
	Scribe.Directory = AtlasDirectory;
	Scribe.DataManager = this;

	Atlasi.Append(GlobalAtlasi);
	Atlasi.Append(UserAtlasi);

	int32 Count = Atlasi.Num();

	LOG(LDATA, 1,"UDataManager.cpp | UDataManager::LoadData | Begin Massive Load. Total Atlases: "+ FString::FromInt(Count));


	for (int i = 0; i < Count; i++)
	{
		Atlasi[i]->Scan(Scribe);
		Atlasi[i]->Unpack(Scribe);
	}

	for (std::pair<int,Data*> element : DataMap)
	{
		element.second->Bloom();
	}

	for (std::pair<int, Data*> element : DataMap)
	{
		element.second->Link();
	}
}