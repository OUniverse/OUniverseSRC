//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "Writer_FormView.generated.h"


UCLASS(Blueprintable)
class OUNIVERSE_API UWriter_FormView : public UUi_View
{

	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable, meta = (DisplayName = "CreateWriterFormView"))
	static UWriter_FormView* Create(UUi_Master* InMax);

	void Init(UUi_Master* InMax);
};