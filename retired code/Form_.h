//Copyright 2015-2019, All Rights Reserved.

/**
Atlas
 */

#pragma once

#include "UObject/NoExportTypes.h"
#include "Form_.generated.h"


class FormF;


UCLASS(BlueprintType)
class OUNIVERSE_API UForm : public UObject
{
	GENERATED_BODY()

public: 

	static UForm* Create(FormF* InForm);
	void Init(FormF* InForm);


	FormF* Form_;

};