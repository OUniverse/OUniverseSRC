//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"

class FormF;
class PayloadC;
class FormLibC;
class AtlasLibC;
class CreditLibC;
class CosmosC;

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

	friend AtlasLibC;
	
public: 

	StringC Path();

	bool Valid();
	
	void Promote();

	void Demote();

	bool Promoted();

	void Evolve(CosmosC* InCosmos);

	void Devolve();

	bool Evolved();

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

	bool CheckRequirements(AtlasLibC* InAtlasMap);
	void Survey(AtlasLibC* InAtlasMap);

	void LinkBoost(AtlasLibC* InLib);

	void LinkExtra(AtlasLibC* InLib);

private:

	AtlasC(StringC InFolderName, StringC InPath);

	struct Link
	{

		Link();

		Link(U64 InUID);

		U64 UID();
		void Found();
		bool Exists();

	private:
		
		U64 UID_;
		bool Exists_;

	};
	
	U64 UID_;
	
	bool Valid_;
	bool Promoted_;
	bool RequirementsChecked_;
	bool Evolved_;

	bool Requirements_;
	bool FoundLinksHard_;
	bool FoundLinksSoft_;
	bool FoundLinksPref_;

	StringC Path_;
	
	ArrayC<AtlasC::Link> LinksHard;
	ArrayC<AtlasC::Link> LinksSoft;
	ArrayC<AtlasC::Link> LinksPref;

	FormLibC* FormLib_;

};