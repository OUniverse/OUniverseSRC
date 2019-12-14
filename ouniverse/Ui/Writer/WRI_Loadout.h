//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "WRI_Loadout.generated.h"

class UWRI;
class UWRI_Loadout_Le;

class AtlasLibC;

class UUi_ScrollBox;


UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Loadout : public UUiView
{

	GENERATED_BODY()

public:


	void Init(UUiView* InParentView, AtlasLibC* InAtlasLib);

	UWRI* CastedAlpha;

	UPROPERTY(meta = (BindWidget))
	UUi_ScrollBox* V_Scroll;


	UWRI_Loadout_Le* ActiveEntry_;

	void BoolChanged(int Type, UWRI_Loadout_Le* InEntry);

	UPROPERTY()
	TArray<UWRI_Loadout_Le*> Entries_;

	static enum Interactives {
		Accept,
	};



private:

	AtlasLibC* AtlasLib_;

};