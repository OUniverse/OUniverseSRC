//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "WRI_Splash.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Splash : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_Splash* Create(UUi_View* InParentView);

	void Init(UUi_View* InParentView);

	UFUNCTION(BlueprintCallable)
	void CmdAdvance();

};