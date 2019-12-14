//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymUserEditU.h"



void USymUserEdit::NativeConstruct()
{
	Super::NativeConstruct();
}

void USymUserEdit::UiConstruct(SymUserEditP* InPro)
{
	Pro_ = InPro;
	//UserLib_ = InUserLib;
}