//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiAlpha.h"
#include "ConShelf.generated.h"


class ConsolePro;
class UMajor;

class UUiButton;

class UConShelf_Log;
class UConShelf_Output;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UConShelf : public UUiAlpha
{

	GENERATED_BODY()

	friend ConsolePro;

private:
	
	virtual void NativeConstruct() override;

	static UConShelf* Create(ConsolePro* InPro, UMajor* InMajor);
	void Init(ConsolePro* InPro, UMajor* InMajor);

	UMajor* Major_;

	UPROPERTY(meta = (BindWidget))
	UUiButton* Opt_Output;

	UPROPERTY(meta = (BindWidget))
	UUiButton* Opt_Log;

	UPROPERTY(meta = (BindWidget))
	UConShelf_Log* View_Log;

	UPROPERTY(meta = (BindWidget))
	UConShelf_Output* View_Output;


private:

	ConsolePro* Profile_;


};