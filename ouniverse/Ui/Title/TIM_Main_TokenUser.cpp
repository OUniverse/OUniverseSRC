//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Title/TIM_Main_TokenUser.h"
#include "System/User.h"
#include "Components/TextBlock.h"


void  UTIM_VMainTokenUser::NativeConstruct()
{
	Super::NativeConstruct();
}

void UTIM_VMainTokenUser::SetUser(UserC* InUser)
{
	V_ID->SetText(InUser->ID().ToFText());
	V_Score->SetText(StringC(InUser->Score()).ToFText());
	
}