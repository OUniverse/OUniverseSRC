//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/Ui_View.h"
#include "WRI_AtlasEdit.generated.h"

class AtlasC;
class UWRI_Alpha;
class UTextBlock;
class UUi_TextEdit;

UCLASS(Blueprintable)
class OUNIVERSE_API UWRI_AtlasEdit : public UUi_View
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	static UWRI_AtlasEdit* Create(UUi_View* InOwningView);

	void Init(UUi_View* InOwningView);

	AtlasC* Atlas_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_UID;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_ID;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_Name;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_Author;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_Website;

	UPROPERTY(meta = (BindWidget))
	UUi_TextEdit* V_Socket;

	UWRI_Alpha* CastedAlpha_;

	static enum Interactives {
		TextID,
		TextName,
		TextWeb,
		TextAuthor,
		TextWebsite,
		TextSocket,
	};

	void TextCommit(UUi_Interactive* Interactive, int CommitMethod) override;
};