//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Blueprint/UserWidget.h"
#include "UiBaseNew.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UUiBaseNew : public UUserWidget
{

	GENERATED_BODY()

public:

	virtual void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) {};


	void Hide();
	
	void Show();

};