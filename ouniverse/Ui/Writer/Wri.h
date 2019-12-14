//Copyright 2015-2019, All Rights Reserved.

/**
Base UI Widget for the WRI (Writer/Scribe) menu.
 */

#pragma once

#include "Ui/UiAlpha.h"
#include "Interface/Array.h"
#include "Wri.generated.h"

class WriterPro;

class AtlasLibC;
class AtlasC;

class LoadoutC;

class UWRI_Main;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI : public UUiAlpha
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI* Create(WriterPro* InPro, AtlasLibC* InAtlasLib);
	void Init(WriterPro* InPro, AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UWRI_Main* View_Main;

	WriterPro* Profile_;

	void OpenLoadout();
	void SetMasterAtlas(AtlasC* InMasterAtlas);

	bool LoadoutLocked_;
	AtlasC* MasterAtlas_;
	ArrayC<AtlasC*> Loadout_;

	static enum Views {
		Main,
	};

private:

	AtlasLibC* AtlasLib_;
};