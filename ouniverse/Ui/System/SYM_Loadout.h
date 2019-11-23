//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_Loadout.generated.h"

class USYM_Alpha;

class LoadoutLibC;

class UUi_ScrollBox;
class USYM_VLoadoutEntry;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_Loadout : public UUi_View
{

	GENERATED_BODY()

public:

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;

	USYM_VLoadoutEntry* ActiveEntry_;

	USYM_Alpha* CastedView_;
};