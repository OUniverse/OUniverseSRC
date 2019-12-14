//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "CnsLogU.generated.h"

class CnsLogP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UCnsLog : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(CnsLogP* InPro);

	CnsLogP* Pro_;
};