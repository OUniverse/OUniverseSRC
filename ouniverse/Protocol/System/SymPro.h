//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class UUi;
class UMajor;
class MaestroC;

class USymPro;

class SymPreP;
class SymMenuP;
class SymTokensP;
class SymUserMenuP;
class SymLoadoutMenuP;

class OUNIVERSE_API SystemPro : public ProtocolC, public InputStackC
{
	friend MaestroC;

public: 

	void OpenMenu();

	void GoUser();
	void GoLoadout();
	void GoWriter();

private:

	static SystemPro* Create(int InID, UMajor* InMajor);

	SystemPro(int InID, UMajor* InMajor);

	UMajor* Major_;
	MaestroC* Maestro_;
	UUi* Ui_;

	USymPro* View_;


	SymPreP* SymPre_;
	SymMenuP* SymMenu_;
	SymTokensP* SymTokens_;
	SymUserMenuP* SymUserMenu_;
	SymLoadoutMenuP* SymLoadoutMenu_;

	static enum Focus {
		FOCUS_MAX,
	};

	static enum Dock {
		DSym,
		DOCK_MAX,
	};
	
	static enum Page {
		PPre,
		PMenu,
		PUserMenu,
		PLoadoutMenu,
		PAGE_MAX,
	};

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;
};