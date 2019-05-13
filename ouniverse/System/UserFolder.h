//Copyright 2015-2019, All Rights Reserved.

/**
A User represents the person that is playing. 

OUniverse supports multiple for the following situations:
- Multiple people playing on the same game.
- Multiple playthroughs and experimentation.

The USER class is created by the UserManager after it parses the User Directory and pulls dated documents.
Each user found is given a USER object.

- Unpacks JSON data and fills out a few special variables.
- Validates itself.
- Allows for editing and saving.

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

		DirS* UserDir;

		bool IsValid();

		int GetUID();

		int UID_;

		UserC* Promote();

private:
			

		bool Valid_;

		DeclarationU* Declaration_;

		
};