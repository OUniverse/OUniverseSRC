//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymUser.generated.h"


class UserLibC;
class UserDaisC;

class UUiButton;
class USYM_UserCreate;
class USYM_UserSelect;
class USYM_UserEdit;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_User : public UUiView
{

	GENERATED_BODY()

public:

	void Init(UUiView* InParentView, UserLibC* InUserLib, UserDaisC* InUserDais);

	UserLibC* UserLib_;
	UserDaisC* UserDais_;

	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Create;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Select;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Edit;

	UPROPERTY(meta = (BindWidget))
	USYM_UserCreate* View_UserCreate;
	UPROPERTY(meta = (BindWidget))
	USYM_UserSelect* View_UserSelect;
	UPROPERTY(meta = (BindWidget))
	USYM_UserEdit* View_UserEdit;

	void ViewOpen_Technical() override;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

};