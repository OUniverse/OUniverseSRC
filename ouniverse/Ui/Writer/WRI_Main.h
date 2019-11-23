//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "WRI_Main.generated.h"

class AtlasLibC;

class UCanvasPanel;
class UUi_Interactive;

class UWRI_AtlasMount;
class UWRI_Loadout;
class UWRI_AtlasEdit;
class UWRI_FormEdit;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Main : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_Main* Create(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	void Init(UUi_View* InParentView, AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UCanvasPanel* V_View;

	UPROPERTY(meta = (BindWidget))
	UUi_Interactive* V_OptLoadout;

	UPROPERTY(meta = (BindWidget))
	UUi_Interactive* V_OptAtlas;

	UPROPERTY(meta = (BindWidget))
	UUi_Interactive* V_OptForm;

	UPROPERTY()
	UWRI_AtlasMount* View_AtlasMount;

	UPROPERTY()
	UWRI_Loadout* View_Loadout;

	UPROPERTY()
	UWRI_AtlasEdit* View_AtlasEdit;

	UPROPERTY()
	UWRI_FormEdit* View_FormEdit;

	static constexpr int const& VAtlasMount = 0;
	static constexpr int const& VLoadout	= 1;
	static constexpr int const& VAtlasEdit	= 2;
	static constexpr int const& VFormEdit	= 3;

	static enum Interactives {
		OptLoadout,
		OptAtlas,
		OptForm,
	};

	void Click(UUi_Interactive* Interactive) override;

};