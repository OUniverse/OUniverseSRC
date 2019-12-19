//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "WriProU.generated.h"

class UWriMenu;
class UWriSplash;
class UWriDataLoad;
class UWriFooter;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriPro : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	UPROPERTY(meta = (BindWidget))
	UWriMenu* View_Menu;

	UPROPERTY(meta = (BindWidget))
	UWriDataLoad* View_DataLoad;

	UPROPERTY(meta = (BindWidget))
	UWriSplash* View_Splash;

	UPROPERTY(meta = (BindWidget))
	UWriFooter* View_Footer;

};