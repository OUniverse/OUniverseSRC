//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "SymUserMenuU.generated.h"

class UUiBaseNew;
class UUiButtonNew;
class SymUserMenuP;

class USymUserSelect;
class USymUserCreate;
class USymUserEdit;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymUserMenu : public UUiBaseNew
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Create;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Select;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Edit;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Back;

	UPROPERTY(meta = (BindWidget))
	USymUserSelect* View_Select;
	UPROPERTY(meta = (BindWidget))
	USymUserCreate* View_Create;
	UPROPERTY(meta = (BindWidget))
	USymUserEdit*	View_Edit;


	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

	static enum REG {
		New,
		Select,
		Edit,
		Back,
	};

	SymUserMenuP* Pro_;
	void UiConstruct(SymUserMenuP* InPro);
};