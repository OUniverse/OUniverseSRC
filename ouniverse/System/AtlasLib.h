//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"


class AtlasC;
class LoadoutC;
class CreditLibC;
class CosmosC;

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

	void Evolve(CosmosC* InCosmos);

	void Promote(LoadoutC* InLoadout);

	void AddAtlas(AtlasC* NewAtlas);

	void AddPreAtlas(AtlasC* NewAtlas);

private:

	StringC Path_;

	int PreLen_;

	int Len_;
	
	MapC<U64, AtlasC*> PreLib_;

	MapC<U64, AtlasC*> Lib_;

	CreditLibC* CreditLib_;

};