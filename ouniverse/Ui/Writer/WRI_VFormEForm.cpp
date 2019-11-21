//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Writer/WRI_VFormEForm.h"
#include "UI/Writer/WRI_VForm.h"

#include "System/FormTypes.h"

#include "Ui/FormField/FFbc.h"
#include "Form/FormF.h"

#include "System/Class.h"


void UWRI_VFormEForm::NativeConstruct()
{
	//DBUG(Form_.Form()->ID().ToChar());

	//void* Test = NULL;

	//Form_.Form()->TryVP(2,Test);

	//StringC* Str= static_cast<StringC*>(Test);

	//DBUG(Str->ToChar());

	Super::NativeConstruct();
}

UWRI_VFormEForm* UWRI_VFormEForm::Create(UWRI_VForm* InView, FormWrapS InFormW)
{
	UWRI_VFormEForm* Neu = CreateWidget<UWRI_VFormEForm>(InView->Scope(),ClassC::WRI_VFormEForm());
	Neu->Init(InView, InFormW);

	return Neu;
}

void UWRI_VFormEForm::Init(UWRI_VForm* InView, FormWrapS InFormW)
{
	//SetView(InView);
	Form_ = InFormW;
}