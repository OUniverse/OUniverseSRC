//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Statics.h"
#include "System/Babel.h"
#include "Kismet/GameplayStatics.h"

FText UUi_Statics::DecodeTextHash(int Hash)
{
	return UBabel::Decode(Hash);
}

void UUi_Statics::PlaySound(USoundBase* Sound, UObject* WorldContextObject, bool bBypassMute, float  ExtraVolumeModifier, float  ExtraPitchModifier, float PitchRange)
{
	UGameplayStatics::PlaySound2D(WorldContextObject, Sound, 1.0f, 1.0f, 0.0f);
}