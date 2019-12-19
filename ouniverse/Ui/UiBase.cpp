//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiBase.h"



void UUiBase::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UUiBase::Show()
{
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}
