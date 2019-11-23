//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VMainVFormEForm.h"
#include "UI/Writer/WRI_FormEdit.h"

#include "System/FormTypes.h"

#include "Ui/FormField/FFbc.h"
#include "Form/FormF.h"

#include "System/Class.h"


void UWRI_FormEdit_Form::NativeConstruct()
{
	//DBUG(Form_.Form()->ID().ToChar());

	//void* Test = NULL;

	//Form_.Form()->TryVP(2,Test);

	//StringC* Str= static_cast<StringC*>(Test);

	//DBUG(Str->ToChar());

	Super::NativeConstruct();
}

UWRI_FormEdit_Form* UWRI_FormEdit_Form::Create(UWRI_FormEdit* InView, FormWrapS InFormW)
{
	UWRI_FormEdit_Form* Neu = CreateWidget<UWRI_FormEdit_Form>(InView->Scope(),ClassC::WRI_FormEdit_Form());
	Neu->Init(InView, InFormW);

	return Neu;
}

void UWRI_FormEdit_Form::Init(UWRI_FormEdit* InView, FormWrapS InFormW)
{
	//SetView(InView);
	Form_ = InFormW;
}