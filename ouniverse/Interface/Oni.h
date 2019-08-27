//Copyright 2015-2019, All Rights Reserved.

/**

## Ini

**Class:**  IniC

Loads and saves ini documents from a path.

#### Features
* Can restore any value to default.
* Only writes altered values.
* Access values by exact type.

#### Additions
**Entry:**  Abstract Ini Entry.
**String:**  Entry extension which contains a StringC.
**Float:**  Entry extension which contains a float.
**Int:**  Entry extension which contains an int.
**Bool:**  Entry extension which contains a bool.

 */

#pragma once

#include "Interface/String.h"
#include "Interface/Map.h"
#include "Interface/Array.h"
#include "Interface/Json.h"
#include "Interface/File.h"


struct DirS;



class OnuC
{

public:

	OnuC(int InKey);

	int Key();

	bool Updated();

	virtual void Load(JsonS InJ);

	virtual JsonS ToJson();

	virtual ~OnuC() {};

protected:

	int Key_;
	bool Updated_;

};

class OnuBoolC : public OnuC
{

public:

	OnuBoolC(int InKey, bool InDefault);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	bool Current_;
	bool Default_;
};

class OnuIntC : public OnuC
{

public:

	OnuIntC(int InKey, int InDefault);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	int Current_;
	int Default_;
};

class OnuFloatC : public OnuC
{

public:

	OnuFloatC(int InKey, float InDefault);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	float Current_;
	float Default_;
};

class OnuStringC : public OnuC
{

public:

	OnuStringC(int InKey, StringC InDefault);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	StringC Current_;
	StringC Default_;
};

class OUNIVERSE_API OniC
{

public:

	static const int VER_WRITE;
	static const char* KEY_KEY;
	static const char* KEY_VAL;

	OniC();

	int VerW_;

	void AddOnu(OnuC* InOnu);

	void Load(FileC InFile);
	 
	void Save();

	MapC<int, OnuC*> Lib_;

	FileC File_;
};

class OUNIVERSE_API OniUserC : public  OniC
{

public:

	static const int AUTOLOGIN_SINGLE_USER;
	static const int AUTOLOGIN_LAST_USER;

	OniUserC();

};


class OUNIVERSE_API OniManagerC
{

public:

	static enum Types {
		Internal,
		Global,
		User,
		Scribe,
		TYPES_MAX,
	};

	OniManagerC();
	
	void Load(OniManagerC::Types InType, FileC InPath);

	ArrayC<OniC*>Lib_;

	
};