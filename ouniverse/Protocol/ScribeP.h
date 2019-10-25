//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "Protocol/Protocol.h"

#include "Interface/Int.h"
#include "Interface/Json.h"

#include <vector>
#include <string>

#include "System/AtlasUID.h"
#include "System/FormUID.h"
#include "System/DuetUID.h"

class DataC;

class OUNIVERSE_API ScribeP 
{

	
	friend UMaestro;


public:

	void UI_AtlasiPreREQ();

	void UI_AtlasiMount(std::vector<int> AtlasiArr, bool ReqScribe);

	void UI_FormQUERY(std::string InQuery);

	void UI_FormREQ(int InAtlasUID, int InFormUID);

	void UI_FormSAVE(std::string InFormJ);

	void UI_AtlasDocSAVE(int InAtlasUID);

	void UpdateForm(DuetUID InUID, JsonS InJ);

	void UpdateAtlas(AtlasUID InAtlasUID, std::string AtlasJson);

	void SaveAtlasDoc(AtlasUID InAtlasUID);

private:

	DataC* Data_;

	ScribeP(DataC* InData);

	void Activate();

};