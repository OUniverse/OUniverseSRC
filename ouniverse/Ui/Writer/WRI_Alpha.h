//Copyright 2015-2019, All Rights Reserved.

/**
Base UI Widget for the WRI (Writer/Scribe) menu.
 */

#pragma once

#include "Ui/Ui_Alpha.h"
#include "Interface/Array.h"
#include "WRI_Alpha.generated.h"


class AtlasLibC;
class AtlasC;

class UCanvasPanel;

class LoadoutC;

class UWRI_Main;
class UWRI_Splash;


UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Alpha : public UUi_Alpha
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_Alpha* Create(UWorld* InScope, UUi* InUi, AtlasLibC* InAtlasLib);
	void Init(UWorld* InScope, UUi* InUi, AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_View;

	UPROPERTY()
	UWRI_Main* View_Main;

	UPROPERTY()
	UWRI_Splash* View_Splash;

	void OpenLoadout();
	void SetMasterAtlas(AtlasC* InMasterAtlas);

	bool LoadoutLocked_;
	AtlasC* MasterAtlas_;
	ArrayC<AtlasC*> Loadout_;

	static constexpr int const& VMain	= 0;
	static constexpr int const& VSplash	= 1;

private:

	AtlasLibC* AtlasLib_;
};