//Copyright 2015-2019, All Rights Reserved.

#include "System/Glass.h"




namespace GlassGlobals
{
	GlassC Glass;
}

GlassC::GlassC()
{

}

GlassC* GlassC::Get()
{
	return &GlassGlobals::Glass;
}

GlassC* GlassC::Create()
{
	GlassGlobals::Glass = *(new GlassC());
	return &GlassGlobals::Glass;
}

TSharedPtr<class SCohtmlInputForward> GlassC::Native()
{
	return NativeInput_;
}

coview GlassC::View()
{
	return Ui_->GetView();
}


