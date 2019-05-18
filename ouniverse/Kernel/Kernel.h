//Copyright 2015-2019, All Rights Reserved.

/**

## Kernel

> **Singleton Service: Created once only by the boot process.**

A user once active becomes a kernel unpacking and managing their save game data.
Acts as a central data storage for the saveable progression.

**Creator:** SessionC
**Holder:** SessionC

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"
#include "Kernel/SaveFileK.h"
#include "Kernel/SaveBriefK.h"

class DeclarationK;
class UserC;

class OUNIVERSE_API KernelC
{

private:

	UserC* User_;
	StringC Path_;

	DeclarationK* Declaration_;
	ArrayC<SaveFileK*> Files;

	ArrayC<SaveBriefK*> Characters_;

public:

	static KernelC* Create(UserC* InUser);

	KernelC(UserC* InUser);

	void Demote() {};

};