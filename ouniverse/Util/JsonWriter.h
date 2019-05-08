//Copyright 2015-2019, All Rights Reserved.

#include "CoreMinimal.h"
#include "JsonWriter.generated.h"

USTRUCT()
struct FJsonWriter
{
	GENERATED_BODY()

	FString J;

	int Obj;
	int Arr;

	FJsonWriter()
	{
		J = "";
		Obj = 0;
		Arr = 0;
	}

	void Add(FString Key, int Val);
	void Add(FString Key, FString Val);
	void BaseObject();
	void Object(FString Key);
	void EndObject();
	void BaseArray();
	void Array(FString Key);
	void EndArray();

	FString Print();
};