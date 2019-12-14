//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBaseNew.h"
#include "CnsOutputU.generated.h"

class CnsOutputP;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UCnsOutput : public UUiBaseNew
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct(CnsOutputP* InPro);

	CnsOutputP* Pro_;
};