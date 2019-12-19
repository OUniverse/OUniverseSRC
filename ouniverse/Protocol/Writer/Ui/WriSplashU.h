//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriSplashU.generated.h"

class UUiButton;
class WriSplashP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriSplash : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriSplashP* InPro);

	WriSplashP* Pro_;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Start;
	UPROPERTY(meta = (BindWidget))
	UUiButton* V_Back;

	static enum REG {
		Start,
		Back,
	};
};