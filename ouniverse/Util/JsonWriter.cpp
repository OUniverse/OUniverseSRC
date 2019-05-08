//Copyright 2015-2019, All Rights Reserved.

#include "Util/JsonWriter.h"



void FJsonWriter::Add(FString Key, int Val)
{
	J+=(TEXT("\"")+Key+TEXT("\":")+FString::FromInt(Val)+TEXT(","));
}


void FJsonWriter::Add(FString Key, FString Val)
{
	J+=(TEXT("\"")+Key+TEXT("\":")+TEXT("\"")+Val+ TEXT("\","));
}

void FJsonWriter::Object(FString Key)
{
	Obj++;
	J+=(TEXT("\"")+Key+TEXT("\":")+TEXT("{"));
}

void FJsonWriter::BaseObject()
{
	Obj++;
	J+=TEXT("{");
}

void FJsonWriter::EndObject()
{
	Obj--;
	FString Comma = ",";
	J.RemoveFromEnd(*Comma, ESearchCase::IgnoreCase);
	J+=TEXT("}");
}


void FJsonWriter::BaseArray()
{
	Obj++;
	J += TEXT("{");
}


void FJsonWriter::Array(FString Key)
{
	Arr++;
	J+=(TEXT("\"") + Key + TEXT("\":") + TEXT("["));
}

void FJsonWriter::EndArray()
{
	Arr--;
	FString Comma = ",";
	J.RemoveFromEnd(*Comma, ESearchCase::IgnoreCase);
	J+=TEXT("]");
}

FString FJsonWriter::Print()
{
	return J;
}