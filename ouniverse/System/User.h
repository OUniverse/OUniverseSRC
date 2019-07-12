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

struct DirS;
class UserFileC;
class DeclarationK;

class OUNIVERSE_API UserC
{

	static const char* FOLDER_PREFIX;
	static const char* FILE_NAME;

public:	    
		UserC(DirS* InUserDir, StringC InFolderName);
		
		static UserC* Create(DirS* InUserDir, StringC InFolderName);

		bool IsValid();

		int UID();

		int UID_;

		StringC Name_;

		StringC Glyph_;

		void Promote();

		void Demote();

		StringC GetPath();

		UserFileC* UserFile_;

private:

		StringC Path_;

		bool Valid_;

		
		
};