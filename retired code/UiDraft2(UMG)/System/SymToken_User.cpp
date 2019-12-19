//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymToken_User.h"
#include "System/User.h"
#include "Components/TextBlock.h"


void  USYM_MainTokenUser::NativeConstruct()
{
	Super::NativeConstruct();
}

void USYM_MainTokenUser::SetUser(UserC* InUser)
{
	V_ID->SetText(InUser->ID().ToFText());
	V_Score->SetText(StringC(InUser->Score()).ToFText());
	
}