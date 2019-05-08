//Copyright 2015-2019, All Rights Reserved.

#include "SystemTask.h"
#include "System/Major.h"
#include "System/Gate.h"
#include "System/PathManager.h"

UClass* USystemTask::GetSystemTaskClass(ESystemTasks SystemTask)
{

	switch (SystemTask) {
	case ESystemTasks::BigBang:
		return USYTASK_BigBang::StaticClass();
		break;
	}

	return NULL;
}



void USystemTask::Init(UMajor* InMajor)
{
	Major = InMajor;
	bGateOpen = false;
}

void USystemTask::Start()
{

}

void USystemTask::Thread()
{

}

void USystemTask::End()
{
	CallBack.ExecuteIfBound();
}










void USYTASK_BigBang::Start()
{


}

void USYTASK_BigBang::Thread()
{

}


bool USYTASK_BigBang::AreSingletonsReady()
{
	return true;
}


void USYTASK_BigBang::SingletonsReady()
{
	End();
}