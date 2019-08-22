//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "Protocol/ProtocolP.h"

#include "Interface/Int.h"
#include "Interface/Json.h"

#include <vector>
#include <string>

#include "System/AtlasUID.h"
#include "System/FormUID.h"
#include "System/DuetUID.h"

class DataC;

class OUNIVERSE_API ScribeP : public ProtocolP
{

	
	friend ProtocolManager;


public:

	void ReqAtlasPre();

	void LoadAtlasi(std::vector<int> AtlasiArr, bool ReqScribe);

	void FormQuery(std::string InQuery);

	void FormREQ(int InAtlasUID, int InFormUID);

	void FormSAVE(std::string InFormJ);

	void AtlasDocSAVE(int InAtlasUID);

	void UpdateForm(DuetUID InUID, JsonS InJ);

	void UpdateAtlas(AtlasUID InAtlasUID, std::string AtlasJson);

	void SaveAtlasDoc(AtlasUID InAtlasUID);

private:

	DataC* Data_;

	ScribeP(DataC* InData);

	virtual void Activate() override;

};