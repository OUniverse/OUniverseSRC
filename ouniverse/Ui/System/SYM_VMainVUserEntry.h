//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "SYM_VMainVUserEntry.generated.h"

class UserC;

class USYM_VMainVUser;
class UTexture2D;
class UImage;
class UTextBlock;
class UUi_Catch;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_VMainVUserEntry : public UUbc
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static USYM_VMainVUserEntry* Create(UWorld* InScope, USYM_VMainVUser* InView, UserC* InUser);

	void Init(USYM_VMainVUser* InView, UserC* InUser);

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;
	UPROPERTY(meta = (BindWidget))
	UUi_Catch* V_Catch;


	UserC* User_;

	USYM_VMainVUser* View_;
};