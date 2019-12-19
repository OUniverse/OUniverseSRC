//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class USymUserMenu;
class SymUserSelectP;
class SymUserCreateP;
class SymUserEditP;

class FocusDockC;
class FocusUiRackC;

class SystemPro;
class UUi;
class UserLibC;

class OUNIVERSE_API SymUserMenuP : public ProtocolC, public InputC
{

public: 

	SymUserMenuP(int InID, SystemPro* InSystem, UUi* InUI, UserLibC* InUserLib);

	USymUserMenu* View_;

	SystemPro* System_;
	UUi* Ui_;
	UserLibC* UserLib_;


	SymUserSelectP* SymUserSelect_;
	SymUserCreateP* SymUserCreate_;
	SymUserEditP* SymUserEdit_;

	void ConstructUi(USymUserMenu* InView);

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void FocusChanged(int InID) override;

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FDock,
		FRack,
		FRackNew,
		FRackSelect,
		FRackEdit,
		FRackBack,
		FOCUS_MAX,
	};


	static enum Dock {
		DUser,
	};


	static enum Flux {
		VCreate,
		VSelect,
		VEdit,
	};

	FocusDockC* ODock_;
	FocusUiRackC* ORack_;

	void AcceptCreate();
	void AcceptSelect();
	void AcceptEdit();
	void AcceptBack();

	void DockEscape();
};