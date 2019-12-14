//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymLoadoutSelectU.h"

#include "Ui/UiButton.h"
#include "Protocol/System/Ui/SymLoadoutSelectU_Solodex.h"

void USymLoadoutSelect::NativeConstruct()
{
	Super::NativeConstruct();
}

void USymLoadoutSelect::UiConstruct(SymLoadoutSelectP* InPro, LoadoutLibC* InLoadoutLib)
{
	Pro_ = InPro;
	LoadoutLib_ = InLoadoutLib;
	V_Solodex->UiConstruct(InPro, InLoadoutLib);
}