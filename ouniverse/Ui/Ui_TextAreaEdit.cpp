//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Ui_TextAreaEdit.h"
#include "Components/MultiLineEditableText.h"


void UUi_TextAreaEdit::Required(UMultiLineEditableText* TextBox)
{
	Text_ = TextBox;
}

void UUi_TextAreaEdit::SetText(StringC InText)
{
	Text_->SetText(InText.ToFText());
}


StringC UUi_TextAreaEdit::GetText()
{
	return StringC(Text_->GetText().ToString());
}

void UUi_TextAreaEdit::KeyboardFocus()
{
	Text_->SetKeyboardFocus();
}