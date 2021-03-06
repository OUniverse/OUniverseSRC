//Copyright 2015-2019, All Rights Reserved.

/**

## SaveFolder

A Save Folder is a marshalling of the results of scanning a folder in the Save directory.

**Creator:** SaveLib
**Holder:** SaveLib

 */

#pragma once

#include "System/Save.h"

#include "cohtml/Binding/Binding.h"
#include "cohtml/Binding/EventHandler.h"



void CoherentBind(cohtml::Binder* binder, SaveC* Save)
{
	/** I struggled binding StringC this way and found the lower binding format much clearer
	if (auto type = binder->RegisterType("Save", Save))
	{
		type.Property("uid", &SaveC::UID_);
	}
	*/

	binder->MapBegin(2);

	CoherentBindInternal(binder, "uid");
	CoherentBindInternal(binder, Save->UID().ForUI());
	CoherentBindInternal(binder, "id");
	CoherentBindInternal(binder, Save->Name_.ToChar());

	binder->MapEnd();
}