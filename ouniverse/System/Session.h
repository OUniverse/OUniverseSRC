//Copyright 2015-2019, All Rights Reserved.

/**

## PreDais

An abbreviated pilot PreDais that is not fully loaded to go easier on the character/dais select screen.

**Creator:** KernelK
**Holder:** KernelK

 */

#pragma once

#include "Kernel/SaveFileK.h"

#include "Interface/Int.h"
#include "Interface/String.h"
#include "Interface/Array.h"

struct WriterVer;

class SessionFullC
{

};

class SessionC : public SaveFileK
{

	static const char* P_SESSION;

private:

	int UID_;

	bool Valid_;

	SessionFullC* Full_;


	struct VersionS
	{
		int Iteration;

		VersionS() {};
		VersionS(StringC InLine);
	};

	struct DetailsS
	{
		StringC Area;
		int Date;

		DetailsS() {};
		DetailsS(StringC InLine);

	};

	struct PartyS
	{
		struct MemberS
		{

		};

		ArrayC<MemberS*> Members_;

		PartyS() {};
		PartyS(StringC InLine);

	};

	VersionS Version_;
	DetailsS Details_;
	PartyS Party_;

	
public:

	SessionC(StringC InFileName, StringC InPath);

	int GetUID();

	bool IsValid();

	void Promote();

	void Demote();
};