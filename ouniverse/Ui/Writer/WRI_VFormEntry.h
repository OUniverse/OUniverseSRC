//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ubc.h"
#include "System/FormWrap.h"

#include "WRI_VFormEntry.generated.h"



class UUi_Catch;
class UWRI_VForm;

class UTextBlock;
class UImage;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VFormEntry : public UUbc
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_VFormEntry* Create(UWorld* InScope, UWRI_VForm* InView, FormWrapS InFormW);

	void Init(UWRI_VForm* InView, FormWrapS InFormW);

	FormWrapS FormW_;

	UPROPERTY(meta = (BindWidget))
	UUi_Catch* V_Catch;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;

	UPROPERTY(meta = (BindWidget))
	UImage* V_ImgType;

	UPROPERTY(meta = (BindWidget))
	UImage* V_ImgAtlas;

	UWRI_VForm* View_;

	void Clicked() override;

};