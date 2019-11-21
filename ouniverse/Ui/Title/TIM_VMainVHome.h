//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "TIM_VMainVHome.generated.h"

class UTIM_Alpha;

UCLASS(Blueprintable)
class OUNIVERSE_API UTIM_VMainVHome : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static UTIM_VMainVHome* Create(UUi_View* InParentView);

	void Init(UUi_View* InParentView);


	UTIM_Alpha* CastedAlpha;

	UFUNCTION(BlueprintCallable)
	void CmdAdvance();

};