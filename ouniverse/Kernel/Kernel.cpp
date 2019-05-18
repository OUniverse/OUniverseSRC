//Copyright 2015-2019, All Rights Reserved.

#include "Kernel/Kernel.h"
#include "Kernel/DeclarationK.h"

#include "Interface/File.h"
#include "Interface/FileQuery.h"

#include "Min/DebugM.h"

KernelC* KernelC::Create(StringC InPath, DeclarationK* InDeclaration)
{
	return new KernelC(InPath, InDeclaration);
}

KernelC::KernelC(StringC InPath, DeclarationK* InDeclaration)
{
	Declaration_ = InDeclaration;
	Files.Add(Declaration_);
	Path_ = InPath;

	//FileC DeclarationFile = FileC(Path_/"u.oudcl");

	FileQueryS Fi = FileQueryS(Path_ / "", ".och");

	int Num = Fi.Num();

	for (int i = 0; i < Num; i++)
	{
		SaveBriefK* NewSave = new SaveBriefK(Fi.Full(i));

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