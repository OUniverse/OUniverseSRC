//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Console/ConTray.h"
#include "System/Class.h"
#include "System/Scope.h"

void UConTray::NativeConstruct()
{
	Super::NativeConstruct();

}


UConTray* UConTray::Create(ConsolePro* InPro)
{
	UConTray* Neu = CreateWidget<UConTray>(ScopeC::World(), ClassC::ConTray());
	Neu->Init(InPro);
	return Neu;
}

void UConTray::Init(ConsolePro* InPro)
{
	ConstructAlpha();
}