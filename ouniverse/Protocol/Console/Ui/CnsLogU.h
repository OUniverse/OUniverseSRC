//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "CnsLogU.generated.h"

class CnsLogP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UCnsLog : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(CnsLogP* InPro);

	CnsLogP* Pro_;
};