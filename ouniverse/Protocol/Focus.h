//Copyright 2015-2019, All Rights Reserved.


#pragma once

#include "Protocol/Ley.h"
#include "Interface/Array.h"
#include "System/InputData.h"

class UUiFocus;
class ProtocolC;
class FluxDockC;

struct FocusUiRackDataS
{

public:

	FocusUiRackDataS() {};

	FocusUiRackDataS(UUiFocus* InFocus, int InID)
	{
		Focus_ = InFocus;
		ID_ = InID;
	}

	UUiFocus* Focus_;
	int ID_;
};

class OUNIVERSE_API FocusC
{

public:

	FocusC(int InID, ProtocolC* InProtocol);
	virtual ~FocusC() {};

	int ID_;
	ProtocolC* Protocol_;

	int ID();

	ArrayC<LeyS> Paths_;

	void SetPath(LeyS::Dir InDir, LeyS::Type InType, int InVar);
	virtual void Call(int InDir);

	virtual void Focus() {};
	virtual void Unfocus() {};

	virtual bool InputCommand(KeyS InKey) { return false; };

};

class OUNIVERSE_API FocusDockC : public FocusC
{

public:

	FocusDockC(int InID, ProtocolC* InProtocol);

	void Set(FluxDockC* InDock);

	FluxDockC* Dock_;


	void Focus() override {};
	void Unfocus() override {};

	bool InputCommand(KeyS InKey) override;
};

class OUNIVERSE_API FocusUiC : public FocusC
{

public:

	FocusUiC(int InID, ProtocolC* InProtocol);


	void Set(UUiFocus* InFocus);

	UUiFocus* Focus_;


	void Focus() override {};
	void Unfocus() override {};

	bool InputCommand(KeyS InKey) override;

};

class OUNIVERSE_API FocusUiRackC : public FocusUiC
{

public:

	FocusUiRackC(int InID, ProtocolC* InProtocol, bool InLoop, bool InHorizontal);

	bool bLoop;
	bool bHorizontal;

	int Index_;

	UUiFocus* ActiveFocus_;

	void Add(UUiFocus* InFocus, int ID);
	void Reset();
	ArrayC<FocusUiRackDataS> Focus_;

	void Focus() override;
	void Unfocus() override;

	void Call(int InDir) override;

	void ShiftUp();
	void ShiftDown();

	void Update();

	bool InputCommand(KeyS InKey) override;
};