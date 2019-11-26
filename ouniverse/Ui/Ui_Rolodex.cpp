//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_Rolodex.h"
#include "Components/VerticalBox.h"
#include "Components/SizeBox.h"
#include "Ui/Ui_RolodexEl.h"

#include "Min/DebugM.h"

void UUi_Rolodex::NativeConstruct()
{
	Super::NativeConstruct();
}


void UUi_Rolodex::AddEntry(UUi_RolodexEl* InRolodexEl)
{
	Entries_.Emplace(InRolodexEl);
}

void UUi_Rolodex::Build()
{

	SideCount = (DisplayCount - 1) / 2;

	
	Steps.Clear();

	
	float Per = 100 / (SideCount+1);

	for (int i = 1; i <= SideCount; i++)
	{	
		Steps.Add(Per*i);
	}


	
	ActiveEntries_.Clear();

	for (int i = 0; i < DisplayCount; i++)
	{
		V_Case->InsertChildAt(i+1,Entries_[i]);
		ActiveEntries_.Add(Entries_[i]);
	}
	
	float CapsSize = SizeCurve->GetFloatValue(0.0);
	float CapsOpacity = OpacityCurve->GetFloatValue(0.0);
	V_Top->SetHeightOverride(CapsSize);
	V_Bot->SetHeightOverride(CapsSize);
	V_Top->SetHeightOverride(CapsOpacity);
	V_Bot->SetHeightOverride(CapsOpacity);
	/**
	ActiveEntries_[0]->SetHeight(MaxSize * Calcs[1] / 100);
	ActiveEntries_[1]->SetHeight(MaxSize * Calcs[2] / 100);
	ActiveEntries_[2]->SetHeight(MaxSize);
	ActiveEntries_[3]->SetHeight(MaxSize * Calcs[2] / 100);
	ActiveEntries_[4]->SetHeight(MaxSize * Calcs[1] / 100);
	*/

	float SizeMod;
	float OpacityMod;

	for (int i = 0; i < SideCount; i++)
	{

		SizeMod = SizeCurve->GetFloatValue(Steps[i]);
		OpacityMod = OpacityCurve->GetFloatValue(Steps[i]);
		ActiveEntries_[i]->SetHeight(SizeMod);
		ActiveEntries_[DisplayCount-i-1]->SetHeight(SizeMod);
		ActiveEntries_[i]->SetRenderOpacity(OpacityMod);
		ActiveEntries_[DisplayCount - i - 1]->SetRenderOpacity(OpacityMod);
	}

	//ActiveEntries_[2]->SetHeight(MaxSize);



	ActiveEntries_[SideCount]->SetHeight(SizeCurve->GetFloatValue(100.0));
	ActiveEntries_[SideCount]->SetRenderOpacity(OpacityCurve->GetFloatValue(100.0));
}

void UUi_Rolodex::Forward()
{
	DBUG("FORWARARRARARA")
	bAnimating = true;
	bDirection = true;
}

void UUi_Rolodex::Backward()
{
	bAnimating = true;
	bDirection = false;
}

void UUi_Rolodex::MoveComplete()
{
	bAnimating = false;
}

void UUi_Rolodex::NativeTick(const FGeometry& MyGeometry, float InDeltaTime)
{
	if (bAnimating)
	{
		for (int i = 0; i <= DisplayCount; i++)
		{
			//V_Case->GetChildAt(i)->Animate;
		}
	}

}