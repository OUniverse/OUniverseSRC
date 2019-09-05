//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"

#include <string>

class UserLibC;
class ProtocolManager;
class OniManagerC;

class OUNIVERSE_API SystemP : public ProtocolP
{
	friend ProtocolManager;

public:


private:

	bool FirstOpen_;

	UserLibC* UserL_;
	ProtocolManager* Maestro_;
	OniManagerC* Oni_;

	SystemP(ProtocolManager* InMaestro, UserLibC* InUserLib, OniManagerC* InOniManager);

	virtual void Activate() override;

	void REQ_PreUsers();

	void REQ_User(int uid);

	void REQ_UserConfig(int uid);

	void SAVE_User(std::string Dat);

	void CREATE_User();



};