//Copyright 2015-2019, All Rights Reserved.

/**

## Kernel

A user once active becomes a kernel unpacking and managing their save game data.
Acts as a central data storage for the saveable progression.

**Creator:** SessionC
**Holder:** SessionC

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"
#include "Kernel/SaveFileK.h"
#include "Dais/PreDaisD.h"

class DeclarationK;
class UserC;
class DaisPreD;
class DaisD;

class OUNIVERSE_API KernelC
{

private:

	enum Types
	{
		Declaration,
		FILES_MAX,
	};

	UserC* User_;

	StringC Path_;

	DeclarationK* Declaration_;


	ArrayC<SaveFileK*> Files;
	ArrayC<SaveFileK*> FileTypes;

	ArrayC<DaisPreD*> PreDaisArray;

	DaisD* Dais_;

	bool DaisSet_;

public:

	static KernelC* Create(UserC* InUser);

	KernelC(UserC* InUser);

	void Demote() {};

	void SetDais(int InUID);

};