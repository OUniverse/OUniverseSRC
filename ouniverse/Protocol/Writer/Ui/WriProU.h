//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "WriProU.generated.h"

class UWriMenu;
class UWriSplash;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriPro : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UWriMenu* View_Menu;

	UPROPERTY(meta = (BindWidget))
	UWriSplash* View_Splash;

};