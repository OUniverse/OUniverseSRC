//Copyright 2015-2019, All Rights Reserved.

/**

## Scribe

**Struct:**  ScribeS

On write all documents are given a version number which is updated only if the read mechanism of the script were changed.
This allows OUniverse to adapt and update in realtime to outdated documents allowing for the engine to improve into the future while maintaining backwards compatability.

*/

#pragma once

#include "Interface/String.h"
#include "Interface/Array.h"
#include "Interface/Map.h"

class FormF;
class FactoryF;

struct StackF
{


public:

	StackF();
	StackF(FactoryF* InFactory, int Start, long long count, StringC InLine);

	void Bloom();

	bool Valid();

	
	struct WriterS
	{
		struct TempS
		{
			TempS();
			int UID;
			StringC Data;

			void Set(int InUID, StringC InData);
		};

		int Cursor;
		void Add(int UID, StringC Data);

		WriterS(int Length);
		ArrayC<TempS> TempList;
	};

private:

	WriterS* Writer_;
	MapC<int, FormF> Map_;

};