// Fill out your copyright notice in the Description page of Project Settings.

#include "BouncerBall.h"
#include "StunPowerUp.h"

#define STUN_LENGTH 2.f
StunPowerUp::StunPowerUp(ABouncerPlayer* PlayerOwner) :BouncerPowerUp(PlayerOwner,"Stun")
{
}

StunPowerUp::~StunPowerUp()
{
}

void StunPowerUp::Use(UWorld* WorldRef)
{
	BouncerPowerUp::Use(WorldRef);
	this->WorldRef = WorldRef;
	Owner->SetTimer(STUN_LENGTH);
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner)
		{
			if (!ActorItr->IsInvinsible())
			{
				ActorItr->GotStunned();
				ActorItr->SetStunned(true);
			}
				
		}
	}
}
void StunPowerUp::Over()
{
	for (TActorIterator<ABouncerPlayer> ActorItr(WorldRef); ActorItr; ++ActorItr)
	{
		if (*ActorItr != Owner)
		{
			ActorItr->StunIsOver();
			if (ActorItr->GetStunnedCounter() <= 0)
				ActorItr->SetStunned(false);
		}
	}
}
