//Copyright 2015-2019, All Rights Reserved.

#include "System/Maestro.h"
#include "Protocol/SplashP.h"
#include "Protocol/SystemP.h"
#include "Protocol/ScribeP.h"
#include "Protocol/OpenWorldP.h"
#include "System/Major.h"

#include "System/OniManager.h"
#include "System/OniType.h"
#include "System/OniKey.h"

#include "Min/DebugM.h"


MaestroC* MaestroC::Create(MajorC* Major)
{
	return new MaestroC(Major);
}


MaestroC::MaestroC(MajorC* Major)
{

	Oni_ = Major->Oni();

	Map_.Init(Types::MAX, NULL); 
	Map_[Types::Splash] = new SplashP(this, Major->Input());
	Map_[Types::System] = new SystemP(this,Major->UserL(),Major->Oni());
	Map_[Types::Scribe] = new ScribeP(Major->Data());
	Map_[Types::OpenWorld] = new OpenWorldP();
	
}

ProtocolP* MaestroC::GetProtocol(Types Type)
{
	return Map_[Type];
}

ProtocolP* MaestroC::Activate(Types Type)
{
	ProtocolP* ActivatedProtocol = GetProtocol(Type);
	ActivatedProtocol->Activate();
	return ActivatedProtocol;
}


void MaestroC::Start()
{
	bool SkipSplash = Oni_->GetBool(OniTypeC::Type::Global, OniGlobalC::SKIP_SPLASH_MOVIES);

	if (SkipSplash)
	{
		Map_[Types::System]->Activate();
	}
	else
	{
		Map_[Types::Splash]->Activate();
	}

}




void MaestroC::SplashEnd()
{
	Map_[Types::System]->Activate();
}