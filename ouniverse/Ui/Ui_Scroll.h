//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Pylon.h"
#include "Interface/Array.h"
#include "Ui_Scroll.generated.h"


class UScrollBox;
class UCanvasPanel;
class UCanvasPanelSlot;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Scroll: public UUi_Pylon
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxDisplayed;

	UCanvasPanel* V_Canvas;
	UScrollBox* V_Scroll;
	
	
	//UCanvasPanelSlot* Slot_;

	UFUNCTION(BlueprintCallable)
	void Require(UCanvasPanel* CanvasPanel, UScrollBox* ScrollBox);

	void Add(UUserWidget* InChild);

	void ClearChildren();

	//ArrayC<UUserWidget*> Entries_;
};