//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_El.h"
#include "Ui_Interface.generated.h"


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUi_Interface : public UUi_El
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintPure)
	UUi_Pylon* Relay();

	void SetupInterface(UUi_Pylon* InRelay, int InInterfaceUID);

	UUi_Pylon* Relay_;

	UFUNCTION(BlueprintImplementableEvent)
	void InterfaceSetup();

	int InterfaceUID_;

	int InterfaceUID();
};