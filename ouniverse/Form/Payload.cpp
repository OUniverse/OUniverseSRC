//Copyright 2015-2019, All Rights Reserved.

#include "Form/Payload.h"
#include "Form/Atlas.h"

#include "Util/FileFriend.h"

#include "Form/Form.h"
#include "Form/Ref.h"
#include "Form/Object.h"

PayloadC::PayloadC(const char* AtlasDirectory)
{
	FormCount = 0;
	Path = AtlasDirectory;

	FactoryVector.assign(FormTypes::MAX, NULL);
	FactoryVector[FormTypes::Form]	 = FormF::Create;
	FactoryVector[FormTypes::Ref]	 = RefF::Create;
	FactoryVector[FormTypes::Object] = ObjectF::Create;
	
	DirFiles Fi = DirFiles(Path);

	for (int i = 0; i < Fi.Count; i++)
	{
		if (AtlasC::Extension(Fi.Extension(i)))
		{
			AtlasC* NewAtlas = new AtlasC(Fi.FullPath(i));
			AtlasVector.push_back(NewAtlas);
			NewAtlas->Scan(this);
			
		}
		else
		{
			GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, "Not Atlas");
		}
	}
}

FormF* PayloadC::AddForm(const std::string InProprietary)
{

	uint32 UID = std::atoi(InProprietary.substr(0, 10).c_str());
	uint8 Type = std::atoi(InProprietary.substr(10, 3).c_str());

	FormF* NewForm = FactoryVector[Type]();
	NewForm->UID = UID;
	NewForm->Serialized = InProprietary.substr(13, -1).c_str();
	Map.insert( { UID , NewForm } );
	
	FormCount++;

	return NewForm;
}