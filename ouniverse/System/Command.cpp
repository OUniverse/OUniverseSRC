//Copyright 2015-2019, All Rights Reserved.

#include "Command.h"

#include "Min/DebugM.h"

CommandC::CommandC(KeyCodeC InKeyCode)
{
	KeyCode_ = InKeyCode;
	Event_ = new Event1C<void, StrokeS>;
}

void CommandC::SetKeyCode(KeyCodeC InKeyCode)
{
	KeyCode_ = InKeyCode;
}

KeyCodeC CommandC::KeyCode()
{
	return KeyCode_;
}

void CommandC::Trigger(StrokeS InStroke)
{
	//GEngine->AddOnScreenDebugMessage(-1, 15.0f, FColor::Yellow, ID.ToString());

	Event_->Trigger(InStroke);
}

CommandE CommandC::Listen()
{
	return Event_;
}