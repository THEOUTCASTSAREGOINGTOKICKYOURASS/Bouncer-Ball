// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Ball.h"
#include "RegularBall.generated.h"

/**
 * This Ball has all of its functionality from the Projectile Movement Component
 * I set in the Blueprint of this Object to have no gravity lock orientation in the Z axis, bounce and not loose velocity
 */
UCLASS()
class BOUNCERBALL_API ARegularBall : public ABall
{
	GENERATED_BODY()
public:

	ARegularBall();
	//What happens when the player shoots the ball
	UFUNCTION()
	void Shoot(FVector Direction);
protected:
	//Used to make the Ball move in blueprint
	UPROPERTY(VisibleAnywhere)
	UProjectileMovementComponent* MovementComponent;
	
};
