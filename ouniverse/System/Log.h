//Copyright 2015-2019, All Rights Reserved.

/**

## Log

Logging class, primarily intended to be created once by the boot process and used as a singleton.
> Here it's created once at startup by the boot script but can be instanced if needed.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

class UBoot;
extern struct DirS;

#include "CoreMinimal.h"
#include "Util/ColorRGB.h"
#include "Interface/String.h"
#include "Interface/Array.h"

class OUNIVERSE_API LogC
{

	friend UBoot;

public:

	LogC();

	static LogC* Get();

	void Write(uint8 InType, uint8 InVerb, uint8 InIndent, StringC InText);

	void Print();

private:
		
	LogC(DirS* InDirLogs);

	static LogC* Create(DirS* InDirLogs);

	int Cursor;
	int Count;
	DirS* DirLogs;
	
	struct Entry
	{
	public:

		FDateTime Time;
		StringC Text;
		uint8 Type;
		uint8 Verbosity;
		ColorRGB Color;

		Entry(uint8 InType, uint8 InVerb, uint8 InIndent, StringC InText, ColorRGB InColor);

		StringC Output();
	};

	enum Type
	{
		General,
		Boot,
		Error,
		Critical,
		MAX,
	};

	ArrayC<Entry*> EntryVector;

};