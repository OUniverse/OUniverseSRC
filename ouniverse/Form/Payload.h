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

class FormF;
class AtlasC;

class PayloadC
{
public:

	FormF* AddForm(const std::string InProprietary);

	PayloadC(const char* AtlasDirectory);

private:

	enum FormTypes {
		Form,
		Ref,
		Object,
		MAX,
	};

	std::vector<FormF* (*)()> FactoryVector;

	const char* Path;

	int FormCount;

	std::unordered_map <uint32, FormF*> Map;

	std::vector <AtlasC*> AtlasVector;

};
