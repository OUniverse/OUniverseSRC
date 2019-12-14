//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "UObject/NoExportTypes.h"
#include "Interface/Array.h"
#include "System/InputData.h"

#include "Input.generated.h"

class UCharacterA;
class UUiEl;


class OUNIVERSE_API InputC
{
	
public:
	InputC() {};

	virtual bool InputCommand(KeyS InKey);
	virtual bool InputAxis(AxisS InAxis);
};

class OUNIVERSE_API InputStackC : public InputC
{

public:
	InputStackC();

	virtual ~InputStackC() {};
	void InputStackAdd(InputC* InInput);
	void InputStackRemove(InputC* InInput);

	bool InputStackBroadcastCommand(bool(InputC::* PTR)(KeyS), KeyS InKey);
	bool InputStackBroadcastAxis(bool(InputC::* PTR)(AxisS), AxisS InKey);

	virtual bool InputCommand(KeyS InKey);
	virtual bool InputAxis(AxisS InAxis);

	int Len_;

	ArrayC<InputC*> Stack_;

};

class OUNIVERSE_API InputUiC : public InputC
{

public:
	
	InputUiC() {};

	void SetInputHandler(UUiEl* InHandler);
	UUiEl* UiInputHandler_;

	virtual bool InputCommand(KeyS InKey);
	virtual bool InputAxis(AxisS InAxis);

};



UCLASS()
class OUNIVERSE_API UInputSchema : public UObject
{

	GENERATED_BODY()

public:
	
	virtual bool AxisLX(float AxisValue) { return false; };
	virtual bool AxisLY(float AxisValue) { return false; };
	virtual bool AxisRX(float AxisValue) { return false; };
	virtual bool AxisRY(float AxisValue) { return false; };


	virtual bool MouseL(bool Down) { return false; };
	virtual bool MouseR(bool Down) { return false; };
	virtual bool MouseM(bool Down) { return false; };
	virtual bool WheelUp(bool Down) { return false; };
	virtual bool WheelDown(bool Down) { return false; };

	virtual bool Up(bool Down) { return false; };
	virtual bool Down(bool Down) { return false; };
	virtual bool Left(bool Down) { return false; };
	virtual bool Right(bool Down) { return false; };

	virtual bool Selector0(bool Down) { return false; };
	virtual bool Selector1(bool Down) { return false; };
	virtual bool Selector2(bool Down) { return false; };
	virtual bool Selector3(bool Down) { return false; };

	virtual bool Interact(bool Down) { return false; };
	virtual bool Jump(bool Down) { return false; };

	virtual bool Console(bool Down) { return false; };
	virtual bool PrintScreen(bool Down) { return false; };

	virtual bool Escape(bool Down) { return false; };
};

UCLASS()
class OUNIVERSE_API UInputSchemaStack : public UInputSchema
{

	GENERATED_BODY()

public:


	static UInputSchemaStack* Create();

	void Init();

	void AddInputSchema(UInputSchema* InSchema);

	bool Process(bool(UInputSchema::* PTR)(bool), bool Down);

	bool ProcessAxis(bool(UInputSchema::* PTR)(float), float AxisValue);

	virtual bool AxisLX(float AxisValue) override;
	virtual bool AxisLY(float AxisValue) override;
	virtual bool AxisRX(float AxisValue) override;
	virtual bool AxisRY(float AxisValue) override;

	virtual bool MouseL(bool Down) override;
	virtual bool MouseR(bool Down) override;
	virtual bool MouseM(bool Down) override;
	virtual bool WheelUp(bool Down) override;
	virtual bool WheelDown(bool Down) override;

	virtual bool Up(bool Down) override;
	virtual bool Down(bool Down) override;
	virtual bool Left(bool Down) override;
	virtual bool Right(bool Down) override;

	virtual bool Selector0(bool Down) override;
	virtual bool Selector1(bool Down) override;
	virtual bool Selector2(bool Down) override;
	virtual bool Selector3(bool Down) override;

	virtual bool Interact(bool Down) override;
	virtual bool Jump(bool Down) override;

	virtual bool Console(bool Down) override;
	virtual bool PrintScreen(bool Down) override;

	virtual bool Escape(bool Down) override;

	

	int Len_;

	UPROPERTY()
	TArray<UInputSchema*> Stack_;
};

UCLASS()
class OUNIVERSE_API UInputSchemaCharacter : public UInputSchema
{

	GENERATED_BODY()

public:

	UCharacterA* Character_;

	void SetCharacter(UCharacterA* InChar);

	virtual bool AxisLX(float AxisValue) override;
	virtual bool AxisLY(float AxisValue) override;

	virtual bool AxisRX(float AxisValue) override;
	virtual bool AxisRY(float AxisValue) override;

	virtual bool Up(bool Down) override;
	virtual bool WheelUp(bool Down) override;
	virtual bool WheelDown(bool Down) override;
};