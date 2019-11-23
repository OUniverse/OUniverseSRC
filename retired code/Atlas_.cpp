//Copyright 2015-2019, All Rights Reserved.

#include "System/Atlas_.h"
#include "System/Atlas.h"
#include "Interface/Url.h"
#include "ImageUtils.h"

UAtlas* UAtlas::Create(AtlasC* InAtlas)
{
	UAtlas* Neu = NewObject<UAtlas>();
	Neu->Init(InAtlas);
	return Neu;
}

void UAtlas::Init(AtlasC* InAtlas)
{
	Atlas_ = InAtlas;
}

FString UAtlas::GetName()
{
	return Atlas_->ID().ToFString();
}

FString UAtlas::GetID()
{
	return Atlas_->ID().ToFString();
}

int UAtlas::GetUID()
{
	return Atlas_->UID().ForUI();
}


FString UAtlas::GetDescription()
{
	return Atlas_->Desc().ToFString();
}


FString UAtlas::GetAuthor()
{
	return Atlas_->Author().ToFString();
}


FString UAtlas::GetWebsite()
{
	return Atlas_->Website().ToFString();
}

FString UAtlas::GetDate()
{
	return Atlas_->Date().ToFString();
}


FString UAtlas::GetVerVis()
{
	return Atlas_->VerVis().ToFString();
}

int UAtlas::GetVerInc()
{
	return Atlas_->VerInc();
}


int UAtlas::GetVerUpdate()
{
	return Atlas_->VerUpdate();
}

FString UAtlas::GetWebSocket()
{
	return Atlas_->WebSocket().ToFString();
}

UTexture2D* UAtlas::GetGFXLarge()
{
	return Atlas_->GFXLargeLoad();
}

UTexture2D* UAtlas::GetGFXSmall()
{
	return Atlas_->GFXSmall();
}
