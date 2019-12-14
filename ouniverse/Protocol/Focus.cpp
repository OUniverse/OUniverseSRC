//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/Focus.h"
#include "Protocol/Protocol.h"
#include "Ui/UiFocus.h"

#include "Min/DebugM.h"

FocusC::FocusC(int InID, ProtocolC* InProtocol)
{
	ID_ = InID;
	Protocol_ = InProtocol;
	Paths_.Init(LeyS::Dir::DIR_MAX, LeyS());

}

int FocusC::ID()
{
	return ID_;
}

void FocusC::Call(int InDir)
{
	
	LeyS* Ley = &Paths_[InDir];
	switch (Ley->Type_) {
	case LeyS::Type::Move:
		Protocol_->FocalActivate(Ley->Var_);
		break;
	case LeyS::Type::Event:
		Protocol_->EventCode(ID(), Ley->Var_, InDir);
		break;
	}
}

void FocusC::SetPath(LeyS::Dir InDir, LeyS::Type InType, int InVar)
{
	LeyS* Path = &Paths_[InDir];
	Path->Type_ = InType;
	Path->Var_ = InVar;
}


FocusDockC::FocusDockC(int InID, ProtocolC* InProtocol) : FocusC(InID, InProtocol)
{

}

void FocusDockC::Set(FluxDockC* InDock)
{
	Dock_ = InDock;
}

bool FocusDockC::InputCommand(KeyS InKey)
{
	return Dock_->InputCommand(InKey);
}




FocusUiC::FocusUiC(int InID, ProtocolC* InProtocol) : FocusC(InID, InProtocol)
{

}

void FocusUiC::Set(UUiFocus* InFocus)
{
	InFocus->SetupFocus(this);
	Focus_ = InFocus;
}

bool FocusUiC::InputCommand(KeyS InKey)
{
	return Focus_->InputCommand(InKey);
}


FocusUiRackC::FocusUiRackC(int InID, ProtocolC* InProtocol, bool InLoop, bool InHorizontal) : FocusUiC(InID, InProtocol)
{
	ActiveFocus_ = NULL;
	Index_ = 0;
	bLoop = InLoop;
	bHorizontal = InHorizontal;
}

void FocusUiRackC::Add(UUiFocus* InFocus, int ID)
{
	InFocus->SetupFocus(this);
	Focus_.Add(FocusUiRackDataS(InFocus,ID));
}

void FocusUiRackC::Reset()
{
	Focus_.Clear();
}

void FocusUiRackC::Call(int InDir)
{
	LeyS* Ley = &Paths_[InDir];

	if (bHorizontal)
	{
		switch (InDir) {
		case LeyS::Dir::Left:
			ShiftDown();
			return;
		case LeyS::Dir::Right:
			ShiftUp();
			return;
		}
	}
	else
	{
		switch (InDir) {
		case LeyS::Dir::Up:
			ShiftDown();
			return;
		case LeyS::Dir::Down:
			ShiftUp();
			return;
		}
	}


}

void FocusUiRackC::ShiftDown()
{
	Index_--;

	if (Index_ < 0)
	{
		Index_ = Focus_.Len() - 1;
	}

	Update();
}

void FocusUiRackC::ShiftUp()
{
	Index_++;

	if (Index_ >= Focus_.Len())
	{
		Index_ = 0;
	}

	Update();
}

void FocusUiRackC::Update()
{
	if (ActiveFocus_ != NULL)
	{
		ActiveFocus_->Unfocus_Mechanism();
	}

	FocusUiRackDataS* Data = &Focus_[Index_];
	ActiveFocus_ = Data->Focus_;
	ActiveFocus_->Focus_Mechanism();

	Protocol_->FocusChanged(Data->ID_);
}

bool FocusUiRackC::InputCommand(KeyS InKey)
{
	return Focus_[Index_].Focus_->InputCommand(InKey);
}

void FocusUiRackC::Focus()
{
	Update();
}

void FocusUiRackC::Unfocus()
{
	ActiveFocus_->Unfocus_Mechanism();
}