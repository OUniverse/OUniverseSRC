//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymToken_Loadout.generated.h"

class LoadoutC;
class UTextBlock;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API USYM_MainTokenLoadout : public UUiBase
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