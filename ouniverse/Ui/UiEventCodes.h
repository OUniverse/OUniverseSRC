//Copyright 2015-2019, All Rights Reserved.

/**
Base widget which manages the entire UI.
 */


#pragma once

class OUNIVERSE_API UiEventsC
{

public:

	static enum Code {
		MouseLeftUp,
		MouseLeftDown,
		MouseLeftClick,
		MouseEnter,
		MouseExit,
		ButtonAccept,
	};
};

class OUNIVERSE_API UiEventCodesC
{


public:

	static constexpr int const& MouseClick = 297800587;
	static constexpr int const& MousePreciseClick = 708819286;
	static constexpr int const& MouseLeftDown = 15508344;
	static constexpr int const& MouseLeftUp = 55533143;
	static constexpr int const& MouseRightDown = 120101436;
	static constexpr int const& MouseRightUp = 971848316;

	static constexpr int const& ButtonHover		= 1514520188;
	static constexpr int const& ButtonUnhover	= 1652750847;
	static constexpr int const& ButtonClick		= 654780677;
	static constexpr int const& ButtonMouseDown = 1879732332;
	static constexpr int const& ButtonMouseUp	= 1955406664;
};