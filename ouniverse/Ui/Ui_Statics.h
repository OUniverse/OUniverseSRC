//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Ui_Statics.generated.h"

class USoundBase;

UCLASS()
class OUNIVERSE_API UUi_Statics : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "UiStatics", meta = (DisplayName = "DecodeTextHash"))
	static FText DecodeTextHash(int hash);

	UFUNCTION(BlueprintCallable, Category = "UiStatics", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "PlaySoundUI"))
	static void PlaySound(USoundBase* Sound, UObject* WorldContextObject, bool bBypassMute, float  ExtraVolumeModifier, float  ExtraPitchModifier, float PitchRange);

};