//Copyright 2015-2019, All Rights Reserved.

/**
Form: Abstract base form.
 */

#pragma once

#include "Interface/String.h"
#include "Interface/Json.h"
#include "Interface/Poly.h"
#include "System/FormUID.h"



class DataD
{

public:

	static DataD* Create(JsonS& InJ);

	DataD();

	void Setup(JsonS& InJ);

	virtual int Type();
	
	virtual void Demarshal();
		
	virtual ~DataD() {};

	FormUID UID();
	
	StringC ID();
		
	StringC Serialize();

	JsonS ToJson();

	JsonS* ToWriter(JsonS* InJ);

	PolyC* Poly();
	
	virtual PolyC* PolyInternal(PolyObjectC* InPoly);

	virtual JsonS* ToJsonInternal(JsonS* S);

	void Update(JsonS& InJ);

	virtual bool TryVP(int VarID, void*& VP);


protected:

	FormUID UID_;
	StringC ID_;
	JsonS Json_;
};