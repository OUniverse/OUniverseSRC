//Copyright 2015-2019, All Rights Reserved.

/**

## UserFolder

A User Folder is a marshalling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

 */

#pragma once

#include "CoreMinimal.h"
#include "Json.h"

#include "Interface/Array.h"
#include "Interface/String.h"

#include "System/UserUID.h"


struct DirS;
class UserFileC;
class DeclarationK;

class OUNIVERSE_API UserC
{
	static const char* FILE_NAME;

public:	    
		UserC(DirS* InUserDir, StringC InFolderName);
		
		static UserC* Create(DirS* InUserDir, StringC InFolderName);

		bool IsValid();

		UserUID UID();

		StringC Name_;

		StringC Glyph_;

		void Promote();

		void Demote();

		StringC GetPath();

		UserFileC* UserFile_;

private:

		UserUID UID_;

		StringC Path_;

		bool Valid_;
	
};