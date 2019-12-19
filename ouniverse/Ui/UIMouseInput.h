//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "UiMouseInput.generated.h"

class UUiBase;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiMouseInput : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	int ID_;

	UUiBase* Relay_;
	void Setup(int InID, UUiBase* InRelay);

	bool bPressed;
	bool bHitDisabled;
	bool bEventDisabled;

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

};