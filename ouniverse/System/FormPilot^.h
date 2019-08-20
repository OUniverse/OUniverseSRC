//Copyright 2015-2019, All Rights Reserved.

/**

## UserFolder

A User Folder is a marshalling of the results of scanning a folder in the user directory.

**Creator:** UserLib
**Holder:** UserLib

 */

#pragma once

#include "System/FormPilot.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"
#include <cohtml\Binding\String.h>


void CoherentBind(cohtml::Binder* binder, FormPilotS* FormPilot)
{
	/** I struggled binding StringC this way and found the lower binding format much clearer
	if (auto type = binder->RegisterType("User", User))
	{
		type.Property("uid", &UserC::UID_);
	}
	*/

	binder->MapBegin(4);
	CoherentBindInternal(binder, "auid");
	CoherentBindInternal(binder, FormPilot->AtlasUID().ToStd());
	CoherentBindInternal(binder, "uid");
	CoherentBindInternal(binder, FormPilot->UID().Ref());
	CoherentBindInternal(binder, "id");
	CoherentBindInternal(binder, FormPilot->ID().ToChar());
	CoherentBindInternal(binder, "ty");
	CoherentBindInternal(binder, FormPilot->Type());

	binder->MapEnd();
}