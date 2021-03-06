//Copyright 2015-2019, All Rights Reserved.

/**

## UserLib

> **Singleton Service: Created once only by the boot process.**
>
A service singleton which manages all User data. (A User represents the person that is playing.)

#### Tasks:
* Can return user from an ID or a serial number (In case ID is changed)
* Manages the shifting of Users or assigning a new User.
* Scans the user directory and creates a UserFolder class object for each valid user found.

**Creator:** UBoot
**Holder:** Major

 */

#pragma once

#include "System/LoadoutAtlas.h"
#include "Interface/String.h"
#include "Interface/Array.h"
#include "System/Glyph.h"

#include "System/LoadoutUID.h"
#include "System/AtlasUID.h"

struct JsonS;

class OUNIVERSE_API LoadoutC
{

public:

	static LoadoutC* Create();
	
	void JsonMethod(JsonS* InJ);

	void CreateMethod(int InUID, StringC InID, GlyphC InGlyph, bool InNoSave);

	LoadoutC();

	void AddAtlasLoadout(AtlasUID InUID, StringC InName);

	bool IsValid();

	LoadoutUID UID();

	StringC ID();

	void Mount();

	void Dismount();

	StringC Combo_UID_ID();

	ArrayC<AtlasUID> GetSelectedAtlasi();

private:


	ArrayC<LoadoutAtlasC> Atlasi_;

	bool Valid_;

	LoadoutUID UID_;
	
	StringC ID_;

	GlyphC Glyph_;

	bool NoSave_;
};