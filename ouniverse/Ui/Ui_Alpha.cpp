//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Alpha.h"


void UUi_Alpha::SetupAlpha(UWorld* InScope, UUi* InUi)
{
	Alpha_ = this;
	OwningView_ = NULL;
	Scope_ = InScope;
	Ui_ = InUi;
	
}

UWorld* UUi_Alpha::Scope()
{
	return Scope_;
}