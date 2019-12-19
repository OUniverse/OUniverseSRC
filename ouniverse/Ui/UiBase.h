//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UiBase.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiBase : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) {};


	void Hide();
	
	void Show();

};