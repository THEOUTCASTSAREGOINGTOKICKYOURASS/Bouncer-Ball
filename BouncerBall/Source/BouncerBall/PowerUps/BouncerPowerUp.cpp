// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "BouncerPowerUp.h"

BouncerPowerUp::BouncerPowerUp(ABouncerPlayer* PlayerOwner, FString Name) :Owner(PlayerOwner), Name(Name), bIsUsed(false)
{
}

BouncerPowerUp::~BouncerPowerUp()
{
}

void BouncerPowerUp::Use(UWorld* WorldRef)
{
	bIsUsed = true;
}