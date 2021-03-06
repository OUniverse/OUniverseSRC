//Copyright 2015-2019, All Rights Reserved.

/**
IO (InterfaceObject)
MainMenu - User
 */

#pragma once

#include "Ui/SystemMenu/IoSM.h"
#include "CoreMinimal.h"

class ConfigManager;
class UserLibC;

class OUNIVERSE_API UserISM : public IoSM
{
	friend SystemMenuIO;

private:

	enum Modes : uint8
	{
		Select,
		Create,
		Edit,
	};

	UserISM(GlassC* InGlass, SystemMenuIO* InSymu, UserLibC* InUser, ConfigManager* InConfig);

	bool bOpen;
	bool bSentUsers;

	UserLibC* UserP;
	ConfigManager* ConfigP;
	Modes Mode;
	void King() override;
	void Open(Modes NewMode);
	void OnActiveUserChanged();
	void OnUserSelected(int UserSN);
	void OnUserAdded();
	void OnUserEdited();
	void OnUserDeleted();

	void Activate() override;
};