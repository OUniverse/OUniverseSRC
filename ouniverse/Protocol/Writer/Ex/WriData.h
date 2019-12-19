//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the MainMenu.
 */

#pragma once

#include "Interface/Array.h"
#include "Interface/String.h"

class AtlasC;
class AtlasLibC;

struct AtlasDataStorageS
{
public:

	AtlasDataStorageS() {};
	AtlasDataStorageS(AtlasC* InAtlas);

	StringC ID;
	StringC Name;
	StringC Author;
	StringC Website;
	StringC Socket;
};


class OUNIVERSE_API WriDataC
{

public: 

	WriDataC(AtlasLibC* InAtlasLib);

	bool LoadoutLocked_;
	AtlasLibC* AtlasLib_;

	AtlasC* MasterAtlas_;
	ArrayC<AtlasC*> Loadout_;
	
	AtlasDataStorageS AtlasStorage_;

	void SetMaster(AtlasC* InMaster);

	void Mount();
	void Dismount();

	void LoadMaster();
	void UnloadMaster();

};