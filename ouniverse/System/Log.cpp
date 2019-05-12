//Copyright 2015-2019, All Rights Reserved.

#include "System/Log.h"
#include "Interface/File.h"
#include "Interface/Dir.h"
#include "Util/ColorRGB.h"

#include "Min/DebugM.h"

#define LOGC_FILENAME "log.txt"

namespace GlobalSingleton
{
	LogC Log;
}

LogC* LogC::Get()
{
	return &GlobalSingleton::Log;
}

LogC* LogC::Create(DirS* InDirLogs)
{
	GlobalSingleton::Log = *(new LogC(InDirLogs));
	return &GlobalSingleton::Log;
}

LogC::LogC() {}

LogC::LogC(DirS* InDirLogs)
{
	Cursor = 0;
	Count = 0;
	DirLogs = InDirLogs;

	//PaceVector.assign(Pace::MAX, NULL);
	FileC::Empty((DirLogs->Get()/"Logs.txt").ToChar());
}


void LogC::Write(uint8 InType, uint8 InVerb, uint8 InIndent, StringC InText)
{
	Count++;
	EntryVector+=(new Entry(InType, InVerb, InIndent, InText, ColorRGB(255, 255, 255)));
}


LogC::Entry::Entry(uint8 InType, uint8 InVerb, uint8 InIndent, StringC InText, ColorRGB InColor)
{
	Text = InText;
	Type = InType;
	Verbosity = InVerb;
	Color = InColor;
}

StringC LogC::Entry::Output()
{
	return Text;
}

void LogC::Print()
{
	StringC LogAmendment = "";

	for (int i = Cursor; i < Count; i++)
	{
		LogAmendment + "#"+"FUCK"+i+" | "+EntryVector[i]->Output();
		LogAmendment += FileC::LineBreak().c_str();
		Cursor++;
	}

	FileC::Append(DirLogs->Get()/"Logs.txt", LogAmendment);
}