//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymMenuU.generated.h"

class UUiButton;
class SymMenuP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymMenu : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(SymMenuP* InPro);

	SymMenuP* Pro_;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

	UPROPERTY(meta = (BindWidget))
	UUiButton* V_NewGame;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Continue;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_User;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Loadout;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Trophey;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Settings;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Update;

	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Credits;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_News;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Scribe;

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