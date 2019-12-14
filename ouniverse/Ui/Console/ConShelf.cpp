//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Console/ConShelf.h"
#include "System/Class.h"
#include "System/Scope.h"
#include "System/Major.h"

#include "Ui/UiButton.h"
#include "Ui/Console/ConShelfREG.h"
#include "Ui/Console/ConShelf_Log.h"
#include "Ui/Console/ConShelf_Output.h"

void UConShelf::NativeConstruct()
{
	Super::NativeConstruct();

	AddViewPanel(ConShelfREG::Docks::DShelf);

	Opt_Output->SetupButton(0,this);
	Opt_Log->SetupButton(1, this);

	View_Log->Init(this, Major_->Logger());
	AddView(ConShelfREG::Docks::DShelf, ConShelfREG::Views::VLog, View_Log);

	View_Output->Init(this);
	AddView(ConShelfREG::Docks::DShelf, ConShelfREG::Views::VOutput, View_Output);

	SwitchView(ConShelfREG::Docks::DShelf,ConShelfREG::Views::VLog);


}


UConShelf* UConShelf::Create(ConsolePro* InPro, UMajor* InMajor)
{
	UConShelf* Neu = CreateWidget<UConShelf>(ScopeC::World(), ClassC::ConShelf());
	Neu->Init(InPro, InMajor);
	return Neu;
}

void UConShelf::Init(ConsolePro* InPro, UMajor* InMajor)
{
	Major_ = InMajor;
	ConstructAlpha();
}