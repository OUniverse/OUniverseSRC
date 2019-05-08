//Copyright 2015-2019, All Rights Reserved.

/**
SystemTasks are for long tasks of procedeural code. 
They can be launched by the MAJOR singleton.
The boot process used to be handled here but that's been moved and currently they have no usage.

- Allows cleaner Singletons as they don't have to be filled with lots of procedeural tasks.
- Allows for multithreading since a SystemTask can be executed in a thread.
- Allows for GATES which wait for a series of checks to be correct before proceeding.
 */

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "System/Delegates.h"
#include "System/Transient.h"
#include "SystemTask.generated.h"

/**
 * 
 */

class UMajor;
class UGate;


UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class ESystemTasks : uint8
{
	BigBang,
};


UCLASS()
class OUNIVERSE_API USystemTask : public UObject
{
	GENERATED_BODY()

	#define TICK_QUICKGATE 0.1f

public:

	static UClass* GetSystemTaskClass(ESystemTasks SystemTask);
	
	UPROPERTY()
	bool bGateOpen;
	UPROPERTY()
	UMajor* Major;
	UPROPERTY()
	UGate* Gate;

	DelegateSimple CallBack;

	void Init(UMajor* InMajor);
	virtual void Start();
	virtual void Thread();
	virtual void End();
};


UCLASS()
class OUNIVERSE_API USYTASK_BigBang : public USystemTask
{
	GENERATED_BODY()

public:
		
	virtual void Start() override;
	virtual void Thread() override;
	bool AreSingletonsReady();
	void SingletonsReady();
};