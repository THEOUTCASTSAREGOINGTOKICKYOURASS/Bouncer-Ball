// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "StealPowerUp.h"

StealPowerUp::StealPowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner)
{
}

StealPowerUp::~StealPowerUp()
{
}

void StealPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
}
void StealPowerUp::Over()
{

}