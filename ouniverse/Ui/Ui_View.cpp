//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_View.h"
#include "Ui/Ui_Viewer.h"
#include "Ui/Ui_Alpha.h"


void UUi_View::SetView(UUi_View* InOwningView)
{
	OwningView_ = InOwningView;
	Alpha_ = OwningView_->Alpha();
}

void UUi_View::CreateViewer()
{
	Viewer_ = UUi_Viewer::Create(this);
}

void UUi_View::InitFromViewer_Internal(UUi_View* InOwningView)
{
	SetView(InOwningView);
	InitFromViewer();
}

void UUi_View::InitFromViewer()
{

}

void UUi_View::SwitchView(int InUID, bool InOpenFirst)
{
	Viewer_->SwitchView(InUID, InOpenFirst);
}

UUi_Alpha* UUi_View::Alpha()
{
	return Alpha_;
}



UWorld* UUi_View::Scope()
{
	return Alpha_->Scope();
}

bool UUi_View::OpenView_Internal(UUi_Viewer* InViewer)
{
	OpenView(InViewer);
	return false;
}

void UUi_View::OpenView_Implementation(UUi_Viewer* InViewer)
{

}

void UUi_View::CloseView_Internal(UUi_Viewer* InViewer)
{
	CloseView(InViewer);
}

void UUi_View::CloseView_Implementation(UUi_Viewer* InViewer)
{
	SetVisibility(ESlateVisibility::Hidden);
	InViewer->CloseComplete();
}