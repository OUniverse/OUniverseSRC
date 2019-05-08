//Copyright 2015-2019, All Rights Reserved.

#include "System/User.h"
#include "Util/JsonWriter.h"
//#include "System/DebugMinimal.h"

User::User() 
{

}

bool User::IsViable()
{
	return true;
}

bool User::DeJson(TSharedPtr<FJsonObject> JData)
{

	TSharedPtr<FJsonObject> JObj;

	TSharedPtr<FJsonObject> FocusedData;
	if (!JData->HasField("global"))
		return false;
		
		JObj = JData->GetObjectField("global");
		VersionI = JObj->GetNumberField("vi");
		VersionW = JObj->GetNumberField("vw");


	if (!JData->HasField("pilot"))
		return false;
		
		JObj = JData->GetObjectField("pilot");
		Name = JObj->GetStringField("name");
		Glyph = JObj->GetStringField("glyph");

	if (!JData->HasField("achievement"))
			return false;

	int ArrCount;

	auto JAchieves = JData->GetArrayField("achievements");	 
	ArrCount = JAchieves.Num();

	for (int i = 0; i < ArrCount; i++)
	{
		Achievements.Push(JAchieves[i]->AsNumber());
	}

	if (!JData->HasField("record"))
		return false;
	auto JRecords = JData->GetArrayField("record");
	ArrCount = JRecords.Num();

	for (int i = 0; i < ArrCount; i++)
	{
		int32 Value;
		JRecords[i]->TryGetNumber(Value);
		Records.Push(Value);
	}

	if (!JData->HasField("playthrough"))
		return false;
	auto JPlaythroughs = JData->GetArrayField("playthrough");
	ArrCount = JPlaythroughs.Num();

	for (int i = 0; i < ArrCount; i++)
	{
		FPlaythroughPilot NewPlaythrough = FPlaythroughPilot();
		JObj = JPlaythroughs[i]->AsObject();
		NewPlaythrough.ID = JObj->GetStringField("id");
		NewPlaythrough.Glyph = JObj->GetStringField("glyph");

			auto Flags = JObj->GetArrayField("flag");
			int FlagsCount = Flags.Num();
			for (int j = 0; j < FlagsCount; j++)
			{
				NewPlaythrough.Flags.Push(Flags[j]->AsNumber());
			}
	}

	if (!JData->HasField("mod"))
		return false;
	auto JModProfiles = JData->GetArrayField("mod");
	ArrCount = JPlaythroughs.Num();

	for (int i = 0; i < ArrCount; i++)
	{
		FModProfile NewModProfile = FModProfile();
		JObj = JModProfiles[i]->AsObject();
		NewModProfile.ID = JObj->GetStringField("id");
		NewModProfile.Glyph = JObj->GetStringField("glyph");

		auto AtlasID = JObj->GetArrayField("atlas");
		int AtlasCount = AtlasID.Num();

		for (int j = 0; j < AtlasCount; j++)
		{
			NewModProfile.AtlasID.Push(AtlasID[j]->AsString());
		}
	}

		//DEBUGPRINT(FColor::Turquoise, Name);
		//DEBUGPRINT(FColor::Turquoise, Glyph);

		return true;
}

FString User::ToJson()
{
	FJsonWriter J = FJsonWriter();
	J.BaseObject();
	J.Object("global");
	J.Add("vi", 1);
	J.Add("vw", 10);
	J.EndObject();
	J.Object("pilot");
	J.Add("name", Name);
	J.Add("glyph", Glyph);
	J.EndObject();

	J.EndObject();
	return J.Print();
}