//Copyright 2015-2019, All Rights Reserved.

/**
ConfigBeacons assist in managing OUniverse's .ini config files (.oni).
It stacks a list of OniFlex objects in a map which link a key to a default and optional override.
It can print out the oni document so the user can update changes.
 */

#pragma once

#include "CoreMinimal.h"
#include <map>
#include <vector>
#include "Interface/String.h"

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
			Entry(StringC InKey);

			StringC Key;

			bool Altered;
			
			virtual void SetDirty(StringC) = 0;
			virtual StringC Out() = 0;
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

	std::map <StringC, Entry*> KeyMap;

	std::vector <Float*> FloatVector;
	std::vector <Int*> IntVector;
	std::vector <Bool*> BoolVector;
	std::vector <String*> StringVector;

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

