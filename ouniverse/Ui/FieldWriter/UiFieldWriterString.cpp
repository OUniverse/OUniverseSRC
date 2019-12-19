
//Copyright 2015-2019, All Rights Reserved.

#include "Ui/FieldWriter/UiFieldWriterString.h"
#include "Components/EditableText.h"

void UUiFieldWriterString::NativeConstruct()
{
	Super::NativeConstruct();

	V_Text->OnTextChanged.AddDynamic(this,&UUiFieldWriterString::OnTextChanged);
	V_Text->OnTextCommitted.AddDynamic(this, &UUiFieldWriterString::OnTextCommitted);
}

void UUiFieldWriterString::NativeDestruct()
{
	V_Text->OnTextChanged.RemoveDynamic(this, &UUiFieldWriterString::OnTextChanged);
	V_Text->OnTextCommitted.RemoveDynamic(this, &UUiFieldWriterString::OnTextCommitted);
	Super::NativeDestruct();
}

void UUiFieldWriterString::SetText(FText InText)
{
	V_Text->SetText(InText);
}

void UUiFieldWriterString::OnTextChanged(const FText& Text)
{

}

void UUiFieldWriterString::OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod)
{

}