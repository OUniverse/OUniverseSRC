//Copyright 2015-2019, All Rights Reserved.

#include "Form/RegionA.h"
#include "Form/RegionF.h"



URegionA* URegionA::Create(RegionF* InForm)
{
	URegionA* Neu = NewObject<URegionA>();
	Neu->InitBase(InForm);
	return Neu;
}