//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiEditableText.h"
#include "Components/EditableText.h"

void UUiEditableText::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUiEditableText::Require(UEditableText* InText)
{
	vText = InText;
}

void UUiEditableText::SetText(FText InText)
{
	vText->SetText(InText);
}