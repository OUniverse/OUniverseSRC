//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_View.h"
#include "Components/CanvasPanelSlot.h"

void UUi_View::CreateViewer()
{
	Viewer_ = UUi_Viewer::Create(this);
}

UUi_Viewer* UUi_View::Viewer()
{
	return Viewer_;
}


void UUi_View::ViewerBind(UUi_View* InView, UUi_Opt* InOpt)
{
	Viewer_->Bind(InOpt->ViewUID_, InView, InOpt);
}

void UUi_View::ViewerSwitch(int InUID)
{
	Viewer_->SwitchView(InUID);
}

void UUi_View::SetMaster(UUi_Master* InMax)
{
	Master_ = InMax;
}

UUi_Master* UUi_View::Master()
{
	return Master_;
}

void UUi_View::SetupForDefaultCanvas()
{
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
	SetVisibility(ESlateVisibility::Hidden);
}


bool UUi_View::OpenView_Internal()
{
	OpenView();
	return false;
}

void UUi_View::OpenView_Implementation()
{

}

bool UUi_View::CloseView_Internal(UUi_Viewer* InViewer)
{
	bool bCancel = false;
	CloseView(InViewer,bCancel);
	return false;
}

void UUi_View::CloseView_Implementation(UUi_Viewer* InViewer, bool& bCancel)
{
	
}





ViewTabS::ViewTabS(int InUID, UUi_Opt* InOpt, UUi_View* InView)
{
	UID_ = InUID;
	Opt_ = InOpt;
	View_ = InView;
}



UUi_Viewer* UUi_Viewer::Create(UUi_View* InView)
{
	UUi_Viewer* Neu = NewObject<UUi_Viewer>();
	Neu->View_ = InView;
	return Neu;
}

void UUi_Viewer::Bind(int InUID, UUi_View* InView, UUi_Opt* InOpt)
{
	Tabs_.Add(ViewTabS(InUID, InOpt, InView));
}

bool UUi_Viewer::TryTabByID(int InUID, ViewTabS*& InTab)
{

	int L = Tabs_.Len();
	
	for (int i = 0; i < L; i++)
	{
		if (Tabs_[i].UID_ == InUID)
		{
			InTab = &Tabs_[i];
			return true;
		}
	}

	return false;
}

void UUi_Viewer::SwitchView(int InUID)
{
	ViewTabS* Try;

	if (!TryTabByID(InUID, Try))
	{
		return;
	}

	Pending_ = Try;

	if (Active_)
	{
		Active_->View_->CloseView_Internal(this);
	}
	else
	{
		CloseComplete();
	}
}

void UUi_Viewer::CloseComplete()
{
	Pending_->View_->OpenView_Internal();
	Active_ = Pending_;
}