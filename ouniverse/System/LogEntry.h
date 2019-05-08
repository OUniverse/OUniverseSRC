//Copyright 2015-2019, All Rights Reserved.

/**
A single log with a few features to help organize and customize the log output.
This log is intended to output at runtime and have it's output and verbosity customizable by ini files.
It can optionally be output to text documents or have it's contents displayed on screen from debugging UI overlays.
 */

#include "CoreMinimal.h"
#include "System/LogMinimal.h"

#pragma once

struct LogEntry 
{
	LogEntry(ELE InLogType, uint8 InVerb, FString InText);
public:	
	FDateTime Time;
	FString Text;
	ELE LogType;
	uint8 Verbosity;
	FColor Color;
	ELogIcon LogIcon;
};