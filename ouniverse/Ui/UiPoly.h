//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "Interface/Poly.h"
#include "UiPoly.generated.h"

class UTextBlock;
class UVerticalBox;
class UEditableText;


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPolyViewer : public UUiFocus
{

	GENERATED_BODY()

public:

	

	UPROPERTY(EditAnywhere, meta = (Category = "PolyClass"))
	TSubclassOf<UUiPolyObject> ObjectClass;

	UPROPERTY(EditAnywhere, meta = (Category = "PolyClass"))
	TSubclassOf<UUiPolyArray> ArrayClass;

	UPROPERTY(EditAnywhere, meta = (Category = "PolyClass"))
	TSubclassOf<UUiPolyString> StringClass;

	UPROPERTY(EditAnywhere, meta = (Category = "PolyClass"))
	TSubclassOf<UUiPolyInt> IntClass;

	UPROPERTY(EditAnywhere, meta = (Category = "PolyClass"))
	TSubclassOf<UUiPolyFloat> FloatClass;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vBox;

	void View(PolyC* InPoly);

	PolyC* PolyRoot;

	UUiPoly* Create(PolyC* InPoly);
};


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPoly : public UUiFocus
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	UUiPolyViewer* Viewer_;
	UUiPoly* Parent_;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* vKey;


};


UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPolyObject : public UUiPoly
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	static UUiPolyObject* Create(PolyC* InPoly, UUiPolyViewer* InViewer);

	PolyObjectC* Poly_;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vSub;	
};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPolyArray : public UUiPoly
{

	GENERATED_BODY()

public:
	
	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	static UUiPolyArray* Create(PolyC* InPoly, UUiPolyViewer* InViewer);

	PolyArrayC* Poly_;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vSub;

};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPolyString : public UUiPoly
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;


	static UUiPolyString* Create(PolyC* InPoly, UUiPolyViewer* InViewer);

	PolyStringC* Poly_;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vVal;

};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPolyInt : public UUiPoly
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	static UUiPolyInt* Create(PolyC* InPoly, UUiPolyViewer* InViewer);

	PolyIntC* Poly_;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vVal;	

};

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiPolyFloat : public UUiPoly
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	PolyFloatC* Poly_;

	UPROPERTY(meta = (BindWidget))
	UEditableText* vVal;

};