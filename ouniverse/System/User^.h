//Copyright 2015-2019, All Rights Reserved.

/**

## UserFolder

A User Folder is a marshalling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

 */

#pragma once

#include "System/User.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"

void CoherentBind(cohtml::Binder* binder, UserC* User)
{
	if (auto type = binder->RegisterType("User", User))
	{
		type.Property("uid", &UserC::UID_);
	}
}