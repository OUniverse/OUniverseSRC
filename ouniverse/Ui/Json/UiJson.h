//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiFocus.h"
#include "Interface/String.h"
#include "Interface/Array.h"
#include "UiJson.generated.h"


class UUiJsonEditor;
class UUiEditableText;
class UVerticalBox;
class UCanvasPanel;
struct JsonS;

UCLASS(Abstract, Blueprintable)
class OUNIVERSE_API UUiJson : public UUiFocus
{

	GENERATED_BODY()

public:

	virtual void NativeConstruct() override;
	virtual void NativeDestruct() override;

	static UUiJson* Create(StringC InKey, JsonS* InJ, UUiJson* InParent);
	static UUiJson* Create(StringC InKey, JsonS* InJ, UUiJsonEditor* InEditor);

	StringC Key;
	StringC Value;

	UUiJsonEditor* Editor;

	static enum JType {
		String,
		Integer,
		Array,
		Object,
	};

	
	ArrayC<UUiJson*> NestedEntries_;

	JType Type;

	UPROPERTY(meta = (BindWidget))
	UVerticalBox* vChildren;

	UPROPERTY(meta = (BindWidget))
	UUiEditableText* vKey;

	UPROPERTY(meta = (BindWidget))
	UUiEditableText* vValue;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vDelete;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vAdd;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vDuplicate;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vExpand;
	
	UPROPERTY(meta = (BindWidget))
	UUiButton* vString;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vNum;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vArray;

	UPROPERTY(meta = (BindWidget))
	UUiButton* vObject;



	static enum Reg {
		RExpand,
		RAdd,
		RDelete,
		RDuplicate,
		RString,
		RNum,
		RArray,
		RObject,
		
	};

	bool Root;

	void SwitchType(int InType);

	void AsObject(JsonS* InJ);
	void AsArray();
	void AsString();
	void AsInteger();

	void Jsonify(JsonS* InJ);

private:

	UUiJson* Parent_;

};