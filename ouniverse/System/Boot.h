//Copyright 2015-2019, All Rights Reserved.

/**

Boot is the procedeural process of setting up all of OUniverse's services and allowing them to load their data and set each other up.
	*Boot works by calling the UBoot::Boot function from any level in UE4 blueprints.

Tasks:
- Creates the Major singleton and adds all services to it.
	*The Major singleton is friended with Boot so that it can only be manipulated by the boot process.
	*Later it might be friend to some testing classes also to allow controlled testing of many components.
- Upon completing this task it hands things off to the ProtocolManager.
- Has alternate boot calls like BootTest() to give quick access to controlled tests.

 */

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Boot.generated.h"


UCLASS()
class UBoot : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:


	//Call this from any level blueprint to begin the OUniverse boot process. Must be called only once.
	UFUNCTION(BlueprintCallable, Category = "OUniverse", meta = (WorldContext = "WorldContextObject", ShowWorldContextPin))
	static void Boot(UObject* WorldContextObject);


	//Call this from any level blueprint to begin the OUniverse customized test boot process. Must be called only once.
	UFUNCTION(BlueprintCallable, Category = "OUniverse", meta = (WorldContext = "WorldContextObject", ShowWorldContextPin))
	static void TestBoot(UObject* WorldContextObject);

	static void UiReady();

};
