//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriButtonU.h"
#include "Protocol/Writer/WriPro.h"

#include "Components/TextBlock.h"

void UWriButton::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriButton::NativeDestruct()
{
	Super::NativeDestruct();
}

void UWriButton::SetTextHash(int InTextHash)
{
	vText->SetText(WriterPro::Dict(InTextHash));
}

void UWriButton::Require(UTextBlock* InText)
{
	vText = InText;
}