//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiScrollEntry.h"
#include "WriLoadoutU_ScrolLEntry.generated.h"


class AtlasC;
class UWriLoadout;
class UUi_Bool;
class UImage;
class UTextBlock;
class UUiMouseInput;
class UWriLoadout;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriLoadout_ScrollEntry : public UUiScrollEntry
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWriLoadout_ScrollEntry* Create(UWriLoadout* InView, AtlasC* InAtlas);

	void Init(UWriLoadout* InView, AtlasC* InAtlas);

	AtlasC* Atlas_;
	UWriLoadout* View_;

	bool AtlasMaster_;
	bool AtlasActive_;

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;
	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* V_BoolMaster;
	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* V_BoolActive;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;


	void BoolMasterToggle(bool FromView);
	void BoolActiveToggle();

	UFUNCTION(BlueprintImplementableEvent)
	void BoolMasterOn();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolMasterOff();

	UFUNCTION(BlueprintImplementableEvent)
	void BoolActiveOn();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolActiveOff();

	static enum REG {
		BoolMaster,
		BoolActive,
	};
};