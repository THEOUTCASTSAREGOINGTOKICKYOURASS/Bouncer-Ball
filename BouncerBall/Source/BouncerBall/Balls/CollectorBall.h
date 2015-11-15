// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "../PickUps/BouncerPickup.h"
#include "CollectorBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ACollectorBall : public ABall
{
	GENERATED_BODY()
	
public:
	ACollectorBall();

	UFUNCTION()
	bool GetTarget();

	virtual void Tick(float DeltaSeconds) override;
	
protected:
	UPROPERTY()
	ABouncerPickup *CurrentPickupTarget;
};
