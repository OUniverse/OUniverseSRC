//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Writer/Ui/WriFormU_PortRack.h"
#include "Protocol/Writer/Ui/WriFormU_Port.h"
#include "System/FormData.h"
#include "Components/VerticalBox.h"


void UWriForm_PortRack::NativeConstruct()
{
	Super::NativeConstruct();

	PortTotal_ = 0;

	TArray<UWidget*> PortChildren = vPanel->GetAllChildren();
	
	PortTotal_ = PortChildren.Num();

	UWriForm_Port* TempPort;

	for (int i = 0; i < PortTotal_; i++)
	{
		TempPort = Cast<UWriForm_Port>(PortChildren[i]);
		Ports_.Add(TempPort);
		TempPort->Init(this);
	}
}

void UWriForm_PortRack::UiConstruct()
{
	OpenNum_ = 0;
}

void UWriForm_PortRack::OpenForm(FormDataC* InForm)
{

	int Seek = OpenForms_.Find(InForm);

	if (Seek == -1)
	{

		InForm->SetOpen(true);
		OpenForms_.Add(InForm);
		Ports_[OpenNum_]->Assign(InForm);
		OpenNum_++;
	}
}

void UWriForm_PortRack::PortClose(UWriForm_Port* InPort)
{
	OpenNum_--;
	OpenForms_.EraseElement(InPort->Form_);
	Rebuild();
}

void UWriForm_PortRack::Rebuild()
{
	for (int i = 0; i < PortTotal_; i++)
	{
		Ports_[i]->TechClose();
	}

	for (int i = 0; i < OpenNum_; i++)
	{
		Ports_[i]->TechOpen(OpenForms_[i]);
	}
}