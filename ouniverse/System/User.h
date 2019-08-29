//Copyright 2015-2019, All Rights Reserved.

/**

## UserFolder

A User Folder is a marshalling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

 */

#pragma once

#include "Interface/Array.h"
#include "Interface/String.h"
#include "Interface/Url.h"

#include "System/UserUID.h"

class UserFileC;


class OUNIVERSE_API UserC
{

public:	    

		static const char* K_NAME;
		static const char* K_GLYPH;
		static const char* K_AWARDS;

		UserC(NewFolderC InFolder, StringC InFolderName);
		
		static UserC* Create(NewFolderC InFolder, StringC InFolderName);

		bool IsValid();

		UserUID UID();

		StringC Name_;

		StringC Glyph_;

		void Mount();

		void Demount();

		NewFolderC Folder();

private:

		UserUID UID_;

		NewFolderC Folder_;
		NewFileC File_;

		bool Valid_;
	
};