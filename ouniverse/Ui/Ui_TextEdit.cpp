//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_TextEdit.h"
#include "Components/EditableText.h"


void UUi_TextEdit::Required(UEditableText* TextBox)
{
	Text_ = TextBox;
}

void UUi_TextEdit::SetText(StringC InText)
{
	Text_->SetText(InText.ToFText());
}


StringC UUi_TextEdit::GetText()
{
	return StringC(Text_->GetText().ToString());
}

void UUi_TextEdit::KeyboardFocus()
{
	Text_->SetKeyboardFocus();
}