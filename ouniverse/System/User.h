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

#include "System/Glyph.h"
#include "System/UserUID.h"


class OUNIVERSE_API UserC
{

private:

	static const int Provenance;

public:	    

		UserC();
		
		static UserC* Create(FolderC InFolder);

		void LoadMethod(StringC InFolderName);
		void CreateMethod(int InUID, StringC InID);

		void Save();

		bool IsValid();

		UserUID UID();

		StringC ID();

		int Score();

		StringC ID_;

		int Score_;

		GlyphC Glyph_;

		void Mount();

		void Dismount();

		FolderC Folder();

		StringC Combo_UID_ID();

private:

		UserUID UID_;

		FolderC Folder_;
		FileC File_;

		bool Valid_;
	
};