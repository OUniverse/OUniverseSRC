//Copyright 2015-2019, All Rights Reserved.

/**
The GraphicsManager is a Singleton extension to MAJOR and manages global graphics settings.
 */

#pragma once

extern class UBoot;


class OUNIVERSE_API SystemManager
{

	friend UBoot;

private:

	SystemManager();
	static SystemManager* Create();

};
