//Copyright 2015-2019, All Rights Reserved.

#include "System/Ui.h"

namespace GlobalSingleton
{
	UiC Ui;
}

UiC* UiC::Get()
{
	return &GlobalSingleton::Ui;
}

UiC* UiC::Create()
{
	GlobalSingleton::Ui = *(new UiC());
	return &GlobalSingleton::Ui;
}

UiC::UiC()
{

}