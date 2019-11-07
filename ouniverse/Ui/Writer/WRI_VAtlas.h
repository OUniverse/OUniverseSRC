//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "WRI_VAtlas.generated.h"

class UUi_View;
class UWRI_Alpha;


class UCanvasPanel;
class UScrollBox;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_VAtlas : public UUi_View
{

	GENERATED_BODY()

public:

	static UWRI_VAtlas* Create(UUi_View* OwningView_);

	void Init(UUi_View* OwningView_);

	UWRI_Alpha* CastedAlpha_;
};