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
class UserC;
class DeclarationU;

class OUNIVERSE_API UserFolderC
{

public:	    
		UserFolderC(DirS* InUserDir, StringC InFolderName);
		
		static UserFolderC* Create(DirS* InUserDir, StringC InFolderName);

		bool IsValid();

		int GetUID();

		int UID_;

		UserC* Promote();

private:
			
		StringC Path_;

		bool Valid_;

		DeclarationU* Declaration_;

		
};