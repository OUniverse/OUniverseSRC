//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiScroll.h"
#include "Ui/UiScrollEl.h"
#include "Ui/UiBase.h"
#include "Components/SizeBox.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanelSlot.h"

#include "System/InputID.h"

#include "Mathz/Modulo.h"

#include "Ui/UiStatics.h"

#include "Min/DebugM.h"


UiScrollAnimationS::UiScrollAnimationS()
{
	Exists_ = false;
	Start_ = 0.0;
	Goal_ = 0.0;
	Time_ = 0.0;
	Delta_ = 0.0;
};

UiScrollAnimationS::UiScrollAnimationS(UUiScroll* InScroll, float InStart, float InGoal, float InTime)
{
	Exists_ = true;
	Start_ = InStart;
	Scroll_ = InScroll;
	Goal_ = InGoal;
	Time_ = InTime;
	Delta_ = 0.0;
	
};

void UiScrollAnimationS::Tick(float InDeltaTime)
{
	//Scroll_->ScrollOffset = FMath::FInterpTo(Scroll_->ScrollOffset, Goal_, InDeltaTime, Speed_);
	//FMargin NewMargins = FMargin(0.0f, Scroll_->ScrollOffset * -1, 0.0f, 0.0f);
	//Scroll_->CaseSlot->SetOffsets(NewMargins);

	Delta_ += InDeltaTime;

	DBUG(FFS(Delta_))

	if (Delta_ >= Time_)
	{
		
		Scroll_->ScrollOffset = Goal_;
		Exists_ = false;
	}
	else
	{
		float DeltaCurveStretch = Delta_ / Time_;
		float Gap = Goal_ - Start_;
		float Pos = (Scroll_->AnimationCurve->GetFloatValue(DeltaCurveStretch)*Gap);
		Scroll_->ScrollOffset = Start_ + Pos;

	}

	FMargin NewMargins = FMargin(0.0f, Scroll_->ScrollOffset * -1, 0.0f, 0.0f);
	Scroll_->CaseSlot->SetOffsets(NewMargins);

}

bool UiScrollAnimationS::Exists()
{
	return Exists_;
}


void UUiScroll::NativeConstruct()
{
	CenteredElement = NULL;
	ScrollOffset = 0.0f;
	CaseSlot = Cast<UCanvasPanelSlot>(V_Case->Slot);
	Super::NativeConstruct();
}

void UUiScroll::Init(int InElementID, UUiBase* InParent)
{
	//SetElementID(InElementID);
	Parent_ = InParent;
}

void UUiScroll::AddEntry(UUiScrollEl* InEntry)
{
	V_Case->AddChild(InEntry);
	InEntry->SetParentScroll(this);
	Entries_.Add(InEntry);
}


void UUiScroll::Build()
{
	MeasureInside();
	MeasureOutside();
}

void UUiScroll::ClearChildren()
{
	//V_Scroll->ClearChildren();
}

void UUiScroll::MeasureInside()
{
	ForceLayoutPrepass();
	TArray<UWidget*> Children = V_Case->GetAllChildren();
	int L = Children.Num();

	InnerHeight = 0.0f;

	for (int i = 0; i < L; i++)
	{
		InnerHeight+= Children[i]->GetDesiredSize().Y;
	}

	if (L != 0)
	{
		SemSize = Children[0]->GetDesiredSize().Y;
	}
}

void UUiScroll::MeasureOutside()
{
	OuterHeight = 0.0f;
	OuterHeight = GetCachedGeometry().GetLocalSize().Y;
}


FReply UUiScroll::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{ 
	bScrolling = true;
	ScrollPosSaver = MouseEvent.GetScreenSpacePosition();
	return FReply::Handled();
}

FReply UUiScroll::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bScrolling = false;
	return FReply::Handled();
}

