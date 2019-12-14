//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "WriSplashU.generated.h"

class UUiButtonNew;
class WriSplashP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriSplash : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(WriSplashP* InPro);

	WriSplashP* Pro_;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Start;
	UPROPERTY(meta = (BindWidget))
	UUiButtonNew* V_Back;

	static enum REG {
		Start,
		Back,
	};
};