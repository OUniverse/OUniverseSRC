//Copyright 2015-2019, All Rights Reserved.

#pragma once

struct UiPathS
{
	UiPathS();

	void Define(int InPathType, int InVar);
	
	int Type();
	int Var();

private:

	int Type_;
	int Var_;

public:

	static enum Types {
		Cancel,
		Move,
		BackView,
		ForwardView,
	};

	static enum Direction {
		Up,
		Down,
		Left,
		Right,
	};

	static enum Source {

	};
};

struct PathUpS : public UiPathS
{

};