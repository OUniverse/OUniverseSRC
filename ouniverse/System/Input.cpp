//Copyright 2015-2019, All Rights Reserved.

#include "System/Input.h"

#include "Min/DebugM.h"

InputReplyS::InputReplyS()
{
	Handled_ = false;
}

InputReplyS::InputReplyS(bool InHandled)
{
	Handled_ = InHandled;
}

void InputReplyS::Set(bool InHandled)
{
	Handled_ = InHandled;
}

bool InputReplyS::Handled()
{
	return Handled_;
}

InputActionS::InputActionS()
{
	CTR_ = false;
	ALT_ = false;
	SHIFT_ = false;
	HELP_ = false;
}

InputActionS::InputActionS(bool InPress, bool InCTR, bool InALT, bool InSHIFT, bool InHelp)
{
	Press_ = InPress;
	CTR_ = InCTR;
	ALT_ = InALT;	
	SHIFT_ = InSHIFT;
	HELP_ = InHelp;
}

void InputActionS::SetAction(InputC::Action InAction)
{
	Action_ = InAction;
}

void InputActionS::SetPress(bool InPress)
{
	Press_ = InPress;
}
void InputActionS::SetCTR(bool InPress)
{
	CTR_ = InPress;
}

void InputActionS::SetALT(bool InPress)
{
	ALT_ = InPress;
}
void InputActionS::SetSHIFT(bool InPress)
{
	SHIFT_ = InPress;
}

void InputActionS::SetHELP(bool InPress)
{
	HELP_ = InPress;
}

int InputActionS::Action()
{
	return Action_;
}

bool InputActionS::Pressed()
{
	return Press_;
}

bool InputActionS::CTR()
{
	return CTR_;
}

bool InputActionS::ALT()
{
	return ALT_;
}

bool InputActionS::Shift()
{
	return SHIFT_;
}

bool InputActionS::Help()
{
	return HELP_;
}




InputSchemaStackC::InputSchemaStackC()
{
	Len_ = 0;
}


void InputSchemaStackC::Add(InputSchemaC* InSchema)
{
	Len_++;
	Stack_.Add(InSchema);
}

InputReplyS InputSchemaStackC::Process(InputReplyS(InputSchemaC::* PTR)(InputActionS), InputActionS InIA)
{
	for (int i = Len_-1; i > -1; i--)
	{
		InputReplyS Reply = (Stack_[i]->*PTR)(InIA);
		
		if (Reply.Handled() == true)
		{
			return true;
		}
	}

	return false;
}


InputReplyS InputSchemaStackC::MouseR(InputActionS InIA)
{
	return InputReplyS();
}

InputReplyS InputSchemaStackC::MouseL(InputActionS InIA)
{
	return Process(&InputSchemaC::MouseL,InIA);
}

InputReplyS InputSchemaStackC::MouseM(InputActionS InIA)
{
	return Process(&InputSchemaC::MouseL, InIA);
}

InputReplyS InputSchemaStackC::Forward(InputActionS InIA)
{
	return Process(&InputSchemaC::Forward, InIA);
}
InputReplyS InputSchemaStackC::Back(InputActionS InIA)
{
	return Process(&InputSchemaC::Back, InIA);
}
InputReplyS InputSchemaStackC::Left(InputActionS InIA)
{
	return Process(&InputSchemaC::Left, InIA);
}
InputReplyS InputSchemaStackC::Right(InputActionS InIA)
{
	return Process(&InputSchemaC::Right, InIA);
}

InputReplyS InputSchemaStackC::Selector0(InputActionS InIA)
{
	return Process(&InputSchemaC::Selector0, InIA);
}
InputReplyS InputSchemaStackC::Selector1(InputActionS InIA)
{
	return Process(&InputSchemaC::Selector1, InIA);
}
InputReplyS InputSchemaStackC::Selector2(InputActionS InIA)
{
	return Process(&InputSchemaC::Selector2, InIA);
}

InputReplyS InputSchemaStackC::Selector3(InputActionS InIA)
{
	return Process(&InputSchemaC::Selector3, InIA);
}

InputReplyS InputSchemaStackC::Interact(InputActionS InIA)
{
	return Process(&InputSchemaC::Interact, InIA);
}
InputReplyS InputSchemaStackC::Jump(InputActionS InIA)
{
	return Process(&InputSchemaC::Jump, InIA);
}

InputReplyS InputSchemaStackC::Console(InputActionS InIA)
{
	return Process(&InputSchemaC::Console, InIA);
}
InputReplyS InputSchemaStackC::PrintScreen(InputActionS InIA)
{
	return Process(&InputSchemaC::PrintScreen, InIA);
}

InputReplyS InputSchemaStackC::Escape(InputActionS InIA)
{
	return Process(&InputSchemaC::Escape, InIA);
}