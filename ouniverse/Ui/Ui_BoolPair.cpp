//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_BoolPair.h"

bool UUi_BoolPair::GetValue(EUi_BoolPairWhich InWhich)
{
	switch (InWhich)
	{
	case EUi_BoolPairWhich::Top: // code to be executed if n = 1;
		return Top;
		break;
	case EUi_BoolPairWhich::Bottom: // code to be executed if n = 2;
		return Bot;
		break;
	default:
		return false;
		break;
	}
}

void UUi_BoolPair::Toggle(EUi_BoolPairWhich InWhich)
{
	switch (InWhich)
	{
	case EUi_BoolPairWhich::Top:
		Top = !Top;
		ChangedTop();
		break;
	case EUi_BoolPairWhich::Bottom:
		Bot = !Bot;
		ChangedBot();
		break;
	}
}

void UUi_BoolPair::Set(EUi_BoolPairWhich InWhich, bool SetTo)
{
	switch (InWhich)
	{
	case EUi_BoolPairWhich::Top: 
		Top = SetTo;
		ChangedTop();
		break;
	case EUi_BoolPairWhich::Bottom:
		Bot = SetTo;
		ChangedBot();
		break;
	}
}