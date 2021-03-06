//Copyright 2015-2019, All Rights Reserved.

/**

## LoadoutFolder

A Loadout Folder is a marshalling of the results of scanning a folder in the Loadout directory.

**Creator:** LoadoutLib
**Holder:** LoadoutLib

 */

#pragma once

#include "System/Loadout.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"


void CoherentBind(cohtml::Binder* binder, LoadoutC* Loadout)
{
	/** I struggled binding StringC this way and found the lower binding format much clearer
	if (auto type = binder->RegisterType("Loadout", Loadout))
	{
		type.Property("uid", &LoadoutC::UID_);
	}
	*/

	binder->MapBegin(2);

	CoherentBindInternal(binder, "uid");
	CoherentBindInternal(binder, Loadout->UID().ForUI());
	CoherentBindInternal(binder, "id");
	CoherentBindInternal(binder, Loadout->ID_.ToChar());

	binder->MapEnd();
}