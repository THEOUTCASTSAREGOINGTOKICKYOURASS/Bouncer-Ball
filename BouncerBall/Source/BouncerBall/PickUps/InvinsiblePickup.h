// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BouncerPickup.h"
#include "InvinsiblePickup.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API AInvinsiblePickup : public ABouncerPickup
{
	GENERATED_BODY()
	
	
public:
	AInvinsiblePickup();
	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
	
};
