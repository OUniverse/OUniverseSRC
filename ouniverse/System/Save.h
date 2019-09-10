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

		static const char* K_NAME;
		static const char* K_GLYPH;
		static const char* K_AWARDS;

		SaveC(FolderC InFolder, StringC InFolderName);
		
		static SaveC* Create(FolderC InFolder, StringC InFolderName);

		bool IsValid();

		SaveUID UID();

		StringC Name_;

		StringC Glyph_;

		void Mount();

		void Dismount();

		FolderC Folder();

private:

		SaveUID UID_;

		FolderC Folder_;
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