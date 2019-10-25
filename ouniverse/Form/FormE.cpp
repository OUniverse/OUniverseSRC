//Copyright 2015-2019, All Rights Reserved.

#include "Form/FormE.h"

UFormE* UFormE::Create(FormD* InDat)
{
	UFormE* Obj = NewObject<UFormE>();
	Obj->Init(InDat);
	return Obj;
}

void UFormE::Init(FormD* InDat)
{
	Dat_ = InDat;
}