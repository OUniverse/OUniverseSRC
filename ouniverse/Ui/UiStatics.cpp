//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiStatics.h"
#include "System/Babel.h"
#include "System/Major.h"
#include "System/ControlUE.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"

FText UUiStatics::DecodeTextHash(int Hash)
{
//#if WITH_EDITOR
//	return FText::FromString("EDITOR BLOCK");
//#endif

	return BabelC::Get()->Decode(Hash);
}

void UUiStatics::PlaySound(USoundBase* Sound, UObject* WorldContextObject, bool bBypassMute, float  ExtraVolumeModifier, float  ExtraPitchModifier, float PitchRange)
{
	UGameplayStatics::PlaySound2D(WorldContextObject, Sound, 1.0f, 1.0f, 0.0f);
}

void UUiStatics::FocusWidget(UUserWidget* InWidget)
{
	InWidget->SetUserFocus(UMajor::Get()->Control());
}