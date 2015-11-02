// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "RegularBall.h"

ARegularBall::ARegularBall()
{
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
		TEXT("MovementComponent"));
	
}
void ARegularBall::Shoot(FVector Direction)

{	
	//set the direction of the ball to the players forward vector
	
	MovementComponent->Velocity = Direction;
	
}

