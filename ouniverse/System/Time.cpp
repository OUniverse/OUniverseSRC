//Copyright 2015-2019, All Rights Reserved.

#include "System/Time.h"

#include "Min/DebugM.h"

namespace GlobalSingleton
{
	TimeC Time;
}

TimeC* TimeC::Get()
{
	return &GlobalSingleton::Time;
}

TimeC* TimeC::Create()
{
	GlobalSingleton::Time = *(new TimeC());
	return &GlobalSingleton::Time;
}

TimeC::TimeC()
{

}

void TimeC::OnFrame(float DeltaTime)
{

}