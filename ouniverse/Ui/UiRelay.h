//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "UiRelay.generated.h"


class UUiBase;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API UUiRelay : public UUserWidget
{

	GENERATED_BODY()

public:

	void SetRelay(int InID, UUiBase* InRelay);
	UUiBase* Relay_;

	int ID_;

};