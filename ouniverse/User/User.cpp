//Copyright 2015-2019, All Rights Reserved.

#include "User/User.h"
#include "User/DeclarationU.h"

#include "User/SaveBriefU.h"

#include "Interface/File.h"
#include "Interface/FileQuery.h"

#include "Min/DebugM.h"
UserC::UserC(StringC InPath, DeclarationU* InDeclaration)
{
	Declaration_ = InDeclaration;
	Files.Add(Declaration_);
	Path_ = InPath;

	//FileC DeclarationFile = FileC(Path_/"u.oudcl");

	FileQueryS Fi = FileQueryS(Path_/"",".och");

	int Num = Fi.Num();

	for(int i=0;i<Num;i++)
	{
		SaveBriefU* NewSave = new SaveBriefU(Fi.Full(i));

		if (NewSave->IsValid())
		{
			Characters_.Add(NewSave);
		}
		else 
		{
			delete NewSave;
		}

	}
	

	
}