//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Data/Doc.h"
#include "Form/FormF.h"

class WorldD : public DocD
{

public: 

	static StringC Extension();

	WorldD(AtlasC* InAtlas, StringC InFile);

	bool Valid();

	void Promote();

private:

	struct HeaderS
	{

	public:

		HeaderS() {};
		HeaderS(StringC InLine);

		bool Valid();

	private:

		bool Valid_;

	};


	HeaderS Header_;

	bool Valid_;
	bool Promoted_;

};