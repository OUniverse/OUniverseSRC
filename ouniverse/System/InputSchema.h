//Copyright 2015-2019, All Rights Reserved.

#pragma once



class OUNIVERSE_API InputReplyS
{

public:

	InputReplyS(bool Bubble, bool BubbleUI)
	{
		Bubble_ = Bubble;
		BubbleUi_ = BubbleUI;
	}

	void SetBubble(bool InBubble)
	{
		Bubble_ = InBubble;
	}

	void SetBubbleUi(bool InBubbleUi)
	{
		BubbleUi_ = InBubbleUi;
	}

	bool Bubble()
	{
		return Bubble_;
	}

	bool Bubble_;
	bool BubbleUi_;
};

class OUNIVERSE_API InputSchemaC
{

public:

	enum Command
	{
		Console,
		Posses1,
		Posses2,
		Posses3,
		Posses4,
		Posses5,
		Posses6,
	};

};

class InputStrokeS
{
	bool SetPressed();

	bool SetALT();

	bool SetCTR();

	bool SetSHIFT();

	bool SetCMD(InputSchemaC::Command Command);
};

class InputAxisS
{

};