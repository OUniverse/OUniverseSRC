//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "Ui_Relay.generated.h"


class UUi_Base;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUi_Relay : public UUserWidget
{

	GENERATED_BODY()

public:

	void SetRelay(UUi_Base* InRelay, int InID);
	UUi_Base* Relay_;

	int ID_;

};