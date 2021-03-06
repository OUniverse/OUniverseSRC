//Copyright 2015-2019, All Rights Reserved.

/**

## SaveFolder

A Save Folder is a marshalling of the results of scanning a folder in the Save directory.

**Creator:** SaveLib
**Holder:** SaveLib

 */

#pragma once

#include "Interface/Array.h"
#include "Interface/String.h"
#include "Interface/Url.h"
#include "Interface/Event.h"

#include "System/SaveUID.h"

class OUNIVERSE_API SaveC
{

public:	    

		SaveC(FileC InFile);
		
		static SaveC* Create(FileC InFile);

		bool IsValid();

		SaveUID UID();

		StringC Name_;

		StringC Glyph_;

		void Mount();

		void Dismount();

		FileC File();

private:

		SaveUID UID_;

		FileC File_;

		bool Valid_;
	
};

class OUNIVERSE_API SaveW
{

public:

	SaveW();

	void Set(SaveC* InSave);

	SaveC* Get();
	
	Event1C<EventLife,SaveC*> E_Set;

private:

	SaveC* Save_;
};