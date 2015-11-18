// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BouncerPickup.h"
#include "SlowPickup.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ASlowPickup : public ABouncerPickup
{
	GENERATED_BODY()
public:
	ASlowPickup();
	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor);
	
	
};
