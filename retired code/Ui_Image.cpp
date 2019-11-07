//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Image.h"
#include "Components/Image.h"




void UUi_Image::NativeConstruct()
{
	V_Image->SetBrushSize(ImageSize);
	Super::NativeConstruct();
}

void UUi_Image::Set(UTexture2D* InTexture)
{
	V_Image->SetBrushFromTexture(InTexture);
}