//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Interface/Array.h"
#include "WRI_AtlasMount.generated.h"

class UWRI_Alpha;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_AtlasMount : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_AtlasMount* Create(UUi_View* InParentView);

	void Init(UUi_View* InParentView);

	static void MountThread(UWRI_Alpha* InAlpha);


	UFUNCTION(BlueprintCallable)
	void AnimationComplete();

	UFUNCTION(BlueprintImplementableEvent)
	void MountingStart();

	UFUNCTION(BlueprintImplementableEvent)
	void MountingComplete();

};