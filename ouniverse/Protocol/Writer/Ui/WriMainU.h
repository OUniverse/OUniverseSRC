//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriMainU.generated.h"

class UUiButton;
class WriMenuP;

class UWriLoadout;
class UWriAtlas;
class UWriForm;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriMenu : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriMenuP* InPro);

	WriMenuP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Loadout;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Atlas;
	UPROPERTY(meta = (BindWidget))
	UUiButton* BT_Form;


	UPROPERTY(meta = (BindWidget))
	UWriLoadout* View_Loadout;
	UPROPERTY(meta = (BindWidget))
	UWriAtlas* View_Atlas;
	UPROPERTY(meta = (BindWidget))
	UWriForm* View_Form;

	static enum REG {
		Loadout,
		Atlas,
		Form,
	};

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

};