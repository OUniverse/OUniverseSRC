//Copyright 2015-2019, All Rights Reserved.

/**
Protocol for handling the UserSelection menus.
 */

#pragma once

#include "Protocol/ProtocolP.h"
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

	void UpdateForm(std::string InAtlasUID, int InUID, std::string FormJson);

	void UpdateAtlas(std::string InAtlasUID, std::string AtlasJson);

	void SaveAtlasDoc(std::string InAtlasUID);

private:

	DataC* Data_;

	ScribeP(DataC* InData);

	virtual void Activate() override;

};