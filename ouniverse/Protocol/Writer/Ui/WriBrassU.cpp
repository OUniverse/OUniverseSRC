//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriBrassU.h"
#include "Protocol/Writer/WriBrassP.h"
#include "Interface/String.h"
#include "Components/TextBlock.h"
#include "Components/Image.h"

void UWriBrass::NativeConstruct()
{
	Super::NativeConstruct();
}

void UWriBrass::NativeDestruct()
{
	Super::NativeDestruct();
}

void UWriBrass::Display(WriBrassS* InData)
{
	BrassUpdateBP(NULL, StringC("TitleTest").ToFText(), StringC("DescriptionTest").ToFText());
}

void UWriBrass::Clear()
{
	BrassClearBP();
}