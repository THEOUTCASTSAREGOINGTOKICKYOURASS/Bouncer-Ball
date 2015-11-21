// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "InvinsiblePowerUp.h"
#define TIME_INVULNERABLE 4.f
InvinsiblePowerUp::InvinsiblePowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner,"Invincible")
{
}

InvinsiblePowerUp::~InvinsiblePowerUp()
{
}

void InvinsiblePowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	Owner->SetInvinsible(true);
	Owner->SetTimer(TIME_INVULNERABLE);
}
void InvinsiblePowerUp::Over()
{
	Owner->SetInvinsible(false);
}