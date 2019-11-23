//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_Pylon.h"
#include "SYM_UserSelect_Le.generated.h"

class UserC;

class USYM_UserSelect;
class UTexture2D;
class UImage;
class UTextBlock;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_UserSelect_Le : public UUi_Pylon
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static USYM_UserSelect_Le* Create(USYM_UserSelect* InView, UserC* InUser);

	void Init(USYM_UserSelect* InView, UserC* InUser);

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;


	UserC* User_;

	USYM_UserSelect* View_;


};