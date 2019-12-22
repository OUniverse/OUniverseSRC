//Copyright 2015-2019, All Rights Reserved.

#include "Ui/Json/UiJson.h"

#include "Ui/Json/UiJsonEditor.h"

#include "Ui/UiButton.h"

#include "System/Scope.h"
#include "Components/VerticalBox.h"

#include "Interface/Json.h"

#include "Ui/UiEditableText.h"

void UUiJson::NativeConstruct()
{
    Super::NativeConstruct();
    vExpand->SetupButton(Reg::RDelete, this);
    vDelete->SetupButton(Reg::RDelete, this);
    vAdd->SetupButton(Reg::RAdd, this);
    vDuplicate->SetupButton(Reg::RDuplicate, this);

    vString->SetupButton(Reg::RString, this);
    vNum->SetupButton(Reg::RNum, this);
    vArray->SetupButton(Reg::RArray, this);
    vObject->SetupButton(Reg::RObject, this);

    vKey->SetText(Key.ToFText());

    int L = NestedEntries_.Len();

    for (int i = 0; i < L; i++)
    {
        vChildren->AddChild(NestedEntries_[i]);
    }
}

void UUiJson::NativeDestruct()
{
    Super::NativeDestruct();
}


UUiJson* UUiJson::Create(StringC InKey, JsonS* InJ, UUiJson* InParent)
{
    UUiJson* Neu = CreateWidget<UUiJson>(ScopeC::World(), InParent->Editor->JsonClass);
    Neu->Editor = InParent->Editor;

    Neu->Key = InKey;
    Neu->Parent_ = InParent;
    Neu->Jsonify(InJ);

    return Neu;
}

UUiJson* UUiJson::Create(StringC InKey, JsonS* InJ, UUiJsonEditor* InEditor)
{
    UUiJson* Neu = CreateWidget<UUiJson>(ScopeC::World(), InEditor->JsonClass);
    Neu->Editor = InEditor;

    Neu->Key = InKey;
    Neu->Parent_ = NULL;
    Neu->Root = true;
    Neu->Jsonify(InJ);

    return Neu;
}



void UUiJson::SwitchType(int InType)
{
    switch (InType) {
    case JType::String:
        //AsString();
        return;
    case JType::Integer:
        //AsInteger();
        return;
    case JType::Array:
        //AsArray();
        return;
    case JType::Object:
        //AsObject();
        return;
    }
}


void UUiJson::Jsonify(JsonS* InJ)
{
    switch (InJ->Type()) {
    case json::value_t::array:
        AsArray();
        break;
    case json::value_t::object:
        AsObject(InJ);
        break;
    case json::value_t::string:
        AsString();
        break;
    case json::value_t::number_integer:
        AsInteger();
        break;
    case json::value_t::number_float:
        AsInteger();
        break;
    }
}

void UUiJson::AsArray()
{


}

void UUiJson::AsObject(JsonS* InJ)
{
    ArrayC<StringC> Arr = InJ->GetKeys();

    int L = Arr.Len();

    for (int i = 0; i < L; i++)
    {
        JsonS JPTR = InJ->Key(Arr[i].ToChar());
        NestedEntries_.Add(Create(Arr[i],&JPTR,this));
    }

}

void UUiJson::AsString()
{

}

void UUiJson::AsInteger()
{

}