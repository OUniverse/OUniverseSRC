//Copyright 2015-2019, All Rights Reserved.

/**
Minimal code needed to give another file access to logging.
 */

#pragma once

#include "LogMinimal.generated.h"

#define LOG(LogType,Verb,Text) Major->Log(LogType,Verb,Text)
#define LBOOT ELE::Boot
#define LHOT ELE::Hot
#define LDATA ELE::Data
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ELogConditions : uint8
{
	On					UMETA(DisplayName = "Message"),
};

UENUM(BlueprintType)	//Abbreviation for ELogEntry
enum class ELE : uint8
{
	Boot UMETA(DisplayName = "Boot"),
	Hot UMETA(DisplayName = "Hot"),
	Data UMETA(DisplayName = "Data"),
	Crit UMETA(DisplayName = "Critical"),
};

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ELog : uint8
{
	Primary UMETA(DisplayName = "Primary"),
};

UENUM(BlueprintType)
enum class ELogIcon : uint8
{
	On					UMETA(DisplayName = "Message"),
};