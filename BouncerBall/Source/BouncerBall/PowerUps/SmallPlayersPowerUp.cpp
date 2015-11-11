// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "SmallPlayersPowerUp.h"

#define SMALL_LENGTH 4.f

SmallPlayersPowerUp::SmallPlayersPowerUp(ABouncerPlayer *PlayerOwner) :BouncerPowerUp(PlayerOwner)
{
}

SmallPlayersPowerUp::~SmallPlayersPowerUp()
{
}

void SmallPlayersPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	this->WorldRef = WorldRef;
	Owner->SetTimer(SMALL_LENGTH);
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner || !ActorItr->IsInvinsible() && ActorItr->GetSize() == 1)
		{
			ActorItr->Shrink();
			ActorItr->GotShrunk();
		}
	}
}
void SmallPlayersPowerUp::Over()
{
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner && ActorItr->GetSize() == 0)
		{
			ActorItr->ShrunkOver();
			if (ActorItr->GetShrunkCounter() == 0)
				ActorItr->Grow();
			
		}
	}
}
