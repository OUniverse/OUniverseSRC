//Copyright 2015-2019, All Rights Reserved.

#include "Protocol/GlobalPro.h"
#include "System/InputID.h"

#include "System/Major.h"
#include "System/Maestro.h"

#include "Protocol/Console/CnsPro.h"

#include "Min/DebugM.h"

GlobalPro* GlobalPro::Create(int InID, UMajor* InMajor)
{
	GlobalPro* Neu = new GlobalPro(InID, InMajor);
	return Neu;
}

GlobalPro::GlobalPro(int InID, UMajor* InMajor) : ProtocolC(InID,this)
{
	Major_ = InMajor;
	Major_->Maestro()->InputStackAdd(this);

}



bool GlobalPro::InputCommand(KeyS InKey)
{ 
	switch (InKey.Command) {
	case InputID::Console_U:
		Major_->Maestro()->Console_->Toggle();
		return true;
	}

	return false; 
};