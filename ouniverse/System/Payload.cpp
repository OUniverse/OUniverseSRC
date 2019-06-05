//Copyright 2015-2019, All Rights Reserved.

#include "System/Payload.h"
#include "System/Atlas.h"

#include "Interface/FileQuery.h"
#include "Interface/DirQuery.h"

#include "Interface/Dir.h"

#include "Form/FormF.h"
#include "Form/RefF.h"
#include "Form/ObjectF.h"

#include "Data/World.h"

#include "Min/LogM.h"

#include "Form/FactoryF.h"

PayloadC::PayloadC(DirS* InDirAtlas)
{
	DirAtlas = InDirAtlas;

	Factory = new FactoryF();

	DirQueryS Fo = DirQueryS(DirAtlas->Get());
	LOG(BOOT, 0, 0, StringC("Scanning Atlas Directory: ") + DirAtlas->Get() + "/")
	
	for (int i = 0; i < Fo.Num(); i++)
	{
		//AtlasC* NewAtlas = new AtlasC(Fo.Full(i));

		//if (NewAtlas->Valid())
		//{
		//	AtlasMap.Add(NewAtlas->UID(), NewAtlas);
		//}
	}
}