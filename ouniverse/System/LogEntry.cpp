//Copyright 2015-2019, All Rights Reserved.

#include "LogEntry.h"

LogEntry::LogEntry(ELE InLogType, uint8 InVerb, FString InText)
{
	LogType = InLogType;
	Verbosity = InVerb;
	Time = FDateTime().Now();
	Text = InText;
}