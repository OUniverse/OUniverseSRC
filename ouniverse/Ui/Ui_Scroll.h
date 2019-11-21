//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "Interface/Array.h"
#include "Ui_Scroll.generated.h"


class UScrollBox;
class UUserWidget;
class UUbc;
class UCanvasPanelSlot;

UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Scroll: public UUbc
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MaxHeight;

	UPROPERTY(meta = (BindWidget))
	UScrollBox* V_Scroll;

	UCanvasPanelSlot* Slot_;

	void Add(UUserWidget* InChild);

	void ClearChildren();

	ArrayC<UUbc*> Entries_;
};