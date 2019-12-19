//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiScrollEntry.h"
#include "WriFormU_ScrolLEntry.generated.h"


class AtlasC;
class UWriForm;
class UUi_Bool;
class UImage;
class UTextBlock;
class UUiMouseInput;
class UWriForm;

class UUiBool;
class FormDataC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriForm_ScrollEntry : public UUiScrollEntry
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWriForm_ScrollEntry* Create(UWriForm* InView, FormDataC* InFormData);

	void Init(UWriForm* InView, FormDataC* InFormData);

	FormDataC* FormData_;
	UWriForm* View_;

	bool bSelected_;

	UPROPERTY(meta = (BindWidget))
	UImage* vType;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* vTitle;
	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* vSelect;

	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* vArea;

	UPROPERTY(meta = (BindWidget))
	UUiBool* vUnsaved;
	UPROPERTY(meta = (BindWidget))
	UUiBool* vOpen;
	UPROPERTY(meta = (BindWidget))
	UUiBool* vError;



	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;


	void BoolSelectedToggle();

	UFUNCTION(BlueprintImplementableEvent)
	void BoolSelectedOn();
	UFUNCTION(BlueprintImplementableEvent)
	void BoolSelectedOff();

	static enum REG {
		MiArea,
		MiSelect,
	};
};