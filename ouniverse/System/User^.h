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
	/** I struggled binding StringC this way and found the lower binding format much clearer
	if (auto type = binder->RegisterType("User", User))
	{
		type.Property("uid", &UserC::UID_);
	}
	*/

	binder->MapBegin(3);

	CoherentBindInternal(binder, "uid");
	CoherentBindInternal(binder, User->UID().ForUI());
	CoherentBindInternal(binder, "id");
	CoherentBindInternal(binder, User->ID_.ToChar());
	CoherentBindInternal(binder, "glyph");
	CoherentBindInternal(binder, User->Glyph_.ForUI());
	binder->MapEnd();
}