//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_UserCreate.generated.h"

class UserLibC;
class UUi_TextEdit;
class USYM_Alpha;

class UserC;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_UserCreate : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_UserCreate* Create(UUi_View* InParentView, UserLibC* InUserLib);

	void Init(UUi_View* InParentView, UserLibC* InUserLib);
	
	UserLibC* UserLib_;

	USYM_Alpha* CastedAlpha;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_TextInput;

	UFUNCTION(BlueprintCallable)
	void CmdAccept();

};