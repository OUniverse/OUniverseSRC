//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_View.h"
#include "SYM_UserSelect.generated.h"

class UserLibC;
class UUi_Scroll;

class USYM_UserSelect_Le;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_UserSelect : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_UserSelect* Create(UUi_View* InParentView, UserLibC* InUserLib);

	void Init(UUi_View* InParentView, UserLibC* InUserLib);

	UPROPERTY(meta = (BindWidget))
	UUi_Scroll* V_Scroll;

	UserLibC* UserLib_;

};