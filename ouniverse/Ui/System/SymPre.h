//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymPre.generated.h"

class UUiMouseInput;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_Pre : public UUiView
{

	GENERATED_BODY()

public:

	void Init(UUiView* InParentView);

	UPROPERTY(meta = (BindWidget))
	UUiMouseInput* V_Mouse;

	FReply EventMouseClick(int ElementID, const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

};