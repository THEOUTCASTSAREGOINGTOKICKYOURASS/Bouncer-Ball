// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "PlayerTargetingBall.generated.h"

/**
 * 
 */
UCLASS()
class BOUNCERBALL_API APlayerTargetingBall : public ABall
{
	GENERATED_BODY()
public:
	APlayerTargetingBall();
	virtual void BeginPlay() override;
protected:
	//Call to have the ball find a new target
	UFUNCTION()
	void GetTarget();
	virtual void Tick(float DeltaSeconds) override;
	void RotateToTarget(float DeltaSeconds);
	//A reference to the current target of the ball
	UPROPERTY()
	ABouncerPlayer *CurrentTarget;
	
};
