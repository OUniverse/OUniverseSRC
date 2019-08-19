//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"

class AtlasC;
class LoadoutC;
class CreditLibC;

class AtlasLibC
{

public:

	AtlasLibC(StringC InPath);

	AtlasC* operator[](U64 InValue);

	AtlasC* At(int Index);

	int PreLen();

	int Len();

	bool Try(U64 InUID, AtlasC* Out);

	void Reset();

	void Mount(LoadoutC* InLoadout);

	void Mount(ArrayC<U64> InUIDArr);

	void AddAtlas(AtlasC* NewAtlas);

	void AddPreAtlas(AtlasC* NewAtlas);

	ArrayC<AtlasC*> GetAtlasPreArray();

private:

	StringC Path_;

	int PreLen_;

	int Len_;
	
	MapC<U64, AtlasC*> PreLib_;

	MapC<U64, AtlasC*> Lib_;

	CreditLibC* CreditLib_;

};