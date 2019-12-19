//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "WRI_AtlasEdit.generated.h"

class AtlasC;
class UWRI;
class UTextBlock;


UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_AtlasEdit : public UUiView
{

	GENERATED_BODY()

public:


	void Init(UUiView* InOwningView);

	AtlasC* Atlas_;


	static enum Interactives {
		TextID,
		TextName,
		TextWeb,
		TextAuthor,
		TextWebsite,
		TextSocket,
	};

};