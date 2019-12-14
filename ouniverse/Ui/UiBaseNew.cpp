//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiBaseNew.h"



void UUiBaseNew::Hide()
{
	SetVisibility(ESlateVisibility::Collapsed);
}

void UUiBaseNew::Show()
{
	SetVisibility(ESlateVisibility::SelfHitTestInvisible);
}
