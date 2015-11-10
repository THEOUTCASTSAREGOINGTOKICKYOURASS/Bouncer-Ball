// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPickup.h"
#include "SpeedPickup.generated.h"
/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ASpeedPickup:public ABouncerPickup
{
	GENERATED_BODY()

public:
	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
	
};
