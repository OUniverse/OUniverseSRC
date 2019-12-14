//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiScrollerEntry.h"
#include "WriLoadoutU_ScrolLEntry.generated.h"


class AtlasC;
class UWriLoadout;
class UUi_Bool;
class UImage;
class UTextBlock;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriLoadout_ScrollEntry : public UUiScrollerEntry
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWriLoadout_ScrollEntry* Create(UWriLoadout* InView, AtlasC* InAtlas);

	void Init(UWriLoadout* InView, AtlasC* InAtlas);

	AtlasC* Atlas_;

	bool AtlasMaster_;
	bool AtlasActive_;

	UPROPERTY(meta = (BindWidget))
	UImage* V_Image;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Text;


};