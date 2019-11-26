//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Relay.h"
#include "UI_MouseInput.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUI_MouseInput : public UUi_Relay
{

	GENERATED_BODY()

public:

	bool bPressed;

	FReply NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	FReply NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	void NativeOnMouseEnter(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	void NativeOnMouseLeave(const FPointerEvent& MouseEvent) override;

};