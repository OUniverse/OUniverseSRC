//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Master.h"


void UUi_Master::SetScope(UWorld* InScope)
{
	Scope_ = InScope;
}

UWorld* UUi_Master::Scope()
{
	return Scope_;
}