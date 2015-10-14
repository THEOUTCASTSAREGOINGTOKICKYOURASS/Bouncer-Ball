// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "RegularBall.h"

ARegularBall::ARegularBall()
{
	MovementComponent = CreateDefaultSubobject<UProjectileMovementComponent>(
		TEXT("MovementComponent"));
	
}
