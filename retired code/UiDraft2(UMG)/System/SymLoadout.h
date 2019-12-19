//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymLoadout.generated.h"


UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_Loadout : public UUiView
{

	GENERATED_BODY()


public:


	void Init(UUiView* InParentView);

};