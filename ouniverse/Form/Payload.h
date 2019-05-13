//Copyright 2015-2019, All Rights Reserved.

/**
Payload is the top level unpacked of the Atlas data system.
- Scans the Atlas Folder (Potentially multiple folders if needed)
- Creates Atlases
- Creates PreForms 
- Creates Forms and maintains them all in a map with a uint32 key.
	- Creates a factory vector with pointers to each form type's creation function.

 */

#pragma once

#include <vector>
#include <unordered_map>
#include "Interface/Array.h"

class FormF;
class AtlasC;
struct DirS;

class PayloadC
{
public:

	FormF* AddForm(const std::string InProprietary);

	PayloadC(DirS* InDirAtlas);

private:

	enum FormTypes {
		Form,
		Ref,
		Object,
		MAX,
	};

	ArrayC<FormF* (*)()> FactoryArray;

	DirS* DirAtlas;

	int FormCount;

	std::unordered_map <uint32, FormF*> Map;

	ArrayC<AtlasC*> AtlasArray;

};
