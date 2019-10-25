//Copyright 2015-2019, All Rights Reserved.

#include "Io/CharacterIO.h"

#include "Form/Character3D.h"

UIoCharacter* UIoCharacter::Create(ACharacter3D* InCharacter)
{
	UIoCharacter* Obj = NewObject<UIoCharacter>();
	Obj->Init(InCharacter);
	return Obj;
}

void UIoCharacter::Init(ACharacter3D* InCharacter)
{

}

InputReplyS UIoCharacter::Forward(InputActionS InIA)
{
	return ActionForward_Internal();
}

bool UIoCharacter::ActionForward_Internal()
{
	bool bHandled = false;
	ActionForward(bHandled);
	return bHandled;
}

void UIoCharacter::ActionForward_Implementation(bool& Result)
{
	
}