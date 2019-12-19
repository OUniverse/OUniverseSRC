//Copyright 2015-2019, All Rights Reserved.

#pragma once

class ProtocolREG
{

public:

	static enum Dock {
		DMaestro,
		DSystem,
		DUser,
		DWriter,
		D_MAX,
	};

	static enum Flux {
		FMaestro,
		FGlobal,
		FConsole,
		FSystem,
		FWriter,
		FSymPre,
		FSymTokens,
		FSymUserMenu,
		FSymUserSelect,
		FSymUserCreate,
		FSymUserEdit,
		F_MAX,
	};
};