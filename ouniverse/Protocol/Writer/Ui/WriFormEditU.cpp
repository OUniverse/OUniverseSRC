//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFormEditU.h"
#include "Protocol/Writer/Ui/WriButtonU.h"

#include "System/FormData.h"

void UWriFormEdit::NativeConstruct()
{
	Super::NativeConstruct();

	vDataMode->SetupButton(REG::RDataMode,this);
	vOutputMode->SetupButton(REG::ROutputMode, this);
	vSave->SetupButton(REG::RSave, this);
	vVerify->SetupButton(REG::RVerify, this);

}

void UWriFormEdit::NativeDestruct()
{

	Super::NativeDestruct();
}

void UWriFormEdit::UiConstruct(WriFormEditP* InPro)
{
	Pro_ = InPro;
}


void UWriFormEdit::OpenForm(FormDataC* InFormData)
{

}