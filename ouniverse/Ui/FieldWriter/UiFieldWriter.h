//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "UiFieldWriter.generated.h"

class UUiBase;

UCLASS(Abstract)
class OUNIVERSE_API UUiFieldWriter : public UUiFocus
{

	GENERATED_BODY()

public:
	void SetupField(int InID, UUiBase* InRelay);

protected:

	UUiBase* Relay_;
	int ID_;
};