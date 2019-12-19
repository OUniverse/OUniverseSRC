//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

#include "Blueprint/UserWidget.h"
#include "UiScrollEl.generated.h"

class USizeBox;
class UUiScroll;

UCLASS(Blueprintable)
class OUNIVERSE_API UUiScrollEl : public UUserWidget
{

	GENERATED_BODY()

public:


	void SetParentScroll(UUiScroll* InScroll);

	UUiScroll* OwningScroll_;

	UPROPERTY(meta = (BindWidget))
	USizeBox* V_Size;

	bool bHovered;
	bool bCenetered;

	virtual void UpdateStyleByViewPosition(float InViewPosition) {};	

	float PreciseClickTracker;
	
	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

	virtual void PreciseClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) {};

	virtual void Hovered_Mechanism();
	virtual void Unhovered_Mechanism();

	virtual void Centered_Mechanism();
	virtual void Uncentered_Mechanism();

	UFUNCTION(BlueprintImplementableEvent)
	void HoveredBP();

	UFUNCTION(BlueprintImplementableEvent)
	void UnhoveredBP();

	UFUNCTION(BlueprintImplementableEvent)
	void CenteredBP();

	UFUNCTION(BlueprintImplementableEvent)
	void UncenteredBP();

};