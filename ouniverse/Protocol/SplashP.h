//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "Protocol/ProtocolP.h"

#include "System/InputManager.h"
#include "System/Command.h"


class MajorC;
class ProtocolManager;
class InputManager;

class OUNIVERSE_API SplashP : public ProtocolP
{
	
	friend ProtocolManager;


public:

	enum Stage
	{
		Brander,
		Sponsor,
		Intro,
	};

	void OnClick();

	void Skip();

	Stage CurrentStage_;

	SplashP(ProtocolManager* InMaestro, InputManager* InInputManager);

	virtual void Activate() override;

	InputManager* Input_;

	ProtocolManager* Maestro_;

private:

	CommandEL CMD_Enter;

	void OnSkip(StrokeS InStroke);
};