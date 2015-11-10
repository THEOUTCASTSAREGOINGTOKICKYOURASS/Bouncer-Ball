// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "BouncerPickup.h"
#include "OwnAllPickup.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API AOwnAllPickup : public ABouncerPickup
{
	GENERATED_BODY()

		UFUNCTION()
		virtual void OnBeginOverlap(AActor *OtherActor);
	
	
	
};
