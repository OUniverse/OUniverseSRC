//Copyright 2015-2019, All Rights Reserved.

#include "Io/MovementIO.h"

#include "Form/Character3D.h"

UIoMovement* UIoMovement::Create(A3dCharacter* InCharacter)
{
	UIoMovement* Obj = NewObject<UIoMovement>();
	Obj->Init(InCharacter);
	return Obj;
}

void UIoMovement::Init(A3dCharacter* InCharacter)
{

}

InputReplyS UIoMovement::Forward(InputActionS InIA)
{
	return ActionForward_Internal();
}

bool UIoMovement::ActionForward_Internal()
{
	bool bHandled = false;
	ActionForward(bHandled);
	return bHandled;
}

void UIoMovement::ActionForward_Implementation(bool& Result)
{
	
}