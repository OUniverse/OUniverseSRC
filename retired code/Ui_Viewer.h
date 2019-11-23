//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ubc.h"
#include "UI/Ui_View.h"
#include "Ui_Viewer.generated.h"

class UUi_View;
class UCanvasPanel;


UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UUi_Viewer : public UUbc
{

	GENERATED_BODY()


public:

	void Add(UUi_View* InView);
	void ClearChildren();


	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Canvas;

};