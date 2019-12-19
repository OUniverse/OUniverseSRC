//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "UiButton.generated.h"

class UUiBase;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiButton : public UUiFocus
{

	GENERATED_BODY()

public:

	void SetupButton(int InID, UUiBase* InRelay);

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

	UFUNCTION(BlueprintImplementableEvent)
	void HoveredBP();
	UFUNCTION(BlueprintImplementableEvent)
	void UnhoveredBP();

	UFUNCTION(BlueprintImplementableEvent)
	void SelectedBP();
	UFUNCTION(BlueprintImplementableEvent)
	void UnselectedBP();

	bool InputCommand(KeyS InKey) override;

private:

	int ID_;
	UUiBase* Relay_;
	bool bPressed;

};