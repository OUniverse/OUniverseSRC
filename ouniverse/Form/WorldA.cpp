//Copyright 2015-2019, All Rights Reserved.

#include "Form/WorldA.h"
#include "Form/WorldF.h"



UWorldA* UWorldA::Create(WorldF* InForm)
{
	UWorldA* Neu = NewObject<UWorldA>();
	Neu->InitBase(InForm);
	return Neu;
}