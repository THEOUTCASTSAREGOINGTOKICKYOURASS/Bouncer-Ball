// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "StealPowerUp.h"

StealPowerUp::StealPowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner,"Steal")
{
	StolenPowerUp = nullptr;
}

StealPowerUp::~StealPowerUp()
{
}

void StealPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	Owner->SetTimer(0.1f);
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if ((*ActorItr != Owner || !ActorItr->IsInvinsible()) && ActorItr->HasPowerUp())
		{
			StolenPowerUp = ActorItr->StealPowerUp();
			StolenPowerUp->NewOwner(Owner);
			return;
		}
	}
}
void StealPowerUp::Over()
{
	Owner->SetStolenPowerUp(StolenPowerUp);
}