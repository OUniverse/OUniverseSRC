//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_VUserVCreate.generated.h"

class UserLibC;
class UEditableTextBox;
class USYM_Alpha;

class UserC;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_VUserVCreate : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_VUserVCreate* Create(UUi_View* InParentView, UserLibC* InUserLib);

	void Init(UUi_View* InParentView, UserLibC* InUserLib);
	
	UserLibC* UserLib_;

	USYM_Alpha* CastedAlpha;

	UPROPERTY(meta = (BindWidget))
	UEditableTextBox* V_Input;

	UFUNCTION(BlueprintCallable)
	void CmdAccept();

};