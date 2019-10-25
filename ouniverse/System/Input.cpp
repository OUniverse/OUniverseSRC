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









static UInputBeacon* Create(UInputSchema* InSchema)
{
	UInputBeacon* Obj = NewObject<UInputBeacon>();
	Obj->Set(InSchema);
	return Obj;
}

UInputSchema* UInputBeacon::Get()
{
	return Schema_;
}

void UInputBeacon::Set(UInputSchema* InSchema)
{
	Schema_ = InSchema;
}









UInputSchemaStack::UInputSchemaStack() {}

UInputSchemaStack* UInputSchemaStack::Create()
{
	UInputSchemaStack* Obj = NewObject<UInputSchemaStack>();
	Obj->Init();
	return Obj;
}

void UInputSchemaStack::Init()
{
	Len_ = 0;
}

void UInputSchemaStack::Add(UInputSchema* InSchema)
{
	Len_++;
	Stack_.Emplace(InSchema);
}

InputReplyS UInputSchemaStack::Process(InputReplyS(UInputSchema::* PTR)(InputActionS), InputActionS InIA)
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


InputReplyS UInputSchemaStack::MouseR(InputActionS InIA)
{
	return InputReplyS();
}

InputReplyS UInputSchemaStack::MouseL(InputActionS InIA)
{
	return Process(&UInputSchema::MouseL,InIA);
}

InputReplyS UInputSchemaStack::MouseM(InputActionS InIA)
{
	return Process(&UInputSchema::MouseL, InIA);
}

InputReplyS UInputSchemaStack::Forward(InputActionS InIA)
{
	return Process(&UInputSchema::Forward, InIA);
}
InputReplyS UInputSchemaStack::Back(InputActionS InIA)
{
	return Process(&UInputSchema::Back, InIA);
}
InputReplyS UInputSchemaStack::Left(InputActionS InIA)
{
	return Process(&UInputSchema::Left, InIA);
}
InputReplyS UInputSchemaStack::Right(InputActionS InIA)
{
	return Process(&UInputSchema::Right, InIA);
}

InputReplyS UInputSchemaStack::Selector0(InputActionS InIA)
{
	return Process(&UInputSchema::Selector0, InIA);
}
InputReplyS UInputSchemaStack::Selector1(InputActionS InIA)
{
	return Process(&UInputSchema::Selector1, InIA);
}
InputReplyS UInputSchemaStack::Selector2(InputActionS InIA)
{
	return Process(&UInputSchema::Selector2, InIA);
}

InputReplyS UInputSchemaStack::Selector3(InputActionS InIA)
{
	return Process(&UInputSchema::Selector3, InIA);
}

InputReplyS UInputSchemaStack::Interact(InputActionS InIA)
{
	return Process(&UInputSchema::Interact, InIA);
}
InputReplyS UInputSchemaStack::Jump(InputActionS InIA)
{
	return Process(&UInputSchema::Jump, InIA);
}

InputReplyS UInputSchemaStack::Console(InputActionS InIA)
{
	return Process(&UInputSchema::Console, InIA);
}
InputReplyS UInputSchemaStack::PrintScreen(InputActionS InIA)
{
	return Process(&UInputSchema::PrintScreen, InIA);
}

InputReplyS UInputSchemaStack::Escape(InputActionS InIA)
{
	return Process(&UInputSchema::Escape, InIA);
}