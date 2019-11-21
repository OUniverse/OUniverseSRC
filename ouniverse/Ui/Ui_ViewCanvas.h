//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Components/CanvasPanel.h"
#include "UI/Ui_View.h"
#include "Ui_ViewCanvas.generated.h"


UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UUi_ViewCanvas : public UCanvasPanel
{

	GENERATED_BODY()


public:

	void Add(UUi_View* InView);
	void ClearChildren();

};