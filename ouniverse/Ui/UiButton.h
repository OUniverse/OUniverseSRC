//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiEl.h"
#include "UiButton.generated.h"

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiButton : public UUiEl
{

	GENERATED_BODY()

public:


	void SetupButton(int ID, UUiBase* Relay);

	bool Deselect_Internal();

	UFUNCTION(BlueprintCallable)
	void Deselect();

	bool Select_Internal();

	UFUNCTION(BlueprintCallable)
	void Select();

	UFUNCTION(BlueprintImplementableEvent)
	void HoveredBP();

	UFUNCTION(BlueprintImplementableEvent)
	void UnhoveredBP();
	
	UFUNCTION(BlueprintImplementableEvent)
	void SelectBP();

	UFUNCTION(BlueprintImplementableEvent)
	void DeselectBP();

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

private:


	int ID_;
	UUiBase* Relay_;
	bool bPressed;
};