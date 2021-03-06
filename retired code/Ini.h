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
#include "Interface/Array.h"
#include "Interface/Map.h"
struct DirS;

struct OUNIVERSE_API IniS
{

public:

	IniS(DirS* Path, StringC InFileName, int BoolSize, int IntSize, int FloatSize, int StringSize);

	DirS* Dir;
	StringC FileName;

		struct Entry
		{
		public:
			Entry() {};
			Entry(StringC InKey);

			StringC Key;

			bool Altered;
			
			virtual void SetDirty(StringC In) {};
			virtual StringC Out() { return "#$%"; };
			virtual void Reset(){};
			virtual ~Entry(){};
		};

		struct String : public Entry
		{

		public:

			static String* Create(StringC InKey,StringC InDefault);

			String(StringC InKey, StringC InDefault);

			StringC Get();

			void Set(StringC In);

			void SetDirty(StringC In) override;

			StringC Out() override;
			
			void Reset();

		private:

			StringC Value;
			StringC Default;

		};
	
		struct Float : public Entry
		{
		public:

			static Float* Create(StringC InKey, float InDefault);

			Float(StringC InKey, float InDefault);

			float Get();

			void Set(float In);
			
			void SetDirty(StringC In) override;

			StringC Out() override;
			
			void Reset();
	
		private:

			float Value;
			float Default;

		};

		struct Int : public Entry
		{
		public:

			static Int* Create(StringC InKey, int InDefault);

			Int(StringC InKey, int InDefault);
			
			int Get();

			void Set(int In);


			void SetDirty(StringC In) override;

			StringC Out() override;
			
			void Reset() override;

		private:

			int Value;
			int Default;

		};

		struct Bool : public Entry
		{

		public:

			static Bool* Create(StringC InKey, bool InDefault);

			Bool(StringC InKey, bool InDefault);

			bool Get();

			void Set(bool In);

			void SetDirty(StringC In) override;
			
			StringC Out() override;

			void Reset();

		private:

			bool Value;
			bool Default;

		};

	MapC<StringC, Entry*> KeyMap;

	ArrayC<Float*> FloatVector;
	ArrayC<Int*> IntVector;
	ArrayC<Bool*> BoolVector;
	ArrayC<String*> StringVector;

	void Parse();

	void AddBool(int Key, Bool* Default);
	void AddInt(int Key, Int* Default);
	void AddFloat(int Key, Float* Default);
	void AddString(int Key, String* Default);


	void Set(int Key, float Val);
	void Set(int Key, int Val);
	void Set(int Key, bool Val);
	void Set(int Key, StringC Val);

	void SetDirty(StringC Key, StringC Val);

	StringC GetString(int key);
	int GetInt(int Key);
	float GetFloat(int Key);
	bool GetBool(int Key);

	void Save();
	void SaveTemplate();
	void SetAndSave(StringC Key, StringC Val, bool bSave);

	void Reset();
};

