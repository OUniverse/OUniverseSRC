//Copyright 2015-2019, All Rights Reserved.

#include "Form/AreaA.h"
#include "Form/AreaF.h"



UAreaA* UAreaA::Create(AreaF* InForm)
{
	UAreaA* Neu = NewObject<UAreaA>();
	Neu->InitBase(InForm);
	return Neu;
}