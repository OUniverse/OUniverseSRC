//Copyright 2015-2019, All Rights Reserved.

#include "System/Fps.h"
#include "Min/DebugM.h"

namespace GlobalSingleton
{
	FpsC Fps;
}

FpsC* FpsC::Get()
{
	return &GlobalSingleton::Fps;
}

FpsC* FpsC::Create(TimeC* InTime)
{
	GlobalSingleton::Fps = *(new FpsC(InTime));
	return &GlobalSingleton::Fps;
}

EventLife FpsC::OnFrame(float DeltaTime)
{
	Recents_.Insert(0, DeltaTime);
	Recents_.Erase(10);

	if (UpdateGate.Overflowed(DeltaTime))
	{
		int l = 10;
		float Average = 0.0f;
		for (int i = 0; i < l; i++)
		{
			Average += Recents_[i];
		}

		//DBUG(IFS(int(10/Average)))
	}

	return EventLife(true);
}

FpsC::FpsC()
{

}

FpsC::FpsC(TimeC* InTime)
{
	UpdateGate = DeltaGateC(1.0);
	Recents_.Init(10,0.0);

	FrameGlobalH = *InTime->Frame_Global()->Bind(InTime->Frame_Global()->Create(this, &FpsC::OnFrame));	
}