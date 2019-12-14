//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiScroller.h"
#include "WriLoadoutU_Scroll.generated.h"



UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriLoadout_Scroll : public UUiScroller
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

};