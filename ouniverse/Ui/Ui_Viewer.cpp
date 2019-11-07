//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Viewer.h"
#include "Ui/Ui_Alpha.h"
#include "Ui/Ui_ViewPanel.h"

ViewTabS::ViewTabS(int InUID, UUi_Opt* InOpt, TSubclassOf<UUi_View> InViewClass, bool InPersists)
{
	View_ = NULL;
	UID_ = InUID;
	Opt_ = InOpt;
	ViewClass_ = InViewClass;
	Persists_ = InPersists;
}



UUi_Viewer* UUi_Viewer::Create(UUi_View* InView)
{
	UUi_Viewer* Neu = NewObject<UUi_Viewer>();
	Neu->Init(InView);
	return Neu;

}

void UUi_Viewer::Init(UUi_View* InView)
{
	View_ = InView;
}

void UUi_Viewer::SetViewPanel(UUi_ViewPanel* InViewPanel)
{
	ViewPanel_ = InViewPanel;
	ViewPanel_->Init();
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

void UUi_Viewer::SwitchView(int InUID, bool InOpenFirst)
{
	ViewTabS* Tab;

	if (!TryTabByID(InUID, Tab))
	{
		return;
	}

	Pending_ = Tab;
	UUi_View* Neu = CreateWidget<UUi_View>(View_->Alpha()->Scope(), Tab->ViewClass_);
	Neu->InitFromViewer_Internal(View_);
	ViewPanel_->Add(Neu);
	Pending_->View_ = Neu;

	if (Active_)
	{
			Active_->View_->CloseView_Internal(this);
	}
	else
	{
		CloseComplete();
	}
}


void UUi_Viewer::OpenComplete()
{

}

void UUi_Viewer::CloseComplete()
{
	Pending_->View_->OpenView_Internal(this);
	Active_ = Pending_;
}


void UUi_Viewer::AddTab(int InUID, UUi_Opt* InOpt, TSubclassOf<UUi_View> InViewClass, bool InPersists)
{
	ViewTabS NewViewTab = ViewTabS(InUID, InOpt, InViewClass, InPersists);
	Tabs_.Add(NewViewTab);
}