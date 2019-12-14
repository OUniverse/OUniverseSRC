//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiBase.h"
#include "WRI_Loadout_Le.generated.h"

class AtlasC;

class UWRI_Loadout;
class UUi_Bool;
class UTexture2D;
class UImage;
class UTextBlock;


UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Loadout_Le : public UUiBase
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_Loadout_Le* Create(UWRI_Loadout* InView, AtlasC* InAtlas);

	void Init(UWRI_Loadout* InView, AtlasC* InAtlas);

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;
	UPROPERTY(meta = (BindWidget))
	UUi_Bool* V_BoolMaster;
	UPROPERTY(meta = (BindWidget))
	UUi_Bool* V_BoolSupport;
	
	AtlasC* Atlas_;

	UWRI_Loadout* View_;


	bool AtlasActivated();

	static enum Interfaces {
		Master,
		Support,
	};

};