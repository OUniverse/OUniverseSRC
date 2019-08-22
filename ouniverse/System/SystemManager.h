//Copyright 2015-2019, All Rights Reserved.

/**

## SystemManager

> **Singleton Service: Created once only by the boot process.**

The SystemManager is a service singleton which scans devices and gathers knowledge it needs for performance of the user's system.
This data is held onto for the lifetime so it only needs to be recorded once at startup.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

extern class BootC;


class OUNIVERSE_API SystemManager
{

	friend BootC;

private:

	SystemManager();
	static SystemManager* Create();

};
