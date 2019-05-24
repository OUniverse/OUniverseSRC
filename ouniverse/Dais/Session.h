//Copyright 2015-2019, All Rights Reserved.

/**

## PreDais

An abbreviated pilot PreDais that is not fully loaded to go easier on the character/dais select screen.

**Creator:** KernelK
**Holder:** KernelK

 */

#pragma once

#include "Kernel/SaveFileK.h"

#include "Interface/String.h"
#include "Interface/Array.h"

class SessionFullC
{

};

class SessionC : public SaveFileK
{

private:

	int UID_;

	bool Valid_;

	SessionFullC* Full_;


	struct MinisterS
	{
		int Ver;

		MinisterS(StringC InLine);
	};


	struct VersionS
	{
		int Iteration;

		VersionS(StringC InLine);
	};

	struct DetailsS
	{
		StringC Area;
		int Date;

		DetailsS(StringC InLine);

	};

	struct PartyS
	{
		struct MemberS
		{

		};

		ArrayC<MemberS*> Members_;

		PartyS(StringC InLine);

	};

	MinisterS Minister_;
	VersionS Version_;
	DetailsS Details_;
	PartyS Party_;

	
public:

	SessionC(StringC InFileName, StringC InPath);

	void Crunch(StringC InFileName);

	int GetUID();

	void Preload();

	bool IsValid();

	void Promote();

	void Demote();
};