//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "WRI_Splash.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Splash : public UUiView
{

	GENERATED_BODY()

public:

	static UWRI_Splash* Create(UUiView* InParentView);

	void Init(UUiView* InParentView);

	UFUNCTION(BlueprintCallable)
	void CmdAdvance();

};