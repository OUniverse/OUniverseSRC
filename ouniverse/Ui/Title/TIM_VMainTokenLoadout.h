//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "TIM_VMainTokenLoadout.generated.h"

class LoadoutC;
class UTextBlock;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UTIM_VMainTokenLoadout : public UUbc
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