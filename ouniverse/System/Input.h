//Copyright 2015-2019, All Rights Reserved.

#pragma once

#include "Interface/Array.h"

class OUNIVERSE_API InputReplyS
{

public:

	InputReplyS();
	InputReplyS(bool InHandled);

	void Set(bool InHandled);
	bool Handled();
private:

	bool Handled_;
};

class OUNIVERSE_API InputC
{

public:

	enum Action
	{
		Forward,
		Back,
		Left,
		Right,
		Console,
		Interact,
		Member1,
		Member2,
		Member3,
		Member4,
		Member5,
	};
};

class InputActionS
{


public:

	InputActionS();

	InputActionS(bool InPress, bool InCTR, bool InALT, bool InSHIFT, bool InHelp);

	void SetAction(InputC::Action InAction);

private:

	InputC::Action Action_;

	bool Press_;
	bool ALT_;
	bool SHIFT_;
	bool CTR_;
	bool HELP_;

	void SetPress(bool InPress);
	void SetCTR(bool InPress);
	void SetALT(bool InPress);
	void SetSHIFT(bool InPress);
	void SetHELP(bool InPress);

	int Action();

	bool Pressed();

	bool CTR();

	bool ALT();

	bool Shift();

	bool Help();
};

class InputAxisS
{

};

class OUNIVERSE_API InputSchemaC
{

public:
	
	virtual ~InputSchemaC() {};

	virtual InputReplyS MouseL(InputActionS InIA) { return false; };
	virtual InputReplyS MouseR(InputActionS InIA) { return false; };
	virtual InputReplyS MouseM(InputActionS InIA) { return false; };


	virtual InputReplyS Forward(InputActionS InIA) { return false; };
	virtual InputReplyS Back(InputActionS InIA) { return false; };
	virtual InputReplyS Left(InputActionS InIA) { return false; };
	virtual InputReplyS Right(InputActionS InIA) { return false; };

	virtual InputReplyS Selector0(InputActionS InIA) { return false; };
	virtual InputReplyS Selector1(InputActionS InIA) { return false; };
	virtual InputReplyS Selector2(InputActionS InIA) { return false; };
	virtual InputReplyS Selector3(InputActionS InIA) { return false; };

	virtual InputReplyS Interact(InputActionS InIA) { return false; };
	virtual InputReplyS Jump(InputActionS InIA) { return false; };

	virtual InputReplyS Console(InputActionS InIA) { return false; };
	virtual InputReplyS PrintScreen(InputActionS InIA) { return false; };

	virtual InputReplyS Escape(InputActionS InIA) { return false; };
};

class OUNIVERSE_API InputSchemaStackC : public InputSchemaC
{

public:

	InputSchemaStackC();
	virtual ~InputSchemaStackC() {};

	void Add(InputSchemaC* InSchema);

	InputReplyS Process(InputReplyS(InputSchemaC::* PTR)(InputActionS), InputActionS InIA);

	virtual InputReplyS MouseL(InputActionS InIA) override;
	virtual InputReplyS MouseR(InputActionS InIA) override;
	virtual InputReplyS MouseM(InputActionS InIA) override;

	virtual InputReplyS Forward(InputActionS InIA) override;
	virtual InputReplyS Back(InputActionS InIA) override;
	virtual InputReplyS Left(InputActionS InIA) override;
	virtual InputReplyS Right(InputActionS InIA) override;

	virtual InputReplyS Selector0(InputActionS InIA) override;
	virtual InputReplyS Selector1(InputActionS InIA) override;
	virtual InputReplyS Selector2(InputActionS InIA) override;
	virtual InputReplyS Selector3(InputActionS InIA) override;

	virtual InputReplyS Interact(InputActionS InIA) override;
	virtual InputReplyS Jump(InputActionS InIA) override;

	virtual InputReplyS Console(InputActionS InIA) override;
	virtual InputReplyS PrintScreen(InputActionS InIA) override;

	virtual InputReplyS Escape(InputActionS InIA) override;


	int Len_;

	ArrayC<InputSchemaC*> Stack_;
};
