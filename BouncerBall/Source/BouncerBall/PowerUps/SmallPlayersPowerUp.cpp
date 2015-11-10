// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "SmallPlayersPowerUp.h"

SmallPlayersPowerUp::SmallPlayersPowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner)
{
}

SmallPlayersPowerUp::~SmallPlayersPowerUp()
{
}

void SmallPlayersPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
}
void SmallPlayersPowerUp::Over()
{

}
