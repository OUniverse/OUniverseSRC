//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "System/FormWrap.h"
#include "WRI_VMainVFormEForm.generated.h"

class UWRI_FormEdit;
class UUi_ScrollBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_FormEdit_Form : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_FormEdit_Form* Create(UWRI_FormEdit* InView, FormWrapS InFormW);
	void Init(UWRI_FormEdit* InView, FormWrapS InFormW);

	FormWrapS Form_;

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;
};