//Copyright 2015-2019, All Rights Reserved.


#include "System/Form_.h"
#include "Form/FormF.h"



UForm* UForm::Create(FormF* InForm)
{
	UForm* Neu = NewObject<UForm>();
	Neu->Init(InForm);
	return Neu;
}

void UForm::Init(FormF* InForm)
{
	Form_ = InForm;
}