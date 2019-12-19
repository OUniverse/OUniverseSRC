//Copyright 2015-2019, All Rights Reserved.



#pragma once

#include "Ui/UiBase.h"
#include "ConShelf_LogEntry.generated.h"


class ConsolePro;
class URichTextBlock;
class UTextBlock;
class UImage;
class UConShelf_Log;
class LoggerEntryC;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UConShelf_LogEntry : public UUiBase
{

	GENERATED_BODY()

public:
	

	virtual void NativeConstruct() override;

	static UConShelf_LogEntry* Create(UConShelf_Log* InView, LoggerEntryC* InUser);

	void Init(UConShelf_Log* InView, LoggerEntryC* InUser);

	UPROPERTY(meta = (BindWidget))
	URichTextBlock* V_Text;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Index;
	UPROPERTY(meta = (BindWidget))
	UTextBlock* V_Cat;
	UPROPERTY(meta = (BindWidget))
	UImage* V_Flag;

	UConShelf_Log* View_;

	LoggerEntryC* Log_;

};