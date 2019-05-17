//Copyright 2015-2019, All Rights Reserved.

/**
WorldManager is a Singleton extension to MAJOR (GameInstance) and manages all loaded 3D data.

This is a massive section and needs to be further subdivided:
World Manager has to handle weather / region and time calculations as well as NPC locations.
As a result of this world manager will be split up into a few levels to separate the streaming of levels
from none 3D tasks like managing the populace and what characters should be existing in what areas.
 */

#pragma once

class UBoot;

class OUNIVERSE_API TerraC
{
	friend UBoot;

private:

	static TerraC* Create();

public:

	static TerraC* Get();
	TerraC();

};