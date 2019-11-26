//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "SYM_AtlasMount.generated.h"

class USYM_Alpha;

class AtlasLibC;

UCLASS(Blueprintable)
class OUNIVERSE_API USYM_AtlasMount : public UUi_View
{

	GENERATED_BODY()


public:

	virtual void NativeConstruct() override;

	static USYM_AtlasMount* Create(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	void Init(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	AtlasLibC* AtlasLib_;

	USYM_Alpha* CastedAlpha;

};