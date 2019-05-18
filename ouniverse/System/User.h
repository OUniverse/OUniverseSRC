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
class UserDeleteC;
class DeclarationK;

class OUNIVERSE_API UserC
{

public:	    
		UserC(DirS* InUserDir, StringC InFolderName);
		
		static UserC* Create(DirS* InUserDir, StringC InFolderName);

		bool IsValid();

		int GetUID();

		int UID_;

		void Promote();

		void Demote();

		StringC GetPath();

		DeclarationK* GetDeclaration();

private:
			
		StringC Path_;

		bool Valid_;

		DeclarationK* Declaration_;

		
};