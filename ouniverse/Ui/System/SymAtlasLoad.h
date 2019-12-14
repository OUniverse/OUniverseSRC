//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymAtlasLoad.generated.h"

class USystemUi;

class AtlasLibC;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_AtlasLoad : public UUiView
{

	GENERATED_BODY()


public:

	void Init(UUiView* InParentView, AtlasLibC* InAtlasLib);

	AtlasLibC* AtlasLib_;

	static void LoadingThread(AtlasLibC* InAtlasLib);

	void ViewOpen_Technical() override;

	UFUNCTION(BlueprintImplementableEvent)
	void LoadStart();

	UFUNCTION(BlueprintImplementableEvent)
	void LoadComplete();

	UFUNCTION(BlueprintCallable)
	void AnimationComplete();
};