//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "UiStatics.generated.h"

class USoundBase;
class UUserWidget;

UCLASS()
class OUNIVERSE_API UUiStatics : public UBlueprintFunctionLibrary
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, Category = "UiStatics", meta = (DisplayName = "DecodeTextHash"))
	static FText DecodeTextHash(int hash);

	UFUNCTION(BlueprintCallable, Category = "UiStatics", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject", DisplayName = "PlaySoundUI"))
	static void PlaySound(USoundBase* Sound, UObject* WorldContextObject, bool bBypassMute, float  ExtraVolumeModifier, float  ExtraPitchModifier, float PitchRange);

	static void FocusWidget(UUserWidget* InWidget);
};