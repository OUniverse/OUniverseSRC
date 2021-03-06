//Copyright 2015-2019, All Rights Reserved.

/**

## UserFolder

A User Folder is a marshalling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

 */

#pragma once

#include "Interface/Json.h"
#include "Interface/Url.h"

class UserC;
class OniManagerC;
class LoadoutLibC;

class OUNIVERSE_API UserDaisC
{

public:

	UserDaisC(OniManagerC* InOni);

	void Initialize(LoadoutLibC* InLoadoutLib);

	void Set(UserC* InUser);

	UserC* Get();

	JsonS UiStatus();

	int IntUID();

	FolderC Folder();

private:

	UserC* User_;

	OniManagerC* Oni_;

	LoadoutLibC* LoadoutLib_;

};