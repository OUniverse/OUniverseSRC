//Copyright 2015-2019, All Rights Reserved.

/**

## UserFolder

A User Folder is a marshalling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

 */

#pragma once

#include "Interface/Json.h"

class UserC;


class OUNIVERSE_API UserDaisC
{

public:

	UserDaisC();

	void Set(UserC* InUser);

	UserC* Get();

	JsonS UiStatus();

private:

	UserC* User_;

};