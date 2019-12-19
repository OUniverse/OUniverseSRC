//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Ui/UiFocus.h"
#include "Interface/Array.h"
#include "WriFormU_PortRack.generated.h"


class UUiBool;
class UVerticalBox;

class UWriForm_Port;
class FormDataC;

class WriFormIsoP;

struct WriFormPortS
{
	FormDataC* Data;
	WriFormIsoP* Iso;
};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UWriForm_PortRack : public UUiFocus
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;

	void UiConstruct();

	void OpenForm(FormDataC* InForm);

	int PortTotal_;
	int OpenNum_;

	ArrayC<FormDataC*> OpenForms_;

	ArrayC<UWriForm_Port*> Ports_;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vPanel;

	void PortClose(UWriForm_Port* InPort);

	void Rebuild();

};