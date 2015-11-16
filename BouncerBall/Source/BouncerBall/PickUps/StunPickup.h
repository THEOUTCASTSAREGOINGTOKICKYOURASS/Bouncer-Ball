// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BouncerPickup.h"
#include "StunPickup.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API AStunPickup : public ABouncerPickup
{
	GENERATED_BODY()
	
public:
	AStunPickup();
	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
	
	
};
