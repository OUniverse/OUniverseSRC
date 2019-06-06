//Copyright 2015-2019, All Rights Reserved.

#include "System/Log.h"
#include "Interface/File.h"
#include "Interface/Dir.h"
#include "Util/ColorRGB.h"

#include "Min/DebugM.h"

#define LOGC_FILENAME "log.txt"

namespace GlobalSingleton
{
	LogDeleteC Log;
}

LogDeleteC* LogDeleteC::Get()
{
	return &GlobalSingleton::Log;
}

LogDeleteC* LogDeleteC::Create(DirS* InDirLogs)
{
	GlobalSingleton::Log = *(new LogDeleteC(InDirLogs));
	return &GlobalSingleton::Log;
}

LogDeleteC::LogDeleteC() {}

LogDeleteC::LogDeleteC(DirS* InDirLogs)
{
	Cursor = 0;
	Count = 0;
	DirLogs = InDirLogs;

	//PaceVector.assign(Pace::MAX, NULL);
	FileC LogFile = FileC(DirLogs->Get()/"logs.txt");
	LogFile.Empty();
}


void LogDeleteC::Write(uint8 InType, uint8 InVerb, uint8 InIndent, StringC InText)
{
	Count++;
	EntryVector+=(new Entry(InType, InVerb, InIndent, InText, ColorRGB(255, 255, 255)));
}


LogDeleteC::Entry::Entry(uint8 InType, uint8 InVerb, uint8 InIndent, StringC InText, ColorRGB InColor)
{
	Text = InText;
	Type = InType;
	Verbosity = InVerb;
	Color = InColor;
}

StringC LogDeleteC::Entry::Output()
{
	return Text;
}

void LogDeleteC::Print()
{
	StringC LogAmendment = "";

	for (int i = Cursor; i < Count; i++)
	{
		LogAmendment += "#";
		LogAmendment += i;  
		LogAmendment += " | ";
		LogAmendment += EntryVector[i]->Output().NewLine();

		Cursor++;
	}

	FileC LogFile = FileC(DirLogs->Get()/"logs.txt");
	LogFile.Append(LogAmendment);
}