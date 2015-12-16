// Fill out your copyright notice in the Description page of Project Settings.

#pragma once
#include "BouncerPickup.h"
#include "SmallPlayersPickup.generated.h"
/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ASmallPlayersPickup:public ABouncerPickup
{
	GENERATED_BODY()
public:

	ASmallPlayersPickup();
	UFUNCTION()
		virtual void OnBeginOverlap(AActor* OtherActor);
};
