//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/System/Ui/SymUserSelectU_Solodex.h"

#include "Components/TextBlock.h"
#include "Ui/UiButton.h"

#include "Protocol/Focus.h"

#include "System/InputID.h"
#include "System/UserLib.h"
#include "System/User.h"

#include "Min/DebugM.h"

void USymUserSelect_Solodex::NativeConstruct()
{
	UserIndex_ = 0;
}

void USymUserSelect_Solodex::UiConstruct(SymUserSelectP* InPro, UserLibC* InUserLib)
{
	Pro_ = InPro;
	UserLib_ = InUserLib;
}

bool USymUserSelect_Solodex::InputCommand(KeyS InKey)
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

void USymUserSelect_Solodex::RollUp()
{
	UserIndex_--;
	if (UserIndex_ < 0)
	{
		UserIndex_ = UserLib_->Num() - 1;
	}
	RefreshUser(EDirection::Down);
}

void USymUserSelect_Solodex::RollDown()
{
	UserIndex_++;
	if (UserIndex_ >= UserLib_->Num())
	{
		UserIndex_ = 0;
	}
	RefreshUser(EDirection::Up);
}

void USymUserSelect_Solodex::Accept()
{

}

void USymUserSelect_Solodex::RefreshUser(EDirection Direction)
{
	UserC* User = UserLib_->GetUser(UserIndex_);
	Update(Direction, User->ID().ToFText(), StringC(User->Score()).ToFText());
}