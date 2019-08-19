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

	void FormQuery(std::string Query);

	void LoadAtlasi(std::vector<std::string> AtlasiSelection, bool ReqScribe);

private:

	DataC* Data_;

	ScribeP(DataC* InData);

	virtual void Activate() override;

};