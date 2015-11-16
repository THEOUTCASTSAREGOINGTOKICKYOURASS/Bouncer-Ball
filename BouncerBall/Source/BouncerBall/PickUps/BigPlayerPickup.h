// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BouncerPickup.h"
#include "BigPlayerPickup.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ABigPlayerPickup : public ABouncerPickup
{
	GENERATED_BODY()
public:
	ABigPlayerPickup();
	UFUNCTION()
	virtual void OnBeginOverlap(AActor* OtherActor);
	
	
};
