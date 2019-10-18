//Copyright 2015-2019, All Rights Reserved.

/**

## Data
> **Singleton Service: Created once only by the boot process.**

Data is a singleton which loads all the atlas style game data.

#### Tasks
* Creates and triggers a PayloadC which unpacks the entire atlas folder.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"
#include "Interface/Json.h"
#include "Interface/Url.h"

#include "System/FormQuery.h"

#include "System/AtlasUID.h"
#include "System/FormUID.h"
#include "System/DuetUID.h"


class BootC;
class AtlasLibC;
class AtlasC;
class LoadoutC;
struct FormPilotS;

class OUNIVERSE_API DataC
{
	friend BootC;

private:

	static DataC* Create(FolderC InAtlasFolder);
	
	DataC(FolderC InAtlasFolder);
	
	FolderC AtlasFolder_;

	AtlasLibC* AtlasLib_;

public:

	static DataC* Get();

	DataC();

	AtlasLibC* GetAtlasLib();

	ArrayC<AtlasC*> GetAtlasPreArray();

	void Query(FormQueryS* InQuery);

	void Mount(LoadoutC* InLoadout);

	FormWrapS GetFormWrap(DuetUID InDuet);

	void UpdateForm(DuetUID InDuet, JsonS& FormJ);

	void UpdateAtlas(AtlasUID InAtlasUID, JsonS& AtlasJ);

	void SaveAtlasDoc(AtlasUID InAtlasUID);

	//void Reset(LoadoutC* InLoadout);
	//void Evolve(CosmosC* InLoadout);
};
