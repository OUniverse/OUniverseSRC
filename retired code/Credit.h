//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "Interface/String.h"

class CreditLibC;
struct JsonS;

class CreditC
{
	friend CreditLibC;
	
public: 

	static const char* FILE_NAME;

	static const char* K_UID;
	static const char* K_ID;
	static const char* K_AUTHORITY;
	static const char* K_ITERATION;

	CreditC(JsonS* InJ);
	
	bool Valid();

	StringC ID_;
	StringC Name_;
	StringC Icon_;
	StringC Desc_;
	StringC Author_;
	StringC Website_ ;

	int Authority_;
	int Iteration_;
	
	void Update(JsonS* InJ);

	void Compare(JsonS* InJ);

	enum AuthorityLevels {
		Error,
		Unknown,
		Rough,
		Ref,
		TeamMember,
		Actual,
	};


private:

	bool Valid_;

	CreditC(U64 InUID, JsonS* InJ);

};