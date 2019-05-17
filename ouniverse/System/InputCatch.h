//Copyright 2015-2019, All Rights Reserved.

/**

## InputCatch

A full screen blank widget which gathers all input events.
Upon receiving the interactions it forwards them to the InputManager to handle the press/click.

**This is a bandaid to get around the shortcomings of UE4's control system.**

#### Benefits:
* Easy access to rebinding.
* Full control over what keypresses and inputs are doing.
* Distinction between Char Typing and Input commands.
* Allows for a more OOP approach to controls.

 */

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"


class InputManager;


class OUNIVERSE_API SInputCatch : public SCompoundWidget
{

	SLATE_BEGIN_ARGS(SInputCatch)
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