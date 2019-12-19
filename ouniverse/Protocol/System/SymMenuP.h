//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/Protocol.h"
#include "System/Input.h"


class SystemPro;

class USymMenu;

class FluxSwitchOpC;
class FocusUiRackC;


class OUNIVERSE_API SymMenuP : public ProtocolC, public InputC
{

public: 

	SymMenuP(int InID, SystemPro* InPro);

	USymMenu* View_;

	SystemPro* Pro_;

	void FluxOpen_Technical(FluxSwitchOpC* InOp) override;
	void FluxClose_Technical(FluxSwitchOpC* InOp) override;

	void ConstructUi(USymMenu* InView);

	bool InputCommand(KeyS InKey) override;

	static enum Focus {
		FDock,
		FRack,
		FRackNewGame,
		FRackContinue,
		FRackUser,
		FRackLoadout,
		FRackTrophey,
		FRackSettings,
		FRackUpdate,
		FRackCredits,
		FRackScribe,
		FRackNews,
		FOCUS_MAX,
	};

	FocusUiRackC* ORack_;

	void AcceptUser();
	void AcceptWriter();

};