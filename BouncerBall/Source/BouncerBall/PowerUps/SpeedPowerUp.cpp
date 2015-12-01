// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "SpeedPowerUp.h"
#define SPEED_TIME 4.f
#define SPEED_SCALAR 1.5f
SpeedPowerUp::SpeedPowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner,"Speed")
{
}

SpeedPowerUp::~SpeedPowerUp()
{
}

void SpeedPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	Owner->SetTimer(SPEED_TIME);
	Owner->SetMoveScalar(SPEED_SCALAR);
}
void SpeedPowerUp::Over()
{
	if (Owner->GetMoveScale() == SPEED_SCALAR)
		Owner->SetMoveScalar(1.f);

}
