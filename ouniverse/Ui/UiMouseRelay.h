//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Blueprint/UserWidget.h"
#include "UiMouseRelay.generated.h"

class UUiBaseNew;

UCLASS(Blueprintable)
class OUNIVERSE_API UUiMouseRelay : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	int ID_;

	UUiBaseNew* Relay_;
	void Setup(int InID, UUiBaseNew* InRelay);

	bool bPressed;
	bool bHitDisabled;
	bool bEventDisabled;

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

};