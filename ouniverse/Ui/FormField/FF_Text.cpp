//Copyright 2015-2019, All Rights Reserved.

#include "Ui/FormField/FF_Text.h"
#include "System/Class.h"
#include "System/Major.h"

UFF_Text* UFF_Text::Create(int InFFID, void* InVP, UFF_Text::Primitives InPrimitive)
{
	UFF_Text* Neu = CreateWidget<UFF_Text>(UMajor::Get()->Scope(), ClassC::FF_Text());
	Neu->Init(InFFID,InVP,InPrimitive);
	return Neu;
}

void UFF_Text::Init(int InFFID, void* InVP, UFF_Text::Primitives InPrimitive)
{
	SetFFID(InFFID);
	VP_ = InVP;
	Primitive_ = InPrimitive;

}