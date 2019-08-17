//Copyright 2015-2019, All Rights Reserved.

#include "System/InputCatch.h"
#include "System/InputManager.h"
#include "Widgets/SOverlay.h"
#include "Widgets/Text/STextBlock.h"

void SInputCatch::Construct(const FArguments& InArgs)
{
	GameHUD = InArgs._GameHUD;
	ChildSlot
	.VAlign(VAlign_Fill)
	.HAlign(HAlign_Fill)
	[
		SNew(SOverlay)
		+ SOverlay::Slot()
		.VAlign(VAlign_Fill)
		.HAlign(HAlign_Fill)
		//[
			 //Inside lies a text block with these settings
		//	SNew(STextBlock)
		//	.ShadowColorAndOpacity(FLinearColor::Black)
		//	.ColorAndOpacity(FLinearColor::Red)
		//	.ShadowOffset(FIntPoint(-1, 1)) 
		//	.Font(FSlateFontInfo("Veranda", 36))
                        // localized text to be translated with a generic name HelloSlateText
		//	.Text(FText::FromString(TEXT("InputBridge")))
		//]
	];
}

FReply SInputCatch::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	InputRelay->OnKeyDown(MyGeometry,InKeyEvent);
	return FReply::Handled();
}

FReply SInputCatch::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("KeyUp"));
	InputRelay->OnKeyUp(MyGeometry, InKeyEvent);
	return FReply::Handled();
}

FReply SInputCatch::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
	InputRelay->OnKeyChar(MyGeometry, InCharacterEvent);
	return FReply::Handled();
}

FReply SInputCatch::OnMouseButtonDown(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, MouseEvent.GetEffectingButton().ToString());
	InputRelay->OnMouseButtonDown(MyGeometry,MouseEvent);
	return FReply::Handled();
}

FReply SInputCatch::OnMouseButtonUp(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	InputRelay->OnMouseButtonUp(MyGeometry,MouseEvent);
	return FReply::Handled();
}

FReply SInputCatch::OnMouseButtonDoubleClick(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	InputRelay->OnMouseButtonDoubleClick(MyGeometry, MouseEvent);
	return FReply::Handled();
}

FReply SInputCatch::OnMouseMove(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("MouseMove"));

	if (InputRelay!=NULL)
	{
		InputRelay->OnMouseMove(MyGeometry,MouseEvent);
	}
	return FReply::Handled();
}

FReply SInputCatch::OnMouseWheel(const FGeometry & MyGeometry, const FPointerEvent & MouseEvent)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, TEXT("MouseWheel"));
	InputRelay->OnMouseWheel(MyGeometry,MouseEvent);
	return FReply::Handled();
}

//This is required to overide the UE4 function to enable keyboard forcus.
bool SInputCatch::SupportsKeyboardFocus() const
{
	return true;
}