//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

#include "Blueprint/UserWidget.h"
#include "Interface/Array.h"
#include "Curves/CurveFloat.h"
#include "Ui_Scrollodex.generated.h"


class USizeBox;
class UVerticalBox;
class UUi_ScrollodexEl;



UCLASS(Blueprintable)
class OUNIVERSE_API UUi_Scrollodex : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* SizeCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCurveFloat* OpacityCurve;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int DisplayCount;


	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* V_Case;


	int Index;
	bool bAnimating;
	bool bDirection;

	void Forward();
	void Backward();
	
	void Build();

	void MoveComplete();

	void AddEntry(UUi_ScrollodexEl* InScrollodexEl);

	//UCanvasPanelSlot* Slot_;

	//UFUNCTION(BlueprintCallable)
	//void Require(UVerticalBox* InVerticalBox);

	FVector2D ScrollPosSaver;

	bool bScrolling;
	
	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;


	void NativeTick(const FGeometry& MyGeometry, float InDeltaTime) override;

	UPROPERTY()
	TArray<UUi_ScrollodexEl*> Entries_;

	ArrayC<float> Steps;
	ArrayC<UUi_ScrollodexEl*> ActiveEntries_;

};