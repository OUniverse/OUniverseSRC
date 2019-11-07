//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Alpha.h"


void UUi_Alpha::SetScope(UWorld* InScope)
{
	Scope_ = InScope;
}

UWorld* UUi_Alpha::Scope()
{
	return Scope_;
}