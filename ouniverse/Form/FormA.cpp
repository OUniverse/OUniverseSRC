//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormA.h"
#include "Form/FormF.h"

UFormA* UFormA::Create(FormF* InForm)
{
	UFormA* Neu = NewObject<UFormA>();
	Neu->InitBase(InForm);
	return Neu;
}

void UFormA::InitBase(FormF* InForm)
{
	Form_ = InForm;
}

FormF* UFormA::Form()
{
	return Form_;
}

int UFormA::GetFormUID()
{
	return Form_->UID().ToInt();
}

FString UFormA::GetFormID()
{
	return Form_->ID().ToFString();
}