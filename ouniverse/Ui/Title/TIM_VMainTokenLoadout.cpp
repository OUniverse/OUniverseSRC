//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_VMainTokenLoadout.h"

#include "System/Loadout.h"
#include "Components/TextBlock.h"

void  UTIM_VMainTokenLoadout::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTIM_VMainTokenLoadout::SetLoadout(LoadoutC* InLoadout)
{
	V_ID->SetText(InLoadout->ID().ToFText());
}