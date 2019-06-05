//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"

class WorldD;
class AtlasC;
class PayloadC;

class AtlasFullC
{
	
public:

	AtlasFullC(AtlasC* InAtlas);

	MapC<int, WorldD*>WorldDocs;

private:

	AtlasC* Atlas_;
};

class AtlasC
{
	static const char* EXT;

	friend PayloadC;


public: 

	StringC Path();

	bool Valid();
	int UID();

private:

	AtlasC(StringC InPath);

	struct DetailsS
	{
		int ID;
		StringC Name;
		StringC Author;
		StringC Description;
		StringC Website;
		StringC Icon;
		StringC Date;

		DetailsS() {};
		DetailsS(const char* JSerialized);
	};

	int UID_;
	bool Valid_;

	StringC Path_;

	DetailsS Details_;

	void Promote();
	bool Header();

	AtlasFullC* Full_;
};