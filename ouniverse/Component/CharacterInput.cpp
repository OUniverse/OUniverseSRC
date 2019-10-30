//Copyright 2015-2019, All Rights Reserved.

#include "Component/CharacterInput.h"
#include "Form/CharacterA.h"
#include "Min/DebugM.h"

UCharacterInput* UCharacterInput::Create(UCharacterA* InChar)
{
	UCharacterInput* Neu = NewObject <UCharacterInput>();
	Neu->Init(InChar);
	return Neu;
}

void UCharacterInput::Init(UCharacterA* InChar)
{
	Character_ = InChar;
}





bool UCharacterInput::AxisLX(float AxisValue)
{
	bool bHandled = false;
	OnAxisLX(AxisValue, bHandled);
	return bHandled;
}

void UCharacterInput::OnAxisLX_Implementation(float AxisValue, bool& Handled) 
{
	MoveX(AxisValue);
	Handled = true;
}

void UCharacterInput::MoveX(float AxisValue)
{
	Character_->MoveX(AxisValue);
}









bool UCharacterInput::AxisLY(float AxisValue)
{
	bool bHandled = false;
	OnAxisLY(AxisValue, bHandled);
	return bHandled;
}

void UCharacterInput::OnAxisLY_Implementation(float AxisValue, bool& Handled) 
{
	MoveY(AxisValue);
	Handled = true;
}

void UCharacterInput::MoveY(float AxisValue)
{
	Character_->MoveY(AxisValue);
}







bool UCharacterInput::AxisRX(float AxisValue)
{
	bool bHandled = false;
	OnAxisRX(AxisValue, bHandled);
	return bHandled;
}

void UCharacterInput::OnAxisRX_Implementation(float AxisValue, bool& Handled) 
{
	LookX(AxisValue);
	Handled = true;
}

void UCharacterInput::LookX(float AxisValue)
{
	Character_->LookX(AxisValue);
}





bool UCharacterInput::AxisRY(float AxisValue)
{
	bool bHandled = false;
	OnAxisRY(AxisValue, bHandled);
	return bHandled;
}

void UCharacterInput::OnAxisRY_Implementation(float AxisValue, bool& Handled) 
{
	TurnY(AxisValue);
	Handled = true;
}

void UCharacterInput::TurnY(float AxisValue)
{
	Character_->TurnY(AxisValue);
}



bool UCharacterInput::WheelUp(bool Down)
{

	bool bHandled = false;
	OnWheelUp(Down, bHandled);
	return bHandled;
}

void UCharacterInput::OnWheelUp_Implementation(bool Down, bool& Handled)
{
	Zoom(1.0);
	Handled = true;
}

void UCharacterInput::Zoom(float AxisValue)
{
	Character_->Zoom(AxisValue);
}




bool UCharacterInput::WheelDown(bool Down)
{

	bool bHandled = false;
	OnWheelDown(Down, bHandled);
	return bHandled;
}

void UCharacterInput::OnWheelDown_Implementation(bool Down, bool& Handled)
{
	Zoom(-1.0);
	Handled = true;
}