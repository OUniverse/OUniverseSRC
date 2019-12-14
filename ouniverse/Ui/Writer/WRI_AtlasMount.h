//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "Interface/Array.h"
#include "WRI_AtlasMount.generated.h"

class UWRI;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_AtlasMount : public UUiView
{

	GENERATED_BODY()

public:


	void Init(UUiView* InParentView);

	static void MountThread(UWRI* InAlpha);


	UFUNCTION(BlueprintCallable)
	void AnimationComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void MountingStart();

	UFUNCTION(BlueprintImplementableEvent)
	void MountingComplete();

};