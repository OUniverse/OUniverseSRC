//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymToken_Loadout.h"

#include "System/Loadout.h"
#include "Components/TextBlock.h"

void  USYM_MainTokenLoadout::NativeConstruct()
{
	Super::NativeConstruct();
}

void USYM_MainTokenLoadout::SetLoadout(LoadoutC* InLoadout)
{
	V_ID->SetText(InLoadout->ID().ToFText());
}