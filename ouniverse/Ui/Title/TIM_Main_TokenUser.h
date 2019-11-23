//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Pylon.h"
#include "TIM_Main_TokenUser.generated.h"

class UserC;
class UTextBlock;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UTIM_VMainTokenUser : public UUi_Pylon
{

	GENERATED_BODY()

private:




public:

	virtual void NativeConstruct() override;

	void SetUser(UserC* InUser);

	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_ID;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Score;

};