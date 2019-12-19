//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymUserSelectU.h"

#include "Protocol/System/Ui/SymUserSelectU_Solodex.h"

void USymUserSelect::NativeConstruct()
{
	Super::NativeConstruct();
}

void USymUserSelect::UiConstruct(SymUserSelectP* InPro, UserLibC* InUserLib)
{
	Pro_ = InPro;
	UserLib_ = InUserLib;
	V_Solodex->UiConstruct(InPro, InUserLib);
}