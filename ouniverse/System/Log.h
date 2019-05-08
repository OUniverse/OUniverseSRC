//Copyright 2015-2019, All Rights Reserved.

/**
LogC.
 */

#pragma once

class UBoot;

#include "CoreMinimal.h"
#include <vector>
#include "Util/ColorRGB.h"


class OUNIVERSE_API LogC
{

	friend UBoot;

public:

	LogC();

	static LogC* Get();

private:
		
	LogC(FString PathToLogCs);

	static LogC* Create(FString PathToLogC);

	int Cursor;
	int Count;
	FString Path;
	
	struct Entry
	{
	public:

		FDateTime Time;
		FString Text;
		uint8 Type;
		uint8 Verbosity;
		ColorRGB Color;

		Entry(uint8 InType, uint8 InVerb, uint8 InIndent, FString InText, ColorRGB InColor);

		FString Output();
	};

	enum Type
	{
		General,
		Boot,
		Error,
		Critical,
		MAX,
	};

	std::vector <Entry*> EntryVector;

	void Write(uint8 InType, uint8 InVerb, uint8 InIndent, FString InText);

	void Print();
};