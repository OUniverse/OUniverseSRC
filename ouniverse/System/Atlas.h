//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"
#include "Interface/Json.h"
#include "Interface/Url.h"

#include "System/AtlasUID.h"

#include "System/FormQuery.h"
#include "CoreMinimal.h"

class AtlasLibC;
class UAtlas;

class DataD;
class PayloadC;

class FormLibC;
class RevisionLibC;
class AmendmentLibC;
class AtlasAccordLibC;

class UTexture2D;

class WriDataC;
class FormDataC;

enum AtlasLibC::DataMode;

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
	friend WriDataC;

public: 


	static enum GFXSize {
		Large,
		Medium,
		Small,
	};

	FolderC Folder();

	bool Valid();
	
	bool Try(FormUID UID, DataD*& InForm);

	bool Mount(AtlasLibC* InAtlasLib, int InDataMode);

	void Dismount();

	bool Mounted();

	void Demarshal();

	AtlasUID UID();	
	StringC ID();
	StringC Name();
	StringC Desc();
	StringC Author();
	StringC Website();
	StringC Date();
	StringC VerVis();
	int VerInc();
	int VerUpdate();
	StringC WebSocket();
	UTexture2D* GFXSmall();
	UTexture2D* GFXLargeLoad();

	bool DevFile_;

	//Uses the Atlas Lib to check if each requirement of this atlas exists
	bool CheckRequirements(AtlasLibC* InAtlasMap);

	void Survey(AtlasLibC* InAtlasMap);

	void Query(FormQueryS* InQuery);

	void QueryFormData(FormDataQueryC* InQuery);


	FormWrapS GetFormWrap(FormUID InForm);

	void UpdateForm(FormUID InUID, JsonS& InJ);

	void Update(JsonS InJ);

	void SaveDoc();

	JsonS ToJson();

private:



	AtlasC(StringC InFolderName, FolderC InFolder);
	
	~AtlasC();

	AtlasUID UID_;	
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
	UTexture2D* GFXSmall_;

	UTexture2D* GetGFX(AtlasC::GFXSize Size);

	bool Valid_;
	bool Mounted_;
	bool RequirementsChecked_;

	bool Requirements_;
	bool FoundLinksHard_;
	bool FoundLinksSoft_;
	bool FoundLinksPref_;

	FolderC Folder_;
	FileC AtlasFile_;

	AtlasAccordLibC* AccordsHard_;
	AtlasAccordLibC* AccordsSoft_;
	AtlasAccordLibC* AccordsPref_;

	FormLibC* FormLib_;
	AmendmentLibC* AmendmentLib_;
	RevisionLibC* RevisionLib_;
};