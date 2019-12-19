//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "CnsShelfU.generated.h"

class CnsShelfP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UCnsShelf : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(CnsShelfP* InPro);

	CnsShelfP* Pro_;
};