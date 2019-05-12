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
#define FOLDER_CONFIG "Config"
#define FOLDER_USERS "Users"
#define FOLDER_CACHE "Cache"

#define EXT_SETTINGS ".ocfg"
#define EXT_REG ".oreg"
#define EXT_USER ".ouser"
#define EXT_PLAYTHROUGH ".oplay"

#define REG_I_SYSMENU_OVERLAY "i_sysmenu_overlays"+EXT_REG
#define REG_INPUTMANAGER "inputmanager_commands"+EXT_REG

#define ALERTLEVEL_REG 2


struct DirS;

class OUNIVERSE_API PathsC
{

private:

	PathsC();

public:

	static PathsC* Create();

	DirS* Doc();

	DirS* App();

	DirS* Logs();

	DirS* Config();

	DirS* Users();

	DirS* ActiveUser();

	DirS* AppConfig();

	DirS* AppCache();

	DirS* Content();

	DirS* Reg();

	DirS* UiServer();

	DirS* UiReg();

private:

	DirS* Doc_;
	DirS* App_;
	DirS* Logs_;
	DirS* Config_;
	DirS* Users_;
	DirS* ActiveUser_;
	DirS* AppConfig_;
	DirS* AppCache_;
	DirS* Content_;
	DirS* Reg_;
	DirS* UiServer_;
	DirS* UiReg_;

};