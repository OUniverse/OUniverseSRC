//Copyright 2015-2019, All Rights Reserved.


#pragma once

class OUNIVERSE_API LeyS
{

public:

	static enum Type {
		None,
		Move,
		Event,
		
	};

	static enum Dir {
		Up,
		Down,
		Left,
		Right,
		Tab,
		Cancel,
		DIR_MAX,
	};

	LeyS();

	uint8_t Type_;
	int Var_;

};