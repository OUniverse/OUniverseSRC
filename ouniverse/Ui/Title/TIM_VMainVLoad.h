//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "TIM_VMainVLoad.generated.h"

class UTIM_Alpha;

class AtlasLibC;

UCLASS(Blueprintable)
class OUNIVERSE_API UTIM_VMainVLoad : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static UTIM_VMainVLoad* Create(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	void Init(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	AtlasLibC* AtlasLib_;

	UTIM_Alpha* CastedAlpha;

};