//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormA.h"
#include "Data/DataD.h"

UFormA* UFormA::Create(DataD* InForm)
{
	UFormA* Neu = NewObject<UFormA>();
	Neu->InitBase(InForm);
	return Neu;
}

void UFormA::InitBase(DataD* InForm)
{
	Form_ = InForm;
}

DataD* UFormA::Form()
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