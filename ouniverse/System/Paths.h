//Copyright 2015-2019, All Rights Reserved.

/**
PathManager is a Singleton extension to MAJOR (GameInstance) and manages directories.

Precomputes paths so they only need to be string assembled once.
 */

#pragma once

#include "CoreMinimal.h"


#define FOLDER_PRIMARY "maj"
#define FOLDER_SECONDARY "min"


#define USER_STANDARD_FILEPREFIX "_"

#define FOLDER_OUNIVERSE "OUniverse"
#define FOLDER_DOC_THISOUNIV "OUniverse I"
#define FOLDER_USER_THISOUNIV "ou"
#define FOLDER_USER_PLAYTHROUGH "p"
#define FOLDER_USER_SETTINGS "p"
#define FOLDER_USER_DATA "d"
#define FOLDER_CONFIG "Config"
#define FOLDER_LOGS "Logs"
#define FOLDER_USERS "Users"
#define FOLDER_CACHE "Cache"

#define EXT_SETTINGS ".ocfg"
#define EXT_REG ".oreg"
#define EXT_USER ".ouser"
#define EXT_PLAYTHROUGH ".oplay"

#define REG_I_SYSMENU_OVERLAY "i_sysmenu_overlays"+EXT_REG
#define REG_INPUTMANAGER "inputmanager_commands"+EXT_REG

#define ALERTLEVEL_REG 2




class OUNIVERSE_API PathsC
{

private:

	PathsC();

public:

	static PathsC* Create();

	FString Documents();

	FString AppData();

	FString Logs();

	FString Users();

	FString AppDataConfig();

	FString AppDataCache();

	FString Content();

	FString Reg();

	FString UiServer();

	FString UiReg();

private:

	
	


	FString Documents_;
	FString AppData_;
	FString Logs_;
	FString Users_;
	FString AppDataConfig_;
	FString AppDataCache_;
	FString Content_;
	FString Reg_;
	FString UiServer_;
	FString UiReg_;


};