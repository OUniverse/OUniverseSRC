//Copyright 2015-2019, All Rights Reserved.

/**
SInput is a full screen blank widget which gathers all keypresses and inputs.
Upon recieving the interactions it forwards them to the InputManager to handle the keypress.
 */

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


class InputManager;


class OUNIVERSE_API SInput : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SInput)
	{
	}

	SLATE_ARGUMENT(TWeakObjectPtr<class AHudUE>, GameHUD);
	SLATE_END_ARGS()


public:

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	/** Overridden from SWidget: Called when a key is pressed down - capturing copy */
	virtual bool SupportsKeyboardFocus() const override;
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent) override;

	virtual FReply OnMouseMove(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;
	virtual FReply OnMouseWheel(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent) override;
	InputManager* InputRelay;

private:
	TWeakObjectPtr<class AHudUE> GameHUD;
	
};