//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymToken_User.generated.h"

class UserC;
class UTextBlock;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API USYM_MainTokenUser : public UUiBase
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