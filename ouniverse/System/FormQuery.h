//Copyright 2015-2019, All Rights Reserved.

/**

## DirQuery

**Struct:** DirQueryS

Functionality for querying directories within a directory.

* Can return the name all folders within a directory.
* Can return the full path of all folders within a diretory.
* Can return the number of folders in a directory.

*/

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"

#include "System/FormWrap.h"

class AtlasC;
class DataD;

class FormDataC;


struct FormQueryBooleanS
{
	FormQueryBooleanS() {};

	virtual bool Valid(AtlasC* Atlas, DataD* Form);

	virtual ~FormQueryBooleanS();
};

struct FQB_ID_CaseInsensitiveS : public FormQueryBooleanS
{
	FQB_ID_CaseInsensitiveS(StringC InQueryID);

	virtual bool Valid(AtlasC* Atlas, DataD* Form) override;

	StringC QueryID_;
};


struct FormQueryS
{
	FormQueryS() {};
	FormQueryS(StringC InQuery, ArrayC<FormWrapS>* InFormArr);
	~FormQueryS();

	void Scan(FormWrapS InForm);

	int BooleanLen();

	ArrayC<FormWrapS>* ValidForms_;
	

private:

	void AddBoolean(FormQueryBooleanS* InBoolean);

	int BooleanLen_;

	ArrayC<FormQueryBooleanS*> Booleans_;

};




class FormDataQueryC
{

public:

	FormDataQueryC() {};
	FormDataQueryC(StringC InQuery, ArrayC<FormDataC*>* InFormArr);
	~FormDataQueryC();

	void Scan(FormDataC* InForm);

	int BooleanLen();

	ArrayC<FormDataC*>* ValidForms_;


private:

	void AddBoolean(FormQueryBooleanS* InBoolean);

	int BooleanLen_;

	ArrayC<FormQueryBooleanS*> Booleans_;

};