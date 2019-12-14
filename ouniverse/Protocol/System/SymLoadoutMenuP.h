//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "Protocol/Flux.h"
#include "System/Input.h"


class USymLoadoutMenu;
class SymLoadoutSelectP;
class SymLoadoutCreateP;
class SymLoadoutEditP;

class FocusDockC;
class FocusUiRackC;

class SystemPro;
class UUi;
class LoadoutLibC;

class OUNIVERSE_API SymLoadoutMenuP : public ProtocolC, public InputC
{

public: 

	SymLoadoutMenuP(int InID, SystemPro* InSystem, UUi* InUI, LoadoutLibC* InLoadoutLib);


	SystemPro* System_;
	UUi* Ui_;
	LoadoutLibC* LoadoutLib_;

	SymLoadoutSelectP* SymLoadoutSelect_;
	SymLoadoutCreateP* SymLoadoutCreate_;
	SymLoadoutEditP* SymLoadoutEdit_;


	void ConstructUi(USymLoadoutMenu* InView);
	
	USymLoadoutMenu* View_;

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
		DLoadout,
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