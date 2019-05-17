//Copyright 2015-2019, All Rights Reserved.

#include "Form/Payload.h"
#include "Form/Atlas.h"

#include "Interface/FileQuery.h"
#include "Interface/Dir.h"

#include "Form/FormF.h"
#include "Form/RefF.h"
#include "Form/ObjectF.h"


#include "Min/LogM.h"

PayloadC::PayloadC(DirS* InDirAtlas)
{
	FormCount = 0;
	DirAtlas = InDirAtlas;

	FactoryArray.Init(FormTypes::MAX, NULL);
	FactoryArray[FormTypes::Form]		= FormF::Create;
	FactoryArray[FormTypes::Ref]		= RefF::Create;
	FactoryArray[FormTypes::Object]		= ObjectF::Create;
	
	FileQueryS Fi = FileQueryS(DirAtlas->Get());


	LOG(BOOT, 0, 0, StringC("Scanning Atlas Folder: ") + DirAtlas->Get()+"/")
	
	for (int i = 0; i < Fi.Num(); i++)
	{
		LOG(BOOT, 0, 0, StringC("File Found: ") + Fi.File(i))

		if (AtlasC::Extension(Fi.Extension(i)))
		{
			LOG(BOOT, 0, 0, StringC("Is an Atlas! "))
			AtlasC* NewAtlas = new AtlasC(Fi.Full(i));
			//AtlasArray.Add(NewAtlas);
		//	NewAtlas->Scan(this);
		}
		else
		{
			LOG(BOOT, 0, 0, StringC("Not an Atlas!"))
		}
	}
}

FormF* PayloadC::AddForm(const std::string InProprietary)
{

	uint32 UID = std::atoi(InProprietary.substr(0, 10).c_str());
	uint8 Type = std::atoi(InProprietary.substr(10, 3).c_str());

	FormF* NewForm = FactoryArray[Type]();
	NewForm->UID = UID;
	NewForm->Serialized = InProprietary.substr(13, -1).c_str();
	Map.insert( { UID , NewForm } );
	
	FormCount++;

	return NewForm;
}