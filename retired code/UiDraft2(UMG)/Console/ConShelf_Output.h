//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "Ui/UiView.h"
#include "ConShelf_Output.generated.h"


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UConShelf_Output : public UUiView
{

	GENERATED_BODY()

public:

	void Init(UUiView* InParentView);

};