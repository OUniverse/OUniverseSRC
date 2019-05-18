//Copyright 2015-2019, All Rights Reserved.

/**
Boot is the procedeural process of setting up all of OUniverse's services and allowing them to load their data and set each other up.
It creates the Major singleton and adds all services to it.
The Major singleton is friended with Boot so that it can only be manipulated by the boot process.
	- Later I might friend it to a testing class so that custom data can be injected for testing.
Upon completing this task it hands things off to the ProtocolManager.


Boot works by calling the UBoot::Boot function from any level in UE4 blueprints.

 */

#pragma once

#include "System/Session.h"

#define SESSION SessionC::Get()