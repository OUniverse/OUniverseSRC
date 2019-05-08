//Copyright 2015-2019, All Rights Reserved.

/**
The LogManager is a Singleton extension to MAJOR and manages logging.
It creates individual Logs (ULog) in a Map and provides a bridge to logging for all of OUniverse's code systems.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "System/LogMinimal.h"
#include "LogManager.generated.h"

class ULog;
class UMajor;

#define LOG_NAME_PRIMARY "primary.txt"
UCLASS()
class OUNIVERSE_API ULogManager : public UObject
{
	GENERATED_BODY()

public:
	
	UPROPERTY()
	UMajor* Major;

	FORCEINLINE void Init(UMajor* Major);
	TMap<ELog,ULog*> LogMap;
	TMap<FString,ULog*> CustomLogMap;

	ULog* AddLog(ELog LogType,FString Path);
	void Write(ELE Log, uint8 Verb, FString Text);
};