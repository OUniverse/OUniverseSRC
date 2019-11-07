//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/Ui_Relay.h"
#include "Ui_ViewPanel.generated.h"

class UUi_View;
class UCanvasPanel;

UCLASS(Blueprintable, BlueprintType)
class OUNIVERSE_API UUi_ViewPanel : public UUi_Relay
{

	GENERATED_BODY()


public:

	void Init();

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_Canvas;

	UPROPERTY()
	UUi_View* OpenView_;

	void Add(UUi_View* InView);

};