//Copyright 2015-2019, All Rights Reserved.

/**

## UiManager

> **Singleton Service: Created once only by the boot process.**

The UiManager is a service singleton which manages all user interface elements (UI).

#### IO
IO is used here as an abbreviation for Interface Object and is any menu component
* A menu IO can be made up of many smaller IOs.

#### Tasks:
* Coordinates all of the UI's IO elements.
* Allows the IO elements to register with other systems (For example the console registering for the console CommandC).
* Activates each IO so that they bind themselves to the actual UI.
* Provides functions for other parts of the program to trigger UI events like popup notifications or data ribbons.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Ui/Ui_Opt.h"
#include "SYM_AlphaOpt.generated.h"

class UUi_View;
class UImage;
class UTextBlock;
class UUi_Catch;

class USYM_Alpha;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_AlphaOpt: public UUi_Opt
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static USYM_AlphaOpt* Create(UWorld* InScope, UUi_View* InView, int InViewID, int BabelUID);

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;
	UPROPERTY(meta = (BindWidget))
	UUi_Catch* V_Catch;

	int BabelID_;

	int ViewUID_;

	USYM_Alpha* CastedView_;

	void Clicked() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* Graphic;

};