FReply UUiScroll::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bIsFocusable = true;
	UUiStatics::FocusWidget(this);

	if (bScrolling)
	{
		FReply Reply = FReply::Handled();
		ScrollOffset = ScrollOffset - (MouseEvent.GetScreenSpacePosition().Y - ScrollPosSaver.Y);

		//DBUG(IFS(ScrollOffset))
		if (ScrollOffset < 0)
		{
			ScrollOffset = 0;
		}

		if (ScrollOffset > (InnerHeight-OuterHeight))
		{
			ScrollOffset = (InnerHeight-OuterHeight);
		}

		SemStyle();//Has to be after ScrollOffset is normalized, otherwise -1 gets passed into the array.
		CalcCenter();

		Reply.SetMousePos(FIntPoint(ScrollPosSaver.X, ScrollPosSaver.Y));

		FMargin NewMargins = FMargin(0.0f, ScrollOffset*-1, 0.0f, 0.0f);

		CaseSlot->SetOffsets(NewMargins);

		return Reply;
	}

	return FReply::Handled();
}

void UUiScroll::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	float GeometryHeight = MyGeometry.GetLocalSize().Y;
	if (OuterHeight != GeometryHeight)
	{
		MeasureOutside();
	}

	if (Animation.Exists())
	{
		Animation.Tick(InDeltaTime);
		SemStyle();
	}
}

void UUiScroll::CalcCenter()
{
	ModuloFloatS Modulus = ModuloC::ModuloFloat(ScrollOffset, SemSize);

	float Center = ScrollOffset+(OuterHeight/2);

	CenteredIndex = ModuloC::Quotient(Center,SemSize);

	UUiScrollEl* CurrentCentered = Entries_[CenteredIndex];
	
	if (CenteredElement == NULL)
	{
		CenteredElement = CurrentCentered;
		CenteredElement->Centered_Mechanism();
	}
	else
	{
		if (CenteredElement != CurrentCentered)
		{
			CenteredElement->Uncentered_Mechanism();
			CenteredElement = CurrentCentered;
			CenteredElement->Centered_Mechanism();
		}
	}

}

void UUiScroll::SemStyle()
{

	ModuloFloatS Modulus = ModuloC::ModuloFloat(ScrollOffset, SemSize);

	int VisibleCount = ModuloC::Quotient(OuterHeight, SemSize)+1;


	//If the very last entry is rolled to and makes a perfect float division it procs an extra box that doesn't exit
	//This protects from that...

	int AccessedMaxIndex = Modulus.Quotient() + VisibleCount;

	if (AccessedMaxIndex <= Entries_.Len())
	{

		int ShowableCount = VisibleCount - 2;
		int StartingPoint = Modulus.Quotient();
		int RatioPer = (100 / ShowableCount);

		Entries_[StartingPoint]->UpdateStyleByViewPosition(0.0f);

		for (int i = 0; i < ShowableCount; i++)
		{
			Entries_[StartingPoint + 1 + i]->UpdateStyleByViewPosition((i + (1 - Modulus.PercentRemainder())) * RatioPer);
		}

		Entries_[StartingPoint + 1 + ShowableCount]->UpdateStyleByViewPosition(0.0f);
	}

}


bool UUiScroll::InputCommand(KeyS InKey)
{


	//if (InputMode_ != InputMode::Control){ControlMode();}

	switch (InKey.Command) {
	case InputID::Up_U:
		DBUG("ScrollUP")
		return true;

	case InputID::Down_U:
		DBUG("ScrollDown")
		Animation = UiScrollAnimationS(this, ScrollOffset, 50.0f, 0.25f);
		return true;

	case InputID::Left_U:
		//Parent_->UiPathRequest(GetElementID(), PathLeft.Type(), PathLeft.Var());
		return true;

	case InputID::Right_U:
		//Parent_->UiPathRequest(GetElementID(), PathRight.Type(), PathRight.Var());
		return true;

	case InputID::Accept_U:
		DBUG("ScrollAccept")
		return true;

	case InputID::Cancel_U:
		//Parent_->UiPathRequest(GetElementID(), PathCancel.Type(), PathCancel.Var());
		return true;
	}

	return false;
}


void UUiScroll::ControlMode()
{
	DBUG("ENTER CONTROL MODE")
}

void UUiScroll::MouseMode()
{

}