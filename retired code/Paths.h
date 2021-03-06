//Copyright 2015-2019, All Rights Reserved.

/**

## Paths

> **Singleton Service: Created once only by the boot process.**

A service singleton extension that precomputes and stores required directory paths through out the lifetime.

Tasks:
- Precomputes paths so they only need to be string assembled once.
- Generates pointer wrapers to directories so that changes to directory during lifetime are reflected in realtime without any monitoring or events.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "CoreMinimal.h"


#define FOLDER_PRIMARY "maj"
#define FOLDER_SECONDARY "min"


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

	static const char* UiServer;

	DirS* UiReg();

	DirS* Atlas();
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
	DirS* UiReg_;
	DirS* Atlas_;
};