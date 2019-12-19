//Copyright 2015-2019, All Rights Reserved.

#include "Ui/System/SymUser.h"
#include "Ui/System/SymReg.h"

#include "Ui/UiButton.h"
#include "Ui/System/SymUser_Select.h"
#include "Ui/System/SymUser_Create.h"
#include "Ui/System/SymUser_Edit.h"

#include "Ui/UiEventCodes.h"


void USYM_User::Init(UUiView* InParentView, UserLibC* InUserLib, UserDaisC* InUserDais)
{
	ConstructView(InParentView);
	UserLib_ = InUserLib;
	UserDais_ = InUserDais;

	AddViewPanel(SYMREG::Docks::DUser);

	BT_Create->SetupButton(SYMREG::Interfaces::IUserCreate,this);
	BT_Select->SetupButton(SYMREG::Interfaces::IUserSelect,this);
	BT_Edit->SetupButton(SYMREG::Interfaces::IUserEdit,this);

	View_UserSelect->Init(this, UserLib_);
	AddView(SYMREG::Docks::DUser, SYMREG::Views::VUserSelect, View_UserSelect);
	View_UserCreate->Init(this, UserLib_);
	AddView(SYMREG::Docks::DUser, SYMREG::Views::VUserCreate, View_UserCreate);
	View_UserEdit->Init(this, UserDais_);
	AddView(SYMREG::Docks::DUser, SYMREG::Views::VUserEdit, View_UserEdit);
}

void USYM_User::ViewOpen_Technical()
{
	SwitchView(SYMREG::Docks::DUser, SYMREG::Views::VUserSelect);
}

void USYM_User::EventUi(int InWidgetID, int InEventID, UUserWidget* InWidget)
{

	switch (InEventID) {
	case UiEventCodesC::ButtonClick:
		switch (InWidgetID) {
		case SYMREG::Interfaces::IUserCreate:
			SwitchView(SYMREG::Docks::DUser, SYMREG::Views::VUserCreate);
			break;
		case SYMREG::Interfaces::IUserSelect:
			SwitchView(SYMREG::Docks::DUser, SYMREG::Views::VUserSelect);
			break;
		case SYMREG::Interfaces::IUserEdit:
			SwitchView(SYMREG::Docks::DUser, SYMREG::Views::VUserEdit);
			break;
		}
		break;
	}
}