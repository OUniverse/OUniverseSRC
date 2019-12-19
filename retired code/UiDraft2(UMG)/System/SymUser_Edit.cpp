//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymUser_Edit.h"


void USYM_UserEdit::Init(UUiView* InParentView, UserDaisC* InUserDais)
{
	ConstructView(InParentView);
	UserDais_ = InUserDais;
}