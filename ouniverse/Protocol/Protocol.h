//Copyright 2015-2019, All Rights Reserved.

/**
Each Protocol is a modes the game can be in. Examples of a mode would be the Title Screen vs InGame.
Protocols contain special logic for handling tasks of different isolated modes the game can be in.

You can think of a Protocol as OUniverse's own GameMode type. Since OUniverse streams everything into one base level
it doesn't have an opportunity to switch out the GameMode and instead uses Protocols which it can dynamicaly switch.

Protocols are loaded via the ProtocolManager class attached to the MAJOR singleton.

This is the abstract Protocol class which all actual Protocols extend from.
 */

#pragma once

#include "System/Input.h"
#include "Protocol/Flux.h"
#include "Protocol/Focal.h"
#include "Protocol/Ley.h"

class MaestroC;
class UUserWidget;
class InputC;

class OUNIVERSE_API ProtocolC : public FluxC, public FocalC
{

	friend MaestroC;

protected:

	ProtocolC(int InID, InputC* InInput);

	virtual ~ProtocolC() {};
	
public:

	InputC* Input_;

	virtual void EventCode(int ID, int EventID, int Var) {};

	virtual void FocusChanged(int ID) {};
	


	virtual void EventPro(int ID, int EventID, ProtocolC* Pro) {};
	virtual void EventUi(int ID, int EventID, UUserWidget* InWidget) {};
};