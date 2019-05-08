//Copyright 2015-2019, All Rights Reserved.

#include "System/Log.h"
#include "HAL/PlatformFilemanager.h"
#include "Util/ColorRGB.h"

namespace GlobalSingleton
{
	LogC Log;
}

LogC* LogC::Get()
{
	return &GlobalSingleton::Log;
}

LogC* LogC::Create(FString PathToLogCs)
{
	GlobalSingleton::Log = *(new LogC(PathToLogCs));
	return &GlobalSingleton::Log;
}

LogC::LogC() {}

LogC::LogC(FString PathToLogCs)
{
	Cursor = 0;
	Count = 0;
	Path = PathToLogCs;
	EntryVector.assign(Type::MAX, NULL);
	FPlatformFileManager::Get().GetPlatformFile().DeleteFile(*PathToLogCs);
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
	return "IDK";
}

void LogC::Print()
{
	FString LogCText;
	FFileHelper::LoadFileToString(LogCText, *Path);

	for (int i = Cursor; i < Count; i++)
	{
		LogCText += "#" + FString::FromInt(i) + " | " + EntryVector[i]->Output();
		LogCText += LINE_TERMINATOR;
		Cursor++;
	}

	FFileHelper::SaveStringToFile(LogCText, *Path);
}