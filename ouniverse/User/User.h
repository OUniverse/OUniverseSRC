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


#include "Interface/String.h"
#include "Interface/Array.h"
#include "User/UserFileU.h"

class DeclarationU;
class UserFileU;

class UserC
{
public:

	UserC(DeclarationU* InDeclaration);

	void Demote() {};
	
private:

	DeclarationU* Declaration_;
	ArrayC<UserFileU*> Files;

};