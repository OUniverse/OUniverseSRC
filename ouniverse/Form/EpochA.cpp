//Copyright 2015-2019, All Rights Reserved.

#include "Form/EpochA.h"
#include "Form/EpochF.h"



UEpochA* UEpochA::Create(EpochF* InForm)
{
	UEpochA* Neu = NewObject<UEpochA>();
	Neu->InitBase(InForm);
	return Neu;
}