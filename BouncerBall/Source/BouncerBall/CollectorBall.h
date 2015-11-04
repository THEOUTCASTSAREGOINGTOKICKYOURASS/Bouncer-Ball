// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "RegularBall.h"
#include "BouncerPickup.h"
#include "CollectorBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API ACollectorBall : public ARegularBall
{
	GENERATED_BODY()
	
public:
	ACollectorBall();

	UFUNCTION()
	void GetTarget();

	virtual void Tick(float DeltaSeconds) override;
	
protected:
	UPROPERTY()
	ABouncerPickup *CurrentPickupTarget;
};
