//Copyright 2015-2019, All Rights Reserved.

#pragma once


struct KeyS
{
	KeyS()
	{
		Command = -1;
		Source = -1;
	}

	KeyS(int InCommand, int InSource)
	{
		Command = InCommand;
		Source = InSource;
	}

	int Command;
	int Source;
};

struct AxisS
{
	AxisS()
	{
		Command = -1;
		Power = 0.0f;
		Source = -1;
	}

	AxisS(int InCommand, float InPower, int InSource)
	{
		Command = InCommand;
		Power = InPower;
		Source = InSource;
	}

	int Command;
	float Power;
	int Source;
};