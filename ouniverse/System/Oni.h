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
#include "Interface/Url.h"

struct DirS;


class OnuC
{

public:

	OnuC(int InKey, int InCategory);

	int Key();

	bool Updated();

	bool IsCategory(int InCategory);

	virtual void Load(JsonS InJ);

	virtual JsonS ToJson();

	virtual ~OnuC() {};

	virtual StringC ToString();
	virtual int ToInt();
	virtual bool ToBool();
	virtual float ToFloat();

protected:

	int Key_;
	bool Updated_;

	int Category_;

};

class OnuBoolC : public OnuC
{

public:

	OnuBoolC(int InKey, bool InDefault, int InCategory);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	bool Current_;
	bool Default_;

	StringC ToString() override;
	int ToInt() override;
	bool ToBool() override;
	float ToFloat() override;
};

class OnuIntC : public OnuC
{

public:

	OnuIntC(int InKey, int InDefault, int InCategory);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	int Current_;
	int Default_;

	StringC ToString() override;
	int ToInt() override;
	bool ToBool() override;
	float ToFloat() override;
};

class OnuFloatC : public OnuC
{

public:

	OnuFloatC(int InKey, float InDefault, int InCategory);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	float Current_;
	float Default_;

	StringC ToString() override;
	int ToInt() override;
	bool ToBool() override;
	float ToFloat() override;
};

class OnuStringC : public OnuC
{

public:

	OnuStringC(int InKey, StringC InDefault, int InCategory);

	virtual void Load(JsonS InJ) override;
	virtual JsonS ToJson() override;

	StringC Current_;
	StringC Default_;

	StringC ToString() override;
	int ToInt() override;
	bool ToBool() override;
	float ToFloat() override;
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

	OnuC* Get(int InInt);

	MapC<int, OnuC*> Lib_;

	FileC File_;

	StringC GetSerializedCategory(int InCategory);

};