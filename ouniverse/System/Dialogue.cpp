//Copyright 2015-2019, All Rights Reserved.

#include "System/Dialogue.h"


UDialogue* UDialogue::Create(bool PActors, bool TActors)
{
	UDialogue* Neu = NewObject<UDialogue>();
	Neu->Init();
	return Neu;
}

void UDialogue::Init()
{

}