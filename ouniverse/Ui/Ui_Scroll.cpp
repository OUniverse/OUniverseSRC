//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Scroll.h"
#include "Ui/Ui_ScrollEl.h"
#include "Components/SizeBox.h"
#include "Components/VerticalBox.h"
#include "Components/CanvasPanelSlot.h"
#include "Input/Reply.h"

#include "Mathz/Modulo.h"

#include "Min/DebugM.h"

void UUi_Scroll::NativeConstruct()
{
	CenteredElement = NULL;
	ScrollOffset = 0.0f;
	CaseSlot = Cast<UCanvasPanelSlot>(V_Case->Slot);
	Super::NativeConstruct();
}

void UUi_Scroll::AddEntry(UUi_ScrollEl* InEntry)
{
	V_Case->AddChild(InEntry);
	InEntry->SetParentScroll(this);
	Entries_.Add(InEntry);
}


void UUi_Scroll::Build()
{
	MeasureInside();
	MeasureOutside();
}

void UUi_Scroll::ClearChildren()
{
	//V_Scroll->ClearChildren();
}

void UUi_Scroll::MeasureInside()
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

void UUi_Scroll::MeasureOutside()
{
	OuterHeight = 0.0f;
	OuterHeight = GetCachedGeometry().GetLocalSize().Y;
}


FReply UUi_Scroll::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{ 
	bScrolling = true;
	ScrollPosSaver = MouseEvent.GetScreenSpacePosition();
	return FReply::Handled();
}

FReply UUi_Scroll::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bScrolling = false;
	return FReply::Handled();
}

FReply UUi_Scroll::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
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

void UUi_Scroll::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	float GeometryHeight = MyGeometry.GetLocalSize().Y;
	if (OuterHeight != GeometryHeight)
	{
		MeasureOutside();
	}
}

void UUi_Scroll::CalcCenter()
{
	ModuloFloatS Modulus = ModuloC::ModuloFloat(ScrollOffset, SemSize);

	float Center = ScrollOffset+(OuterHeight/2);

	int CenteredIndex = ModuloC::Quotient(Center,SemSize);

	UUi_ScrollEl* CurrentCentered = Entries_[CenteredIndex];
	
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

void UUi_Scroll::SemStyle()
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