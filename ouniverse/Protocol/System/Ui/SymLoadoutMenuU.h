//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiBase.h"
#include "SymLoadoutMenuU.generated.h"

class UUiBase;
class UUiButton;
class SymLoadoutMenuP;

class USymUserSelect;
class USymUserCreate;
class USymUserEdit;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API USymLoadoutMenu : public UUiBase
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget) override;

	static enum REG {
		New,
		Select,
		Edit,
		Back,
	};

	SymLoadoutMenuP* Pro_;
	void UiConstruct(SymLoadoutMenuP* InPro);
};