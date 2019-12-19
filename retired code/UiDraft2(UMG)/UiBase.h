//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UiBase.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUiBase : public UUserWidget
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BaseOpen"))
	void BaseOpen();

	UFUNCTION(BlueprintImplementableEvent, meta = (DisplayName = "BaseClose"))
	void BaseClose();

	virtual FReply EventMouseButtonDown(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) { return FReply::Handled(); };
	virtual FReply EventMouseButtonUp(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) { return FReply::Handled(); };
	virtual FReply EventMouseClick(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) { return FReply::Handled(); };
	virtual FReply EventMouseMove(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) { return FReply::Handled(); };
	virtual void EventMouseEnter(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) { };
	virtual void EventMouseLeave(int ElementID, const FPointerEvent& MouseEvent) { };

	virtual void UiPathRequest(int ID, int Type, int Var) {};

	virtual void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) {};

};