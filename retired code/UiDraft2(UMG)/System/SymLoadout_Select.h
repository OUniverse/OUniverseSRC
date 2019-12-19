//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymLoadout_Select.generated.h"


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_LoadoutSelect : public UUiView
{

	GENERATED_BODY()


public:

	void Init(UUiView* InParentView);

};