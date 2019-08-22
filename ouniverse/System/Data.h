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

#include "System/FormQuery.h"

#include "System/ProgramState.h"

#include "System/AtlasUID.h"
#include "System/FormUID.h"
#include "System/DuetUID.h"

class UBoot;
class AtlasLibC;
class AtlasC;
struct FormPilotS;

class OUNIVERSE_API DataC
{
	friend UBoot;

private:

	static DataC* Create(ProgramStateC::State InState, StringC InPath);
	
	DataC(ProgramStateC::State InState, StringC InPath);
	
	StringC Path_;

	AtlasLibC* AtlasLib_;

	ProgramStateC::State State_;

public:

	static DataC* Get();

	DataC();

	AtlasLibC* GetAtlasLib();

	ArrayC<AtlasC*> GetAtlasPreArray();

	void Query(FormQueryS* InQuery);

	FormWrapS GetFormWrap(DuetUID InDuet);

	void UpdateForm(DuetUID InDuet, JsonS& FormJ);

	void UpdateAtlas(AtlasUID InAtlasUID, JsonS& AtlasJ);

	void SaveAtlasDoc(AtlasUID InAtlasUID);

	//void Reset(LoadoutC* InLoadout);
	//void Evolve(CosmosC* InLoadout);
};
