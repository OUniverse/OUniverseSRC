//Copyright 2015-2019, All Rights Reserved.

#include "System/Delegate.h"


DelegateS::DelegateS()
{
	
}


//void* object, Method method
void DelegateS::Execute()
{
	if (d)
	{
		d();
	}
}