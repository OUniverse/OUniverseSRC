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
#include <string>



struct OUNIVERSE_API IniS
{

public:

	IniS(FString* Path, FString FileName, int BoolSize, int IntSize, int FloatSize, int StringSize);

	FString* Dir;
	FString File;

		struct Entry
		{
		public:
			Entry(std::string InKey);

			std::string Key;

			bool Altered;
			
			virtual void SetDirty(std::string) = 0;
			virtual std::string Out() = 0;
			virtual void Reset(){};
			virtual ~Entry(){};
		};

		struct String : public Entry
		{

		public:

			static String* Create(std::string InKey,std::string InDefault);

			String(std::string InKey, std::string InDefault);

			std::string Get();

			FString GetAsFString();

			void Set(std::string In);

			void SetDirty(std::string In) override;

			std::string Out() override;
			
			void Reset();

		private:

			std::string Value;
			std::string Default;

		};
	
		struct Float : public Entry
		{
		public:

			static Float* Create(std::string InKey, float InDefault);

			Float(std::string InKey, float InDefault);

			float Get();

			void Set(float In);
			
			void SetDirty(std::string In) override;

			std::string Out() override;
			
			void Reset();
	
		private:

			float Value;
			float Default;

		};

		struct Int : public Entry
		{
		public:

			static Int* Create(std::string InKey, int InDefault);

			Int(std::string InKey, int InDefault);
			
			int Get();

			void Set(int In);


			void SetDirty(std::string In) override;

			std::string Out() override;
			
			void Reset() override;

		private:

			int Value;
			int Default;

		};

		struct Bool : public Entry
		{

		public:

			static Bool* Create(std::string InKey, bool InDefault);

			Bool(std::string InKey, bool InDefault);

			bool Get();

			void Set(bool In);

			void SetDirty(std::string In) override;
			
			std::string Out() override;

			void Reset();

		private:

			bool Value;
			bool Default;

		};

	std::map <std::string,Entry*> KeyMap;
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
	void Set(int Key, std::string Val);

	void SetDirty(std::string Key, std::string Val);

	std::string GetString(int key);
	int GetInt(int Key);
	float GetFloat(int Key);
	bool GetBool(int Key);

	void Save();
	void SaveTemplate();
	void SetAndSave(std::string Key, std::string Val, bool bSave);

	void Reset();
};

