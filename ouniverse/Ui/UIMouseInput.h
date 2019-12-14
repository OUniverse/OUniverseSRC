//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiRelay.h"
#include "UIMouseInput.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUiMouseInput : public UUiRelay
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	bool bPressed;

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

};