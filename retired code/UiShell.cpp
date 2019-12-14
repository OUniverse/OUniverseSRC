//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiShell.h"
#include "Ui/UiAlpha.h"


UiShellC::UiShellC(int InID, ProtocolC* InProtocol)
{
	ID_ = InID;
	AbstractProtocol_ = InProtocol;
}


void UiShellC::Deactivate()
{
	Alpha()->RemoveFromParent();
}

int UiShellC::ID()
{
	return ID_;
}

UUiAlpha* UiShellC::Alpha()
{
	return Alpha_;

}

void UiShellC::SetAlpha(UUiAlpha* InAlpha)
{
	Alpha_ = InAlpha;
}