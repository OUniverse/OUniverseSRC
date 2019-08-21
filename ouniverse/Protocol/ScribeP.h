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

class DataC;

class OUNIVERSE_API ScribeP : public ProtocolP
{

	
	friend ProtocolManager;


public:

	void ReqAtlasPre();

	void LoadAtlasi(std::vector<std::string> AtlasiSelection, bool ReqScribe);

	void FormQuery(std::string InQuery);

	void FormREQ(std::string InAtlasUID, int InUID);

	void FormSAVE(std::string InFormJ);

	void AtlasDocSAVE(std::string InAtlasUID);

	void UpdateForm(U64 InAtlasUID, U32 InUID, JsonS InJ);

	void UpdateAtlas(std::string InAtlasUID, std::string AtlasJson);

	void SaveAtlasDoc(U64 InAtlasUID);

private:

	DataC* Data_;

	ScribeP(DataC* InData);

	virtual void Activate() override;

};