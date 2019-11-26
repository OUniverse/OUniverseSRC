//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_Home.generated.h"

class USYM_Alpha;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_Home : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_Home* Create(UUi_View* InParentView);

	void Init(UUi_View* InParentView);


	USYM_Alpha* CastedAlpha;

	UFUNCTION(BlueprintCallable)
		void CmdAdvance();

};