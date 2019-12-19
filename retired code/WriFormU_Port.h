//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "WriFormU_Port.generated.h"

class FormDataC;
class UTextBlock;
class UWriButton;
class UUiBool;

class UWriForm_PortRack;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriForm_Port : public UUiFocus
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void Assign(FormDataC* InForm);
	void Clear();

	void Init(UWriForm_PortRack* InPortRack);

	UWriForm_PortRack* PortRack_;

	int PortIndex_;

	FormDataC* Form_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vId;

	UPROPERTY(meta = (BindWidget))
	UWriButton* vClose;

	UPROPERTY(meta = (BindWidget))
	UUiBool* vUnsaved;


	static enum REG {
		RClose,
	};

	UFUNCTION(BlueprintImplementableEvent)
	void PortAssignBP();
		

	UFUNCTION(BlueprintImplementableEvent)
	void PortClearBP();

	void EventUi(int WidgetID, int InEventID, UUserWidget* InWidget);

	void TechOpen(FormDataC* InForm);
	void TechClose();

};