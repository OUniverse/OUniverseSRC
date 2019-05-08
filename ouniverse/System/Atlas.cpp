//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas.h"
#include "System/DataManager.h"
#include "Data/DataFactory.h"
#include "Data/DataDefines.h"
#include "Data/Data.h"
#include "System/LogMinimal.h"
#include "System/Major.h"

UAtlas::UAtlas()
{

}

bool UAtlas::IsViable()
{
	return true;
}

void UAtlas::Datify(TSharedPtr<FJsonObject> InDatra)
{
	Datra = InDatra;
}

void UAtlas::Scan(FDataScribe Scribe)
{
	

	TArray<FString> FolderFiles;
	FString Path = Scribe.Directory + Id + "/" + FString("*");
	IFileManager& FileManager = IFileManager::Get();
	FileManager.FindFiles(FolderFiles, *Path, true, false);

	int16 Count = FolderFiles.Num();

	Scribe.DataManager->Major->Log(LDATA,1,"Atlas.cpp | UAtlas::Scan | Scanning AtlasFolder for documents: " + Id);
	Scribe.DataManager->Major->Log(LDATA,1,"	Path: " + Path);
	Scribe.DataManager->Major->Log(LDATA,1,"	Found#: " + FString::FromInt(Count));

	for (int i = 0; i < Count; i++)
	{
		Scribe.DataManager->Major->Log(LDATA,1,"		#"+FString::FromInt(i)+": "+FolderFiles[i]);

		if (FPaths::GetExtension(FolderFiles[i], true) == EXT_POD)
		{
			Scribe.DataManager->Major->Log(LDATA, 1, "			Extension Accepted: " + FString(EXT_POD));
			PodPaths.Emplace(FolderFiles[i]);
		}
	}

}

void UAtlas::Unpack(FDataScribe Scribe)
{
	int16 Count = PodPaths.Num();
	FString RawDataString;
	TSharedPtr<FJsonObject> RawData;
	FString Path = Scribe.Directory + Id + "/";
	Scribe.DataManager->Major->Log(LDATA, 1, "Atlas.cpp | UAtlas::Unpack | Unpacking Atlasi");
	Scribe.DataManager->Major->Log(LDATA, 1, "	id: "+Id);
	Scribe.DataManager->Major->Log(LDATA, 1, "	Pod Count: " + FString::FromInt(Count));

	for (int i = 0; i < Count; i++)
	{
		
		FString FilePath = Path + PodPaths[i];
		Scribe.DataManager->Major->Log(LDATA, 1, "		Pod: #"+FString::FromInt(Count)+" file name: "+PodPaths[i]);

		FFileHelper::LoadFileToString(RawDataString, *FilePath);

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(RawDataString);
		if (FJsonSerializer::Deserialize(JsonReader, RawData))
		{
			Scribe.DataManager->Major->Log(LDATA, 1, "		JsonData is valid");
			UnpackPod(RawData, Scribe);
		}
	}
}

void UAtlas::UnpackPod(TSharedPtr<FJsonObject> PodData, FDataScribe Scribe)
{
	const TArray<TSharedPtr<FJsonValue>> *ArrDatri;
	PodData->TryGetArrayField(PODFIELD_DATA, ArrDatri);
	auto Datri = *ArrDatri;

	int Count = Datri.Num();
	for (int i = 0; i < Count; i++)
	{
		Scribe.DataManager->Major->Log(LDATA, 1, Datri[i]->AsObject()->GetStringField(PODFIELD_ID));
		int DataTypeIndex = Datri[i]->AsObject()->GetIntegerField(PODFIELD_DATATYPE);
		Scribe.DataManager->Major->Log(LDATA, 1, FString::FromInt(DataTypeIndex));
		Data* NewData = Scribe.DataManager->DataType[DataTypeIndex]->Create();
		NewData->Datify(Datri[i]->AsObject());
		Scribe.DataManager->AddData(NewData);
	}
	
	//insert(pair <FName, Data>(FName(*TheString), NewData));
}

