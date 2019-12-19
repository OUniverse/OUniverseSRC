//Copyright 2015-2019, All Rights Reserved.

#include "System/Input.h"
#include "Form/CharacterA.h"
#include "Component/CharacterInput.h"



bool InputC::InputCommand(KeyS InKey)
{ 
	return false; 
};

bool InputC::InputAxis(AxisS InAxis)
{ 
	return false; 
};






InputStackC::InputStackC()
{
	Len_ = 0;
};

bool InputStackC::InputCommand(KeyS InKey)
{ 
	return InputStackBroadcastCommand(&InputC::InputCommand, InKey);
};

bool InputStackC::InputAxis(AxisS InAxis)
{
	return InputStackBroadcastAxis(&InputC::InputAxis, InAxis);
};

void InputStackC::InputStackAdd(InputC* InSchema)
{
	Len_++;
	Stack_.Add(InSchema);
}

void InputStackC::InputStackRemove(InputC* InSchema)
{
	Len_--;
	Stack_.EraseElement(InSchema);
}


bool InputStackC::InputStackBroadcastCommand(bool(InputC::* PTR)(KeyS), KeyS InKey)
{
	for (int i = Len_ - 1; i > -1; i--)
	{
		bool Reply = (Stack_[i]->*PTR)(InKey);

		if (Reply)
		{
			return true;
		}
	}

	return false;
}

bool InputStackC::InputStackBroadcastAxis(bool(InputC::* PTR)(AxisS), AxisS InAxis)
{
	for (int i = Len_ - 1; i > -1; i--)
	{
		bool Reply = (Stack_[i]->*PTR)(InAxis);

		if (Reply)
		{
			return true;
		}
	}

	return false;
}












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

void UInputSchemaStack::AddInputSchema(UInputSchema* InSchema)
{
	Len_++;
	Stack_.Emplace(InSchema);
}

bool UInputSchemaStack::Process(bool(UInputSchema::* PTR)(bool), bool Down)
{
	for (int i = Len_-1; i > -1; i--)
	{
		bool Reply = (Stack_[i]->*PTR)(Down);
		
		if (Reply)
		{
			return true;
		}
	}

	return false;
}

bool UInputSchemaStack::ProcessAxis(bool(UInputSchema::* PTR)(float), float AxisValue)
{
	for (int i = Len_ - 1; i > -1; i--)
	{
		bool Reply = (Stack_[i]->*PTR)(AxisValue);

		if (Reply)
		{
			return true;
		}
	}

	return false;
}

bool UInputSchemaStack::MouseR(bool Down)
{
	return bool();
}

bool UInputSchemaStack::MouseL(bool Down)
{
	return Process(&UInputSchema::MouseL,Down);
}

bool UInputSchemaStack::MouseM(bool Down)
{
	return Process(&UInputSchema::MouseL, Down);
}

bool UInputSchemaStack::WheelUp(bool Down) { return Process(&UInputSchema::WheelUp, Down); }
bool UInputSchemaStack::WheelDown(bool Down) { return Process(&UInputSchema::WheelDown, Down); }

bool UInputSchemaStack::Up(bool Down){ return Process(&UInputSchema::Up, Down);}
bool UInputSchemaStack::Down(bool Down) { return Process(&UInputSchema::Down, Down);}
bool UInputSchemaStack::Left(bool Down) { return Process(&UInputSchema::Left, Down);}
bool UInputSchemaStack::Right(bool Down) {	return Process(&UInputSchema::Right, Down);}

bool UInputSchemaStack::Selector0(bool Down)
{
	return Process(&UInputSchema::Selector0, Down);
}
bool UInputSchemaStack::Selector1(bool Down)
{
	return Process(&UInputSchema::Selector1, Down);
}
bool UInputSchemaStack::Selector2(bool Down)
{
	return Process(&UInputSchema::Selector2, Down);
}

bool UInputSchemaStack::Selector3(bool Down)
{
	return Process(&UInputSchema::Selector3, Down);
}

bool UInputSchemaStack::Interact(bool Down)
{
	return Process(&UInputSchema::Interact, Down);
}
bool UInputSchemaStack::Jump(bool Down)
{
	return Process(&UInputSchema::Jump, Down);
}

bool UInputSchemaStack::Console(bool Down)
{
	return Process(&UInputSchema::Console, Down);
}
bool UInputSchemaStack::PrintScreen(bool Down)
{
	return Process(&UInputSchema::PrintScreen, Down);
}

bool UInputSchemaStack::Escape(bool Down)
{
	return Process(&UInputSchema::Escape, Down);
}

bool UInputSchemaStack::AxisLX(float AxisValue) { return ProcessAxis(&UInputSchema::AxisLX, AxisValue); }
bool UInputSchemaStack::AxisLY(float AxisValue) { return ProcessAxis(&UInputSchema::AxisLY, AxisValue); }
bool UInputSchemaStack::AxisRX(float AxisValue) { return ProcessAxis(&UInputSchema::AxisRX, AxisValue); }
bool UInputSchemaStack::AxisRY(float AxisValue) { return ProcessAxis(&UInputSchema::AxisRY, AxisValue); }





void UInputSchemaCharacter::SetCharacter(UCharacterA* InChar)
{
	Character_ = InChar;
}

bool UInputSchemaCharacter::AxisLX(float AxisValue) { return Character_->Input_->AxisLX(AxisValue); }
bool UInputSchemaCharacter::AxisLY(float AxisValue) { return Character_->Input_->AxisLY(AxisValue); }
bool UInputSchemaCharacter::AxisRX(float AxisValue) { return Character_->Input_->AxisRX(AxisValue); }
bool UInputSchemaCharacter::AxisRY(float AxisValue) { return Character_->Input_->AxisRY(AxisValue); }

bool UInputSchemaCharacter::Up(bool Down) { return false; }

bool UInputSchemaCharacter::WheelUp(bool Down) { return Character_->Input_->WheelUp(Down); }
bool UInputSchemaCharacter::WheelDown(bool Down) { return Character_->Input_->WheelDown(Down); }