//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "WRI_Main.generated.h"

class AtlasLibC;

class UUiButton;


class UWRI_AtlasMount;
class UWRI_Loadout;
class UWRI_AtlasEdit;
class UWRI_FormEdit;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_Main : public UUiView
{

	GENERATED_BODY()

public:


	static UWRI_Main* Create(UUiView* InParentView, AtlasLibC* InAtlasLib);

	void Init(UUiView* InParentView, AtlasLibC* InAtlasLib);

	UPROPERTY(meta = (BindWidget))
	UUiButton* OPT_Loadout;
	UPROPERTY(meta = (BindWidget))
	UUiButton* OPT_AtlasEdit;
	UPROPERTY(meta = (BindWidget))
	UUiButton* OPT_FormEdit;


	UPROPERTY(meta = (BindWidget))
	UWRI_AtlasMount* View_AtlasLoad;
	UPROPERTY(meta = (BindWidget))
	UWRI_Loadout* View_Loadout;
	UPROPERTY(meta = (BindWidget))
	UWRI_AtlasEdit* View_AtlasEdit;
	UPROPERTY(meta = (BindWidget))
	UWRI_FormEdit* View_FormEdit;


	static enum Interfaces {
		OptLoadout,
		OptAtlasEdit,
		OptFormEdit,
	};

	static enum Views {
		AtlasLoad,
		Loadout,
		AtlasEdit,
		FormEdit,
	};

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

};