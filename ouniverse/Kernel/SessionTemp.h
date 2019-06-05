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
#include "System/Session.h"

class DeclarationK;
class UserC;
class SessionC;
class DaisD;

class OUNIVERSE_API SessionTempC
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

	ArrayC<SessionC*> PreDaisArray;

	DaisD* Dais_;

	bool DaisSet_;

public:

	static SessionTempC* Create(UserC* InUser);

	SessionTempC(UserC* InUser);

	void Demote() {};

	void SetDais(int InUID);

};