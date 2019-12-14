//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "SymMenuU.generated.h"

class UUiButtonNew;
class SymMenuP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymMenu : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(SymMenuP* InPro);

	SymMenuP* Pro_;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_NewGame;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Continue;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_User;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Loadout;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Trophey;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Settings;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Update;

	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Credits;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_News;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Scribe;

	static enum REG {
		NewGame,
		Continue,
		User,
		Loadout,
		Trophey,
		Settings,
		Update,
		Credits,
		News,
		Scribe,
	};
};