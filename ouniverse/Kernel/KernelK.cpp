//Copyright 2015-2019, All Rights Reserved.

#include "Kernel/KernelK.h"
#include "Kernel/DeclarationK.h"
#include "System/User.h"

#include "Interface/File.h"
#include "Interface/FileQuery.h"

#include "Dais/DaisD.h"

#include "Min/DebugM.h"
#include "Min/LogM.h"

KernelC* KernelC::Create(UserC* InUser)
{
	return new KernelC(InUser);
}

KernelC::KernelC(UserC* InUser)
{
	DaisSet_ = false;

	FileTypes.Init(Types::FILES_MAX, nullptr);
	User_ = InUser;
	Declaration_ = User_->GetDeclaration();
	Files.Add(Declaration_);
	FileTypes[Types::Declaration] = Declaration_;
	Path_ = User_->GetPath();

	//FileC DeclarationFile = FileC(Path_/"u.oudcl");

	FileQueryS Fi = FileQueryS(Path_ / "", ".oss");

	int Num = Fi.Num();

	for (int i = 0; i < Num; i++)
	{
		//LOG(BOOT, 0, 0, Fi.Full(i))
		DaisPreD* NewSave = new DaisPreD(Fi.File(i),Fi.Full(i));

		//LOG(BOOT, 0, 0, ".oss found ")
		//	LOG(BOOT, 0, 0, Fi.Full(i))
		//LOG(BOOT, 0, 0, FileReadS(Fi.Full(i)).Out().ToChar())
		//if (NewSave->IsValid())
		//{
		//	PreDaisArray.Add(NewSave);
		//}
		//else
		//{
		//	delete NewSave;
		//}

	}

	LOG(BOOT, 0, 0, "Kernel Activated: ")
}

void KernelC::SetDais(int InUID)
{
	int L = PreDaisArray.Len();
	for (int i = 0; i < L; i++)
	{
		if (PreDaisArray[i]->GetUID() == InUID)
		{
			DBUG("Selected Dias Found");

			if (DaisSet_)
			{
				Dais_->Demote();
				delete Dais_;
			}

			DaisSet_ = true;
			Dais_ = new DaisD(PreDaisArray[i]);

			break;
		}
	}
}