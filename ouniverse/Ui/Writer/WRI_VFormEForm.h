//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "System/FormWrap.h"
#include "WRI_VFormEForm.generated.h"

class UWRI_VForm;
class UUi_ScrollBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VFormEForm : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_VFormEForm* Create(UWRI_VForm* InView, FormWrapS InFormW);
	void Init(UWRI_VForm* InView, FormWrapS InFormW);

	FormWrapS Form_;

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;
};