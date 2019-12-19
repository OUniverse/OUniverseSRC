//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymLoadoutSelectU_Solodex.h"

#include "Components/TextBlock.h"

#include "Protocol/Focus.h"

#include "System/InputID.h"
#include "System/LoadoutLib.h"
#include "System/Loadout.h"

#include "Min/DebugM.h"

void USymLoadoutSelect_Solodex::NativeConstruct()
{
	UserIndex_ = 0;
}

void USymLoadoutSelect_Solodex::UiConstruct(SymLoadoutSelectP* InPro, LoadoutLibC* InLoadoutLib)
{
	Pro_ = InPro;
	LoadoutLib_ = InLoadoutLib;
}

bool USymLoadoutSelect_Solodex::InputCommand(KeyS InKey)
{

	switch (InKey.Command) {
	case InputID::Up_D:
		RollUp();
		return true;
	case InputID::Down_D:
		RollDown();
		return true;
	case InputID::Accept_D:
		Accept();
		return true;
	case InputID::Cancel_D:
		Focus_->Call(LeyS::Dir::Cancel);
		return true;
	case InputID::Left_D:
		Focus_->Call(LeyS::Dir::Left);
		return true;
	case InputID::Right_D:
		Focus_->Call(LeyS::Dir::Right);
		return true;
	}

	return false;
}

void USymLoadoutSelect_Solodex::RollUp()
{
	UserIndex_--;
	if (UserIndex_ < 0)
	{
		UserIndex_ = LoadoutLib_->Num() - 1;
	}
	RefreshUser(EDirection::Down);
}

void USymLoadoutSelect_Solodex::RollDown()
{
	UserIndex_++;
	if (UserIndex_ >= LoadoutLib_->Num())
	{
		UserIndex_ = 0;
	}
	RefreshUser(EDirection::Up);
}

void USymLoadoutSelect_Solodex::Accept()
{

}

void USymLoadoutSelect_Solodex::RefreshUser(EDirection Direction)
{
	LoadoutC* Loadout = LoadoutLib_->GetLoadout(UserIndex_);
	Update(Direction, Loadout->ID().ToFText(), StringC(555).ToFText());
}