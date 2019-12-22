//Copyright 2015-2019, All Rights Reserved.

#include "Ui/UiPoly.h"
#include "System/Scope.h"

#include "Components/TextBlock.h"
#include "Components/EditableText.h"
#include "Components/VerticalBox.h"


UUiPoly* UUiPolyViewer::Create(PolyC* InPoly)
{
    int Type = InPoly->Type();

    switch (Type) {
    case PolyC::Object:
        return UUiPolyObject::Create(InPoly,this);
    case PolyC::Array:
        return UUiPolyArray::Create(InPoly, this);
    case PolyC::String:
        return UUiPolyString::Create(InPoly, this);
    case PolyC::Int:
        return UUiPolyInt::Create(InPoly, this);
    }

    return NULL;
}


void UUiPolyViewer::View(PolyC* InPoly)
{
    PolyRoot = InPoly;
    vBox->AddChild(Create(InPoly));
}

void UUiPoly::NativeConstruct()
{
    Super::NativeConstruct();
}

void UUiPoly::NativeDestruct()
{
    Super::NativeDestruct();
}


UUiPolyArray* UUiPolyArray::Create(PolyC* InPoly, UUiPolyViewer* InViewer)
{
    UUiPolyArray* Neu = CreateWidget<UUiPolyArray>(ScopeC::World(), InViewer->ArrayClass);
    Neu->Poly_ = static_cast<PolyArrayC*>(InPoly);
    Neu->Viewer_ = InViewer;
    return Neu;
}


void UUiPolyArray::NativeConstruct()
{
    Super::NativeConstruct();
}

void UUiPolyArray::NativeDestruct()
{
    Super::NativeDestruct();
}




UUiPolyObject* UUiPolyObject::Create(PolyC* InPoly, UUiPolyViewer* InViewer)
{
    UUiPolyObject* Neu = CreateWidget<UUiPolyObject>(ScopeC::World(), InViewer->ObjectClass);
    Neu->Poly_ = static_cast<PolyObjectC*>(InPoly);
    Neu->Viewer_ = InViewer;
    return Neu;
}


void UUiPolyObject::NativeConstruct()
{
    Super::NativeConstruct();

    int L = Poly_->Items.Len();

    vKey->SetText(Poly_->Key.ToFText());
    for (int i = 0; i < L; i++)
    {
        vSub->AddChild(Viewer_->Create(Poly_->Items[i]));
    }
}

void UUiPolyObject::NativeDestruct()
{
    Super::NativeDestruct();
}



UUiPolyString* UUiPolyString::Create(PolyC* InPoly, UUiPolyViewer* InViewer)
{
    UUiPolyString* Neu = CreateWidget<UUiPolyString>(ScopeC::World(), InViewer->StringClass);
    Neu->Poly_ = static_cast<PolyStringC*>(InPoly);
    Neu->Viewer_ = InViewer;
    return Neu;
}

void UUiPolyString::NativeConstruct()
{
    Super::NativeConstruct();
    vKey->SetText(Poly_->Key.ToFText());
    vVal->SetText(Poly_->Val_.ToFText());
}

void UUiPolyString::NativeDestruct()
{
    Super::NativeDestruct();
}



UUiPolyInt* UUiPolyInt::Create(PolyC* InPoly, UUiPolyViewer* InViewer)
{
    UUiPolyInt* Neu = CreateWidget<UUiPolyInt>(ScopeC::World(), InViewer->IntClass);
    Neu->Poly_ = static_cast<PolyIntC*>(InPoly);
    Neu->Viewer_ = InViewer;
    return Neu;
}

void UUiPolyInt::NativeConstruct()
{
    Super::NativeConstruct();
    vKey->SetText(Poly_->Key.ToFText());
    vVal->SetText(StringC(Poly_->Val_).ToFText());
}

void UUiPolyInt::NativeDestruct()
{
    Super::NativeDestruct();
}





void UUiPolyFloat::NativeConstruct()
{
    Super::NativeConstruct();
    vKey->SetText(Poly_->Key.ToFText());
}

void UUiPolyFloat::NativeDestruct()
{
    Super::NativeDestruct();
}