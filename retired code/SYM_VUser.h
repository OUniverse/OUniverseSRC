//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_VUser.generated.h"

class UserLibC;
class UCanvasPanel;

class USYM_UserCreate;
class USYM_UserSelect;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_VUser : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_VUser* Create(UUi_View* InParentView, UserLibC* InUserLib);

	void Init(UUi_View* InParentView, UserLibC* InUserLib);

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_View;

	UserLibC* UserLib_;

	USYM_UserCreate* View_Create;
	USYM_UserSelect* View_Select;

};