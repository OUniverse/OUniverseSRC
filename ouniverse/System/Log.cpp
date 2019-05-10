//Copyright 2015-2019, All Rights Reserved.

#include "System/Log.h"
#include "Interface/File.h"
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

LogC* LogC::Create(FString DirLogs)
{
	GlobalSingleton::Log = *(new LogC(DirLogs));
	return &GlobalSingleton::Log;
}

LogC::LogC() {}

LogC::LogC(FString DirLogs)
{
	Cursor = 0;
	Count = 0;
	Path = DirLogs + LOGC_FILENAME;
	//PaceVector.assign(Pace::MAX, NULL);
	FileC::Empty(Path);
}


void LogC::Write(uint8 InType, uint8 InVerb, uint8 InIndent, FString InText)
{
	Count++;
	EntryVector.push_back(new Entry(InType, InVerb, InIndent, InText, ColorRGB(255, 255, 255)));
}


LogC::Entry::Entry(uint8 InType, uint8 InVerb, uint8 InIndent, FString InText, ColorRGB InColor)
{
	Text = InText;
	Type = InType;
	Verbosity = InVerb;
	Color = InColor;
}

FString LogC::Entry::Output()
{
	return Text;
}

void LogC::Print()
{
	FString LogAmendment = "";

	for (int i = Cursor; i < Count; i++)
	{
		LogAmendment += "#" + FString::FromInt(i) + " | " + EntryVector[i]->Output();
		LogAmendment += FileC::LineBreak();
		Cursor++;
	}
	
	FileC::Append(*Path, LogAmendment);
}