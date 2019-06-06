//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"

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
	static const char* FILE_NAME;

	static const char* K_ID;
	static const char* K_NAME;
	static const char* K_ICON;
	static const char* K_DESC;
	static const char* K_AUTHOR;
	static const char* K_WEBSITE;
	static const char* K_DATE;
	static const char* K_VER;
	static const char* K_IVER;

	static const char* K_LINKS;
	static const char* K_LINKS_HARD;
	static const char* K_LINKS_SOFT;
	static const char* K_LINKS_PREF;

	static const char* K_FLAGS;
	friend PayloadC;


public: 

	StringC Path();

	bool Valid();
	
	void Promote();
	void Demote();

	bool Promoted();

	U64 UID();

	StringC ID_;
	StringC Name_;
	StringC Icon_;
	StringC Desc_;
	StringC Author_;
	StringC Website_ ;
	StringC Date_;
	StringC Ver_;
	int Inc_;

private:

	AtlasC(StringC InFolderName, StringC InFullPath);


	U64 UID_;
	bool Valid_;
	bool Promoted_;

	StringC Path_;

	bool Header();

	AtlasFullC* Full_;

	ArrayC<U64> LinksHard;
	ArrayC<U64> LinksSoft;
	ArrayC<U64> LinksPref;
};