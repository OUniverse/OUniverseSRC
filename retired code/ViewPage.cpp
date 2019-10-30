//Copyright 2015-2019, All Rights Reserved.

#include "Ui/ViewPage.h"


void UViewPage::Init()
{

}

bool UViewPage::CloseInternal()
{
	 bool bCancel= false;
	 OnClose(bCancel);
	 return bCancel;
}

void UViewPage::OnClose_Implementation(bool& Cancel)
{
	
}