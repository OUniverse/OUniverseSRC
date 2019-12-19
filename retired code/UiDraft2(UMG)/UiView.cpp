//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiView.h"
#include "System/Scope.h"
#include "Ui/UiAlpha.h"





ViewPanelS::ViewPanelS(int InUID)
{
	Active_ = -1;
	UID_ = InUID;
}

void ViewPanelS::Add(int InViewUID, UUiView* InView)
{
	Views_.Add(InViewUID, InView);
	InView->OwningViewPanel_ = this;
}

UUiView* ViewPanelS::GetView(int InViewUID)
{
	return Views_.Find(InViewUID);
}


void ViewPanelS::SwitchView(int InViewID)
{

	Pending_ = InViewID;

	if (Active_ != -1)
	{
		UUiView* CurrentView = GetView(InViewID);
		CurrentView->ViewClose_Mechanism();
	}
	else
	{
		ViewCloseComplete();
	}
}


void ViewPanelS::ViewOpenComplete()
{

}

void ViewPanelS::ViewCloseComplete()
{
	UUiView* CurrentView;

	if (Active_ != -1)
	{
		CurrentView = GetView(Active_);
		CurrentView->SetVisibility(ESlateVisibility::Collapsed);
		CurrentView->ViewClose_Technical();
		CurrentView->ViewClose_AutoTechnical();
	}

	Active_ = Pending_;

	CurrentView = GetView(Active_);
	CurrentView->SetVisibility(ESlateVisibility::SelfHitTestInvisible);
	CurrentView->ViewOpen_Technical();
	CurrentView->ViewOpen_AutoTechnical();
	CurrentView->ViewOpen_Mechanism();
}















void UUiView::ConstructView(UUiView* InOwningView)
{
	ConstructEl();
	OwningView_ = InOwningView;
}

bool UUiView::ViewOpen_Mechanism()
{
	ViewOpen();
	return false;
}

void UUiView::ViewOpen_Implementation()
{

}

void UUiView::ViewClose_Mechanism()
{
	ViewClose();
}

void UUiView::ViewClose_Implementation()
{
	OwningViewPanel_->ViewCloseComplete();
}





void UUiView::AddViewPanel(int Index)
{
	Panels_.Add(Index, ViewPanelS(Index));
}

void UUiView::AddView(int InPanelUID, int InViewUID, UUiView* InView)
{

	GetPanel(InPanelUID)->Add(InViewUID, InView);
}

ViewPanelS* UUiView::GetPanel(int InPanelUID)
{
	return &Panels_.Find(InPanelUID);
}


void UUiView::SwitchView(int InPanelID, int InViewID)
{
	GetPanel(InPanelID)->SwitchView(InViewID);
}


void UUiView::InterfacesInit(int InMax)
{
	Interfaces_.Init(InMax, NULL);
}

void UUiView::InterfacesAdd(int Index, UUiEl* InInterface)
{
	Interfaces_[Index] = InInterface;
}

void UUiView::InterfacesActivate(int Index)
{
	ActiveInterface_ = Interfaces_[Index];
	ControlRelay(ActiveInterface_);
}