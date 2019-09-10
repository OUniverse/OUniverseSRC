//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"
#include "Interface/Url.h"

#include "System/FormQuery.h"

#include "System/AtlasUID.h"

class AtlasC;
class LoadoutC;

class AtlasLibC
{

public:

	AtlasLibC(FolderC InFolder);

	AtlasC* Get(AtlasUID InValue);

	AtlasC* At(int Index);

	int PreLen();

	int Len();

	bool Try(AtlasUID InUID, AtlasC* Out);

	void Reset();

	void Mount(LoadoutC* InLoadout);

	void Mount(ArrayC<AtlasUID> InUIDArr);

	void AddAtlas(AtlasC* NewAtlas);

	void AddPreAtlas(AtlasC* NewAtlas);

	ArrayC<AtlasC*> GetAtlasPreArray();

	void Query(FormQueryS* InQuery);


private:

	FolderC AtlasFolder_;

	int PreLen_;

	int Len_;
	
	MapC<AtlasUID, AtlasC*> PreLib_;

	MapC<AtlasUID, AtlasC*> Lib_;

};