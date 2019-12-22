//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriMainU.generated.h"

class UWriButton;
class WriMenuP;

class UWriLoadout;
class UWriAtlas;
class UWriData;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriMenu : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriMenuP* InPro);

	WriMenuP* Pro_;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vLoadout;
	UPROPERTY(meta = (BindWidget))
	UWriButton* vAtlas;
	UPROPERTY(meta = (BindWidget))
	UWriButton* vData;
	UPROPERTY(meta = (BindWidget))
	UWriButton* vWorld;
	UPROPERTY(meta = (BindWidget))
	UWriButton* vTools;
	UPROPERTY(meta = (BindWidget))
	UWriButton* vExit;
	   	 

	UPROPERTY(meta = (BindWidget))
	UWriLoadout* View_Loadout;
	UPROPERTY(meta = (BindWidget))
	UWriAtlas* View_Atlas;
	UPROPERTY(meta = (BindWidget))
	UWriData* View_Form;

	static enum REG {
		RLoadout,
		RAtlas,
		RData,
		RWorld,
		RTools,
		RExit,

	};

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

};