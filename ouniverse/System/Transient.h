//Copyright 2015-2019, All Rights Reserved.

/**
Transient holds a few helpful debugging tools which are not intended to be compiled into the final version.
Primarily it holds heavier ways to print out data when the log is non accessible due to a crash.
 */

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Transient.generated.h"

#define HARDLOGS true
#if HARDLOGS
#define TPRINT(text) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 1.5, FColor::White, text)
#define TLOG(text) UTransient::Log(text)
#define TLOGS(path,space) UTransient::Log(path,space)
#define TLOGF(path,text) UTransient::Log(path,text)
#else
#define TPRINT(text)
#define TLOG(text)
#define TLOGS(path,false)
#define TLOGF(path,text)
#endif

UCLASS()
class OUNIVERSE_API UTransient : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	static void Log(FString NewEntry);
	static void Log(FString LogName, bool space);
	static void Log(FString LogName, FString NewEntry);	
};

