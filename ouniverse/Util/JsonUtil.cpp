//Copyright 2015-2019, All Rights Reserved.

#include "JsonUtil.h"
#include "json.h"


FString JsonUtil::SerializeJson(TSharedPtr<FJsonObject> Json)
{
		FString OutputString;
		TSharedRef< TJsonWriter<> > Writer = TJsonWriterFactory<>::Create(&OutputString);
		FJsonSerializer::Serialize(Json.ToSharedRef(), Writer);
		return OutputString;
}