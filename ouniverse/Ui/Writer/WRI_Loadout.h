//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "WRI_Loadout.generated.h"

class UWRI_Alpha;
class UWRI_Loadout_Le;

class AtlasLibC;

class UUi_ScrollBox;
class UUi_Interactive;

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EWRI_VSetupEntryBoolType : uint8
{
	Master		UMETA(DisplayName = "Master"),
	Support		UMETA(DisplayName = "Support"),
};

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Loadout : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_Loadout* Create(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	void Init(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	UWRI_Alpha* CastedAlpha;

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;
	
	UPROPERTY(meta = (BindWidget))
	UUi_Interactive* V_Accept;

	UWRI_Loadout_Le* ActiveEntry_;

	void BoolChanged(int Type, UWRI_Loadout_Le* InEntry);

	UPROPERTY()
	TArray<UWRI_Loadout_Le*> Entries_;

	static enum Interactives {
		Accept,
	};

	void Click(UUi_Interactive* Interactive) override;

private:

	AtlasLibC* AtlasLib_;

};