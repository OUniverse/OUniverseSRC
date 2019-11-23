//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"
#include "Interface/Url.h"
#include "Interface/Json.h"

#include "System/FormQuery.h"

#include "System/AtlasUID.h"
#include "System/DuetUID.h"

class AtlasC;
class UAtlas;
class LoadoutC;
class LoadoutDaisC;
class FormF;

class AtlasLibC
{

public:

	static AtlasLibC* Create(FolderC InFolder, LoadoutDaisC* InLoadoutDais);
	
	static AtlasLibC* Get();

	AtlasLibC(FolderC InFolder, LoadoutDaisC* InLoadoutDais);

	AtlasC* GetAtlas(AtlasUID InValue);

	AtlasC* At(int Index);

	int PreLen();

	int Len();

	bool Try(AtlasUID InUID, AtlasC*& Out);

	void Reset();

	void MountFromLoadout();

	void MountFromWriter(ArrayC<AtlasC*>* AtlasUIDs);

	void Dismount();

	void AddAtlas(AtlasC* NewAtlas);

	void AddPreAtlas(AtlasC* NewAtlas);

	MapC<AtlasUID, AtlasC*>* GetAtlasPreMap();

	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(DuetUID InDuet);

	bool TryForm(DuetUID DUID, FormF*& InForm, int& Error);

	void UpdateForm(DuetUID InDuet, JsonS& FormJ);

	void UpdateAtlas(AtlasUID InAtlasUID, JsonS& AtlasJ);

	void SaveAtlasDoc(AtlasUID InAtlasUID);

private:

	FolderC AtlasFolder_;

	int PreLen_;

	int Len_;
	
	MapC<AtlasUID, AtlasC*> PreLib_;

	MapC<AtlasUID, AtlasC*> Lib_;

	LoadoutDaisC* LoadoutDais_;
};