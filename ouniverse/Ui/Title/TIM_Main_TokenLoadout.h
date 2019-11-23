//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Pylon.h"
#include "TIM_Main_TokenLoadout.generated.h"

class LoadoutC;
class UTextBlock;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UTIM_VMainTokenLoadout : public UUi_Pylon
{

	GENERATED_BODY()

private:




public:

	virtual void NativeConstruct() override;


	void SetLoadout(LoadoutC* InLoadout);


	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_ID;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_AtlasCount;


};