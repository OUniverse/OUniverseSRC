//Copyright 2015-2019, All Rights Reserved.

#include "Component/Dolly.h"
#include "GameFramework/Actor.h"

UDolly::UDolly()
{
	Result_ = this;
}

UDolly* UDolly::AttachActor(AActor* AttachThis)
{
	AttachThis->AttachToComponent(Result_, FAttachmentTransformRules::KeepRelativeTransform);
	return Result_;
}

UDolly* UDolly::AttachComponent(USceneComponent* AttachThis)
{
	AttachThis->AttachToComponent(Result_, FAttachmentTransformRules::KeepRelativeTransform);
	return Result_;
}