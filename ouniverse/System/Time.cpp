//Copyright 2015-2019, All Rights Reserved.

#include "System/Time.h"

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
	Frame_Global_ = new Event1C<EventLife, float>;
	Frame_Pausable_ = new Event1C<EventLife, float>;
	Ms100_Global_ = new Event1C<EventLife, float>;
	Ms100_Pausable_ = new Event1C<EventLife, float>;
	Ms1000_Global_ = new Event1C<EventLife, float>;
	Ms1000_Pausable_ = new Event1C<EventLife, float>;

	Pause_ = false;
}

FrameGlobalE TimeC::Frame_Global()
{
	return Frame_Global_;
}

FramePausableE TimeC::Frame_Pausable()
{
	return Frame_Pausable_;
}

FrameGlobalE TimeC::Ms100_Global()
{
	return Ms100_Global_;
}

FramePausableE TimeC::Ms100_Pausable()
{
	return Ms100_Pausable_;
}

FrameGlobalE TimeC::Ms1000_Global()
{
	return Ms1000_Global_;
}

FramePausableE TimeC::Ms1000_Pausable()
{
	return Ms1000_Pausable_;
}

void TimeC::Pause(bool InPause)
{
	Pause_ = InPause;
}

void TimeC::OnFrame(float DeltaTime)
{
	Frame_Global_->Trigger(DeltaTime);
	if (Pause_)
	{
	Frame_Pausable_->Trigger(DeltaTime);
	}
}

void TimeC::OnMs100(float DeltaTime)
{
	Ms100_Global_->Trigger(DeltaTime);
	if (Pause_)
	{
		Ms100_Pausable_->Trigger(DeltaTime);
	}
}

void TimeC::OnMs1000(float DeltaTime)
{
	Ms1000_Global_->Trigger(DeltaTime);
	if (Pause_)
	{
		Ms1000_Pausable_->Trigger(DeltaTime);
	}
}