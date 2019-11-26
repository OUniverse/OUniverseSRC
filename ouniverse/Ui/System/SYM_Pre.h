//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_Pre.generated.h"

class USYM_Alpha;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_Pre : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_Pre* Create(UUi_View* InParentView);

	void Init(UUi_View* InParentView);


	USYM_Alpha* CastedAlpha;

	UFUNCTION(BlueprintCallable)
	void CmdAdvance();

};