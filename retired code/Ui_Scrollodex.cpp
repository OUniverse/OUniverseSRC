//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Scrollodex.h"
#include "Components/VerticalBox.h"
#include "Components/SizeBox.h"
#include "Ui/Ui_ScrollodexEl.h"

#include "Min/DebugM.h"

void UUi_Scrollodex::NativeConstruct()
{
	Super::NativeConstruct();
}


void UUi_Scrollodex::AddEntry(UUi_ScrollodexEl* InScrollodexEl)
{
	Entries_.Emplace(InScrollodexEl);
}

void UUi_Scrollodex::Build()
{
	for (int i = 0; i < DisplayCount; i++)
	{
		V_Case->AddChild(Entries_[i]);
		ActiveEntries_.Add(Entries_[i]);
	}
}

void UUi_Scrollodex::Forward()
{
	DBUG("FORWARARRARARA")
	bAnimating = true;
	bDirection = true;
}

void UUi_Scrollodex::Backward()
{
	bAnimating = true;
	bDirection = false;
}

void UUi_Scrollodex::MoveComplete()
{
	bAnimating = false;
}

void UUi_Scrollodex::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (bAnimating)
	{
		for (int i = 0; i <= DisplayCount; i++)
		{
			//V_Case->GetChildAt(i)->Animate;
		}
	}

}


FReply UUi_Scrollodex::NativeOnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	DBUG("FUCKING DOWN");
	bScrolling = true;
	ScrollPosSaver = MouseEvent.GetScreenSpacePosition();
	return FReply::Handled();
}

FReply UUi_Scrollodex::NativeOnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	bScrolling = false;
	return FReply::Handled();
}

FReply UUi_Scrollodex::NativeOnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (bScrolling)
	{
		FReply Reply = FReply::Handled();
		//float Offset = V_Scroll->GetScrollOffset() - (MouseEvent.GetScreenSpacePosition().Y - ScrollPosSaver.Y);

		float Offset = 0;
		if (Offset < 0)
		{
			Offset = 0;
		}

		if (Offset > 2000)
		{
			Offset = 2000;
		}
		//V_Scroll->SetScrollOffset(Offset);
		Reply.SetMousePos(FIntPoint(ScrollPosSaver.X, ScrollPosSaver.Y));

		//FFS(V_Scroll->GetChildAt(0)->GetDesiredSize().Y);
		return Reply;
	}

	return FReply::Handled();
}