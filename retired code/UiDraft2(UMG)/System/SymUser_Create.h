//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Ui/UiView.h"
#include "SymUser_Create.generated.h"

class UserLibC;
class UEditableText;

UCLASS(Abstract,Blueprintable)
class OUNIVERSE_API USYM_UserCreate : public UUiView
{

	GENERATED_BODY()


public:

	void NativeDestruct() override;

	void Init(UUiView* InParentView, UserLibC* InUserLib);
	
	UserLibC* UserLib_;

	UPROPERTY(meta = (BindWidget))
	UEditableText* V_TextInput;
	
	UFUNCTION(BlueprintCallable)
	void CmdAccept();
	
	UFUNCTION()
	void TextChanged(const FText& Text);

	UFUNCTION()
	void OnTextCommitted(const FText& Text, ETextCommit::Type CommitMethod);

};