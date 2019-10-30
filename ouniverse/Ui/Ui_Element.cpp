//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Element.h"


bool UUi_Element::CloseInternal()
{
	bool bCancel = false;
	OnClose(bCancel);
	return bCancel;
}

void UUi_Element::OnClose_Implementation(bool& Cancel)
{

}