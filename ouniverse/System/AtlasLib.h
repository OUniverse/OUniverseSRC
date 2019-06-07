//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"


class AtlasC;
class LoadoutC;

class AtlasLibC
{

public:

	AtlasLibC(StringC InPath);

	AtlasC* operator[](U64 InValue);

	AtlasC* At(int Index);

	void Add(U64 InUID, AtlasC* InAtlas);

	int Len();

	bool Try(U64 InUID, AtlasC* Out);

	void Reset();

	void Promote(LoadoutC* InLoadout);

private:

	StringC Path_;

	int Len_;
	
	MapC<U64, AtlasC*> Lib_;

};