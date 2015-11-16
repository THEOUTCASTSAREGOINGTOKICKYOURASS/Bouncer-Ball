// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BigPlayerPowerUp.h"

#define BIG_TIME 4.f

BigPlayerPowerUp::BigPlayerPowerUp(ABouncerPlayer* PlayerOwner) :BouncerPowerUp(PlayerOwner)
{
}

BigPlayerPowerUp::~BigPlayerPowerUp()
{
}

void BigPlayerPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	Owner->SetTimer(BIG_TIME);
	Owner->Grow();
}
void BigPlayerPowerUp::Over()
{
	Owner->Shrink();
}