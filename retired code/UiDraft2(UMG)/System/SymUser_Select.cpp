//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymUser_Select.h"
#include "Ui/System/SYM_UserSelect_Le.h"


#include "Ui/UiScroll.h"
#include "System/UserLib.h"


void USYM_UserSelect::Init(UUiView* InParentView, UserLibC* InUserLib)
{
	ConstructView(InParentView);
	UserLib_ = InUserLib;

	int L = UserLib_->Num();

	V_Scroll->Init(Interfaces::Scroll, this);
	V_Scroll->PathLeft.Define(UiPathS::Types::Move, 0);
	V_Scroll->PathRight.Define(UiPathS::Types::Move, 0);
	V_Scroll->PathCancel.Define(UiPathS::Types::Cancel, 0);

	for (int i = 0; i < L; i++)
	{
		USYM_UserSelect_Le* Entry = USYM_UserSelect_Le::Create(this, UserLib_->GetUser(i));
		V_Scroll->AddEntry(Entry);
	}

	V_Scroll->Build();
	OwningView_->ControlRelay(this);
	InterfacesInit(Interfaces::MAX);
	InterfacesAdd(Interfaces::Scroll, V_Scroll);
	InterfacesActivate(Interfaces::Scroll);

}

void USYM_UserSelect::UserSelected(UserC* InUser)
{
	UserLib_->Set(InUser);
	//USYM* CastedAlpha = static_cast<SymC*>(Shell())->Alpha();
	//CastedAlpha->UserSelected();
}