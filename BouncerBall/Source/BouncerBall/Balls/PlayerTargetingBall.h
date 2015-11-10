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
protected:
	//Call to have the ball find a new target
	UFUNCTION()
	void GetTarget();
	//A reference to the current target of the ball
	UPROPERTY()
	ABouncerPlayer *CurrentTarget;
	
	
};
