//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_Pylon.h"
#include "System/FormWrap.h"

#include "WRI_FormEdit_Le.generated.h"



class UWRI_FormEdit;

class UTextBlock;
class UImage;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_FormEdit_Le : public UUi_Pylon
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_FormEdit_Le* Create(UWorld* InScope, UWRI_FormEdit* InView, FormWrapS InFormW);

	void Init(UWRI_FormEdit* InView, FormWrapS InFormW);

	FormWrapS FormW_;


	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;

	UPROPERTY(meta = (BindWidget))
	UImage* V_ImgType;

	UPROPERTY(meta = (BindWidget))
	UImage* V_ImgAtlas;

	UWRI_FormEdit* View_;

	void OnClick();

};