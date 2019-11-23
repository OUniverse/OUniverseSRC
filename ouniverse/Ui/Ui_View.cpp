//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_View.h"
#include "Ui/Ui_Alpha.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"







UUi_ViewElementData* UUi_ViewElementData::Create(int InUID, UUi_View* InView)
{
	UUi_ViewElementData* Neu = NewObject<UUi_ViewElementData>();
	Neu->UID_ = InUID;
	Neu->View_ = InView;
	return Neu;
}



UViewPanelData* UViewPanelData::Create(int InUID)
{
	UViewPanelData* Neu = NewObject<UViewPanelData>();
	Neu->UID_ = InUID;
	return Neu;
}

void UViewPanelData::Add(int InViewUID, UUi_View* InView)
{
	Views_.Add(InViewUID, UUi_ViewElementData::Create(InViewUID, InView));
}

UUi_ViewElementData* UViewPanelData::GetView(int InViewUID)
{
	return Views_.FindRef(InViewUID);
}

void UViewPanelData::SetViewPanel(UCanvasPanel* InViewPanel)
{
	Viewer_ = InViewPanel;
}


void UViewPanelData::SwitchView(int InViewID)
{

	Pending_ = GetView(InViewID);

	if (Active_ != NULL)
	{
		UUi_View* ActiveView = Active_->View_;
		ActiveView->ViewClose_Mechanism(this);
	}
	else
	{
		ViewCloseComplete();
	}
}


void UViewPanelData::ViewOpenComplete()
{

}

void UViewPanelData::ViewCloseComplete()
{
	if (Active_ != NULL)
	{
		Viewer_->RemoveChild(Active_->View_);
	}

	Active_ = Pending_;

	UUi_View* ActiveView = Active_->View_;
	Viewer_->AddChildToCanvas(ActiveView);
	UCanvasPanelSlot* CanvasSlot = Cast<UCanvasPanelSlot>(ActiveView->Slot);
	CanvasSlot->SetAnchors(FAnchors(0.0f, 0.0f, 1.0f, 1.0f));
	CanvasSlot->SetOffsets(FMargin(0.0f, 0.0f, 0.0f, 0.0f));

	ActiveView->ViewOpen_Mechanism(this);
}
















void UUi_View::StoreParentView(UUi_View* InOwningView)
{
	OwningView_ = InOwningView;
	Alpha_ = OwningView_->Alpha();
}


UUi_Alpha* UUi_View::Alpha()
{
	return Alpha_;
}

UWorld* UUi_View::Scope()
{
	return Alpha_->Scope();
}

bool UUi_View::ViewOpen_Mechanism(UViewPanelData* InViewPanel)
{
	ViewOpen(InViewPanel);
	return false;
}

void UUi_View::ViewOpen_Implementation(UViewPanelData* InViewPanel)
{

}

void UUi_View::ViewClose_Mechanism(UViewPanelData* InViewPanel)
{
	ViewClose(InViewPanel);
}

void UUi_View::ViewClose_Implementation(UViewPanelData* InViewPanel)
{
	InViewPanel->ViewCloseComplete();
}





void UUi_View::AddViewPanel(int Index)
{
	Panels_.Add(Index, UViewPanelData::Create(Index));
}

void UUi_View::AddView(int InPanelUID, int InViewUID, UUi_View* InView)
{
	GetPanel(InPanelUID)->Add(InViewUID, InView);
}

void UUi_View::SetViewPanel(int InPanelUID, UCanvasPanel* InViewPanel)
{
	GetPanel(InPanelUID)->SetViewPanel(InViewPanel);
}


UViewPanelData* UUi_View::GetPanel(int InPanelUID)
{
	return Panels_.FindRef(InPanelUID);
}


void UUi_View::SwitchView(int InPanelID, int InViewID)
{
	GetPanel(InPanelID)->SwitchView(InViewID);
}