//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_Alpha.h"
#include "WRI_Alpha.generated.h"

class UHorizontalBox;
class UAtlas;
class AtlasLibC;
class UWRI_AlphaOpt;
class UUi_Viewer;

class UWRI_VSetup;
class UWRI_VForm;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Alpha : public UUi_Alpha
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_Alpha* Create(UWorld* InScope, AtlasLibC* InAtlasLib);
	void Init(AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UHorizontalBox* V_Opts;

	UPROPERTY(meta = (BindWidget))
	UUi_Viewer* V_Viewer;

	AtlasLibC* AtlasLib_;

	void ImbueVSetup(UWRI_VSetup* InVSetup);

	void ImbueVForm(UWRI_VForm* InVSetup);

	static enum ViewPanels {
		Main,
		ViewPanels_MAX,
	};
	static enum Views {
		Setup,
		Atlas,
		Form,
		Views_MAX,
	};

};