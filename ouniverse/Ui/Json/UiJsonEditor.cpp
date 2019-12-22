//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Json/UiJsonEditor.h"
#include "Ui/Json/UiJson.h"
#include "Interface/String.h"

#include "Components/VerticalBox.h"

void UUiJsonEditor::NativeConstruct()
{
	Super::NativeConstruct();
}

void UUiJsonEditor::NativeDestruct()
{
	Super::NativeDestruct();
}

void UUiJsonEditor::FreshStart()
{

}

void UUiJsonEditor::JsonStart(JsonS* InJson)
{
	Base_ = UUiJson::Create("", InJson, this);
	vBox->AddChild(Base_);
}