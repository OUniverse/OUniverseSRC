//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"
#include "Interface/Json.h"

#include "System/FormQuery.h"

class AtlasLibC;

class FormF;
class PayloadC;

class FormLibC;
class RevisionLibC;
class AmendmentLibC;
class AtlasAccordLibC;

class AtlasC
{
	static const char* FILE_NAME;
	static const char* FILE_NAME_DEV;

	static const char* K_NAME;
	static const char* K_ICON;
	static const char* K_DESC;
	static const char* K_AUTHOR;
	static const char* K_WEBSITE;
	static const char* K_DATE;
	static const char* K_VER_VIS;
	static const char* K_VER_INC;
	static const char* K_VER_UPDATE;
	static const char* K_WEB_SOCKET;

	static const char* K_LINKS;
	static const char* K_LINKS_HARD;
	static const char* K_LINKS_SOFT;
	static const char* K_LINKS_PREF;

	static const char* K_FLAGS;

	friend AtlasLibC;
	
public: 

	StringC Path();

	bool Valid();
	
	bool Mount(AtlasLibC* InAtlasLib);

	void Dismount();

	bool Mounted();


	U64 UID();

	StringC ID_;
	StringC Name_;
	StringC Icon_;
	StringC Desc_;
	StringC Author_;
	StringC Website_;
	StringC Date_;	
	StringC VerVis_;
	int VerInc_;
	int VerUpdate_;
	StringC WebSocket_;

	bool DevFile_;

	//Uses the Atlas Lib to check if each requirement of this atlas exists
	bool CheckRequirements(AtlasLibC* InAtlasMap);

	void Survey(AtlasLibC* InAtlasMap);

	void LinkBoost(AtlasLibC* InLib);

	void LinkExtra(AtlasLibC* InLib);

	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(U32 InForm);

	void UpdateForm(U32 InUID, JsonS& InJ);

	void Update(JsonS InJ);

	void SaveDoc();

	JsonS ToJson();

private:

	AtlasC(StringC InFolderName, StringC InPath);
	
	~AtlasC();

	U64 UID_;
	
	bool Valid_;
	bool Mounted_;
	bool RequirementsChecked_;

	bool Requirements_;
	bool FoundLinksHard_;
	bool FoundLinksSoft_;
	bool FoundLinksPref_;

	StringC Path_;
	
	AtlasAccordLibC* AccordsHard_;
	AtlasAccordLibC* AccordsSoft_;
	AtlasAccordLibC* AccordsPref_;

	FormLibC* FormLib_;
	AmendmentLibC* AmendmentLib_;
	RevisionLibC* RevisionLib_;
};