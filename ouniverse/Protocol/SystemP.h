//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Protocol/ProtocolP.h"

#include <string>

class UserLibC;
class LoadoutLibC;
class MaestroC;
class OniManagerC;

struct JsonS;

class OUNIVERSE_API SystemP : public ProtocolP
{
	friend MaestroC;

public:


private:

	bool FirstOpen_;

	UserLibC* UserL_;
	LoadoutLibC* LoadoutL_;
	MaestroC* Maestro_;
	OniManagerC* Oni_;

	SystemP(MaestroC* InMaestro, UserLibC* InUserLib, LoadoutLibC* InLoadoutLib, OniManagerC* InOniManager);

	virtual void Activate() override;


	void ACT_UserSelected(int uid);
	
	void REQ_PreUsers();

	void REQ_User(int uid);

	void REQ_UserConfig(int uid);

	void SAVE_User(std::string Dat);

	void CREATE_User();

	void REQ_Loadouts();

};